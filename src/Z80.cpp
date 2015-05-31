//====================================================================================
// Name        : Z80.h
// Author      : Jered Tupik
// Version     : 1.0	4/24/2015
// Copyright   : GNU v3 Public License
//
//				 Copyright (C) 2015  Tupik, Jered
//
//			     This program is free software: you can redistribute it and/or modify
//    			 it under the terms of the GNU General Public License as published by
//   			 the Free Software Foundation, either version 3 of the License, or
//    			 (at your option) any later version.
//
//    			 This program is distributed in the hope that it will be useful,
//    			 but WITHOUT ANY WARRANTY; without even the implied warranty of
//    			 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    			 GNU General Public License for more details.
//
//   			 You should have received a copy of the GNU General Public License
//    			 along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
// Description : CPP file of Z80.
//====================================================================================
#include "Z80.h"

//Constructor / Destructors
Z80::Z80(){
	initializeRegisters();
}

Z80::Z80(const char* FN){
	initializeRegisters();
	loadFile(FN, 0x0);
}

Z80::Z80(std::string FN){
	initializeRegisters();
	loadFile(FN, 0x0);
}

Z80::~Z80(){

}

//Initializes the Registers of the Z80 Microprocessors
void Z80::initializeRegisters(){
	for(int i = 0; i < 2; i++){
		AF[i] = 0x0;
		BC[i] = 0x0;
		DE[i] = 0x0;
		HL[i] = 0x0;
	}
	IX = 0x0;
	IY = 0x0;
	I = 0x0;
	R = 0x0;
	PC = 0x0;
	T = 0x0;
	M = 0x0;

	Memory = std::shared_ptr<uint8_t>(new uint8_t[MEMORY_SIZE], std::default_delete<uint8_t[]>());
	this->resetMemory();

	Stack = Z80Stack(0x100, Memory);
	//ALU = Z80ALU();

	IFF1 = false;
	IFF2 = false;
	CPUMode = M0;
}

/**
 * Stores the 8-bit number into the specified byte of the
 * given register;
 */
void Z80::storeRegister(uint16_t& Register, uint8_t NUM, uint8_t OLD_NUM, bool H_B){
	if(OLD_NUM != NUM){
		if(H_B){
			Register = (NUM << 8) | (Register & BYTE_MASK);
		}else{
			Register = (Register & (BYTE_MASK << 8)) | NUM;
		}
	}
}

/**
 * Retrieves the next byte from the Memory, and
 * increments PC.
 */
uint8_t Z80::getMemoryByte(){
	return Memory.get()[++PC];
}

/**
 * Retrieves the next word (2 bytes) from the Memory, and
 * increments PC accordingly.
 */
uint16_t Z80::getMemoryWord(){
	uint8_t L_B = getMemoryByte();
	uint16_t H_B = getMemoryByte() << 8;
	return H_B | L_B;
}

/**
 * Resets the Memory of the Z80 to 0.
 */
void Z80::resetMemory(){
	for(size_t i = 0; i < MEMORY_SIZE; i++){
		Memory.get()[i] = 0;
	}
}

/**
 * Returns a reference to the bus
 */
uint8_t& Z80::getBus(){
	return BUS[0];
}

/**
 * Writes the given byte to the specified port.
 */
void Z80::writeBus(uint8_t DATA, uint8_t PORT){
	BUS[PORT] = DATA;
}

/**
 * Resets the Bus of the Z80 to 0.
 */
void Z80::resetBus(){
	for(int i = 0; i < BUS_SIZE; i++){
		BUS[i] = 0;
	}
}
/**
 * Loads the file specified by FN to the external memory
 * of the Z80 Emulator.
 *
 * Parameters: FN - The designated file to load to memory
 *
 * Returns:    Flag consisting of any errors encountered
 *             while loading the file
 *
 * Errors:     INVALID_FILE - 1
 * 			   FILE_TO_BIG  - 2
 */
uint8_t Z80::loadFile(const std::string FN, uint16_t Offset){
	uint8_t Flags(0);
	size_t FileSize = 0;
	std::ifstream File(FN, std::ios::binary);
	if(File.bad()){
		Flags |= INVALID_FILE;
	}else{
		//while(!File.eof()){
			File.seekg(0, std::ios::end);
			FileSize = File.tellg();
			File.seekg(0, std::ios::beg);
			if(FileSize < MEMORY_SIZE){
				File.read((char* ) &Memory.get()[Offset], FileSize);
			}else{
				Flags |= FILE_TO_BIG;
			}
		//}
	}
	File.close();
	/*for(int i = 0; i < FileSize + Offset; i++){
		std::cout << "0x" << std::uppercase << std::hex << (int)Memory.get()[i] << " ";
		if((i + 1) % 20 == 0){
			std::cout << std::endl;
			std::cout << std::dec << (i + 1) << ":  ";
		}
	}*/
	//std::cout << std::endl;
	//std::cout << std::endl;
	Memory.get()[0] = 0xD3;
	Memory.get()[1] = 0x00;
	Memory.get()[5] = 0xDB;
	Memory.get()[6] = 0x00;
	Memory.get()[7] = 0xC9;
	/*for(int i = 0; i < FileSize + Offset; i++){
		std::cout << "0x" << std::uppercase << std::hex << (int)Memory.get()[i] << " ";
		if((i + 1) % 20 == 0){
			std::cout << std::endl;
			std::cout << std::dec << (i + 1) << ":  ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;*/
	return Flags;
}

/**
 * Resets the Z80 Emulator to its default state, as
 * specified by the Z80 CPU User's Manual.
 * (http://www.z80.info/zip/z80cpu_um.pdf)
 */
void Z80::resetZ80(){
	initializeRegisters();
	for(size_t i = 0; i < 2; i++){
		AF[i] = 0xFFFF;
		BC[i] = 0xFFFF;
		DE[i] = 0xFFFF;
		HL[i] = 0xFFFF;
	}
}

void Z80::setPC(uint16_t N_PC){
	PC = N_PC;
}

void Z80::runCycle(){
	if(!HALT){
		rI = false;
		mP = false;
		uint8_t OPCode = Memory.get()[PC];
		if(executeOPCode(OPCode) != 0){
			std::cout << "Error. Incorrect Operation(" << OPCode << ") at " << PC << std::endl;
		}
		if(!rI && !mP){
			PC += 1;
		}
	}
	/*uint16_t InterruptCode = InterruptPoller.processInterrupt();
	/* Implement T and M counting later. */
	/*if(InterruptCode != INTERRUPT_NONE){
		uint8_t InterruptType = InterruptCode >> 8;
		if((InterruptType == INTERRUPT_MASK && IFF1 == true) || InterruptType == INTERRUPT_NMSK){
			if(InterruptType == INTERRUPT_NMSK){
				IFF2 = IFF1;
				IFF1 = false;
				Stack.pushWord(PC + 1);
				PC = 0x66;
			}else if(InterruptType == INTERRUPT_MASK && IFF1 == true){
				switch(CPUMode){
					case M0:
						if(this->executeOPCode((InterruptCode & BYTE_MASK)) != 0){

						}
						break;
					case M1:
						Stack.pushWord(PC + 1);
						PC = 0x38;
						break;
					case M2:
						Stack.pushWord(PC + 1);
						PC = ((I << 8) | (InterruptCode & (BYTE_MASK - 1)));
						break;
					default:
						break;
				}
			}
			HALT = false;
		}
	}*/
}

/**
 * Executes the current OPcode received, and toggles/resets the
 * respective flags affected by the operation.
 *
 * Parameters:			OPCode - The first 8 bits of the operation
 * 								 to run.
 *
 * Errors:				INVALID_OPCODE - 4
 */
uint8_t Z80::executeOPCode(uint8_t OPCode){
	uint8_t ExitStatus(0);

	//Note: Think of a better ****ing way to do this later
	uint8_t A = (AF[M_REGISTER] >> 8), F = (AF[M_REGISTER] & BYTE_MASK);
	uint8_t B = (BC[M_REGISTER] >> 8), C = (BC[M_REGISTER] & BYTE_MASK);
	uint8_t D = (DE[M_REGISTER] >> 8), E = (DE[M_REGISTER] & BYTE_MASK);
	uint8_t H = (HL[M_REGISTER] >> 8), L = (HL[M_REGISTER] & BYTE_MASK);
	uint8_t IXH = (IX >> 8), IXL = (IX & BYTE_MASK);
	uint8_t IYH = (IY >> 8), IYL = (IY & BYTE_MASK);
	uint16_t SP = Stack.getStackPointer();

	uint8_t C_A = (AF[M_REGISTER] >> 8), C_F = (AF[M_REGISTER] & BYTE_MASK);
	uint8_t C_B = (BC[M_REGISTER] >> 8), C_C = (BC[M_REGISTER] & BYTE_MASK);
	uint8_t C_D = (DE[M_REGISTER] >> 8), C_E = (DE[M_REGISTER] & BYTE_MASK);
	uint8_t C_H = (HL[M_REGISTER] >> 8), C_L = (HL[M_REGISTER] & BYTE_MASK);
	uint8_t C_IXH = (IX >> 8), C_IXL = (IX & BYTE_MASK);
	uint8_t C_IYH = (IY >> 8), C_IYL = (IY & BYTE_MASK);

	switch(OPCode){
		case 0xCB:
			OPCode = Memory.get()[++PC];
			switch(OPCode){
				#include "Z80 Instruction Handler/BIT.h"		//Finished
			}
			break;
		case 0xDD:
			OPCode = Memory.get()[++PC];
			if(OPCode == 0xCB){
				uint8_t O = getMemoryByte();
				uint8_t C_R = Memory.get()[IX + O];
				OPCode = Memory.get()[++PC];
				switch(OPCode){
					#include "Z80 Instruction Handler/IX_BIT.h"
				}
			}else{
				switch(OPCode){
					#include "Z80 Instruction Handler/IX.h"
				}
			}
			break;
		case 0xED:
			OPCode = Memory.get()[PC + 1];
			switch(OPCode){
				#include "Z80 Instruction Handler/EXTENDED.h"	//Finished
			}
			if(!rI){
				PC += 1;
			}
			break;
		case 0xFD:
			OPCode = Memory.get()[++PC];
			if(OPCode == 0xCB){
				uint8_t O = getMemoryByte();
				uint8_t C_R = Memory.get()[IY + O];
				OPCode = Memory.get()[++PC];
				switch(OPCode){
					#include "Z80 Instruction Handler/IY_BIT.h"
				}
			}else{
				switch(OPCode){
					#include "Z80 Instruction Handler/IY.h"
				}
			}
			break;
		default:
			switch(OPCode){
				#include "Z80 Instruction Handler/MAIN.h"		//Finished
			}
			break;
	}
	storeRegister(AF[M_REGISTER], A, C_A, true);
	storeRegister(AF[M_REGISTER], F, C_F, false);
	storeRegister(BC[M_REGISTER], B, C_B, true);
	storeRegister(BC[M_REGISTER], C, C_C, false);
	storeRegister(DE[M_REGISTER], D, C_D, true);
	storeRegister(DE[M_REGISTER], E, C_E, false);
	storeRegister(HL[M_REGISTER], H, C_H, true);
	storeRegister(HL[M_REGISTER], L, C_L, false);
	storeRegister(IX, IXH, C_IXH, true);
	storeRegister(IX, IXL, C_IXL, false);
	storeRegister(IY, IYH, C_IYH, true);
	storeRegister(IY, IYL, C_IYL, false);
	//Stack.setStackPointer(SP);
	return ExitStatus;
}

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
	loadFile(FN);
}

Z80::Z80(std::string FN){
	initializeRegisters();
	loadFile(FN);
}

Z80::~Z80(){
	delete[] Memory;
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

	Memory = new uint8_t[MEMORY_SIZE];
	this->resetMemory();

	Stack = Z80Stack(0, Memory);

	IFF1 = false;
	IFF2 = false;
	CPUMode = M0;
}

/**
 * Resets the Memory of the Z80 to 0.
 */
void Z80::resetMemory(){
	for(size_t i = 0; i < MEMORY_SIZE; i++){
		Memory[i] = 0;
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
uint8_t Z80::loadFile(const std::string FN){
	uint8_t Flags(0);
	std::ifstream File(FN, std::ios::binary);
	if(File.bad()){
		Flags |= INVALID_FILE;
	}else{
		while(!File.eof()){
			File.seekg(0, std::ios::end);
			size_t FileSize = File.tellg();
			File.seekg(0, std::ios::beg);
			if(FileSize < MEMORY_SIZE){
				File.read(reinterpret_cast<char *>(Memory), FileSize);
			}else{
				Flags |= FILE_TO_BIG;
			}
		}
	}
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

void Z80::runCycle(){
	if(!HALT){
		if(this->executeOPCode(Memory[PC++]) != 0){

		}
	}
	uint16_t InterruptCode = InterruptPoller.processInterrupt();
	/* Implement T and M counting later. */
	if(InterruptCode != INTERRUPT_NONE){
		uint8_t InterruptType = InterruptCode >> 8;
		if((InterruptType == INTERRUPT_MASK && IFF1 == true) || InterruptType == INTERRUPT_NMSK){
			if(InterruptType == INTERRUPT_NMSK){
				IFF2 = IFF1;
				IFF1 = false;
				Stack.pushWord(PC);
				PC = 0x66;
			}else if(InterruptType == INTERRUPT_MASK && IFF1 == true){
				switch(CPUMode){
					case M0:
						if(this->executeOPCode((InterruptCode & 0xFF)) != 0){

						}
						break;
					case M1:
						Stack.pushWord(PC);
						PC = 0x38;
						break;
					case M2:
						Stack.pushWord(PC);
						PC = ((I << 8) | (InterruptCode & 0xFE));
						break;
					default:
						break;
				}
			}
			HALT = false;
		}
	}
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
uint8_t Z80::executeOPCode(const uint8_t OPCode){
	uint8_t Flags(0);
	switch(OPCode){
		default:
			Flags |= INVALID_OPCODE;
			break;
	}
	return Flags;
}

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
	InterruptMonitor = std::thread(&Z80::interruptHandler, this, 100);
}

Z80::Z80(const char* FN){
	initializeRegisters();
	InterruptMonitor = std::thread(&Z80::interruptHandler, this, 100);
	loadFile(FN);
}

Z80::Z80(std::string FN){
	initializeRegisters();
	InterruptMonitor = std::thread(&Z80::interruptHandler, this, 100);
	loadFile(FN);
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
	for(size_t i = 0; i < MEMORY_SIZE; i++){
		Memory[i] = 0;
	}
	IX = 0x0;
	IY = 0x0;
	SP = 0x0;
	I = 0x0;
	R = 0x0;
	PC = 0x0;
	T = 0x0;
	M = 0x0;

	interruptCode = 0;
	InterruptType = NONE;
	IFF1 = false;
	IFF2 = false;
	CPUMode = M0;
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

/**
 * Acts as a poll loop for the InterruptHandler thread.
 * This method constantly polls the various devices for
 * any interrupts generated, and records the information
 * of any interrupt received.
 */
void Z80::interruptHandler(uint16_t Delay){
	while(true){
		for(auto i = InterruptDevices.begin(); i != InterruptDevices.end(); i++){
			uint8_t ReturnCode = i->PollDevice();
			if(ReturnCode != 0){
				interruptCode = ReturnCode;
				if(i->isNonMaskable()){
					InterruptType = NMI;
				}else{
					InterruptType = MI;
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(Delay));
	}
}

/**
 * 'Pops' the current data from the top of the Stack,
 * and then decrements SP to the next piece of data.
 * The Stack follows a LIFO method.
 *
 * Returns:		The last piece of data pushed to the stack,
 * 				or the value of the memory before it if a
 * 				stack underflow occurs.
 */
uint8_t Z80::popStack(){
	return Memory[SP];
}

/**
 * 'Pushes' Value to the top of the current stack, or
 * throws an error if a memory stack overflow occurs.
 * Follows a LIFO methodology.
 *
 * Parameters:		Value - The value to push to the
 * 					stack
 *
 * Returns:			The exit status of the pushStack()
 * 					method
 *
 * Errors:			MEMORY_OVERFLOW - 3
 */
uint8_t Z80::pushStack(const uint8_t Value){
	uint8_t Flags(0);
	if(SP == 0){
		Flags |= MEMORY_OVERFLOW;
	}
	Memory[SP] = Value;
	return Flags;
}

//ALU METHODS
/**
 * Adds the Number2 to Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::ADD(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Subtracts the Number2 from Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::SUBTRACT(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Performs an AND of Number1 + Number2, and sets
 * the flags toggled by the operation.
 */
void Z80::AND(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Performs an OR of Number1 + Number2, and sets
 * the flags toggled by the operation.
 */
void Z80::OR(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Performs an Exclusive OR of Number1 + Number2, and sets
 * the flags toggled by the operation.
 */
void Z80::EXCLUSIVEOR(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Compares Number1 and Number2, and sets
 * the flags toggled by the operation.
 */
void Z80::COMPARE(uint16_t& Number1, uint16_t& Number2){

}

/**
 * Performs an Arithmetic Bit Shift on Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::ARITHMETICSHIFTBITS(uint16_t& Number1, int16_t NumBits){

}

/**
 * Performs an Logical Bit Shift on Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::LOGICALSHIFTBITS(uint16_t& Number, int16_t NumBits){

}

/**
 * Performs a rotate on Number, and sets
 * the flags toggled by the operation.
 */
void Z80::ROTATE(uint16_t& Number, bool Left){

}

/**
 * Performs an increment on Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::INCREMENT(uint16_t& Number, bool Word){
	Number++;
	if(!Word){
		uint8_t Flags(0);
		if((int16_t)Number < 0){
			Flags |= SF;
		}
		if(Number == 0){
			Flags |= ZF;
		}
		Flags |= (Number & F5F);
		if((((Number - 1) & 0xF) >> 3 == 1) && (((Number) & 0xF) >> 3 == 0)){
			Flags |= HF;
		}
		Flags |= (Number & F3F);
		if(Number - 1 == 0x7F){
			Flags |= PVF;
		}
		AF[0] |= Flags;
	}
}

/**
 * Performs an decrement on Number1, and sets
 * the flags toggled by the operation.
 */
void Z80::DECREMENT(uint16_t& Number, bool Word){
	Number--;
	if(!Word){

	}
}

/**
 * Sets the bit of Number specified by BitNum, and sets
 * the flags toggled by the operation.
 */
void Z80::SETBIT(uint16_t& Number, uint16_t BitNum){

}

/**
 * Resets the bit of Number specified by BitNum, and sets
 * the flags toggled by the operation.
 */
void Z80::RESETBIT(uint16_t& Number, uint16_t BitNum){

}

/**
 * Tests the bit of Number specified by BitNum, and sets
 * the flags toggled by the operation.
 */
void Z80::TESTBIT(uint16_t& Number, uint16_t BitNum){

}

void Z80::runCycle(){
	if(!HALT){
		if(this->executeOPCode(Memory[PC++]) != 0){

		}
	}
	if(InterruptType != NONE){
		if(InterruptType == NMI){
			IFF2 = IFF1;
			IFF1 = false;
			this->pushStack((PC & 0xFF00) >> 8);
			SP--;
			this->pushStack((PC & 0x00FF));
			PC = 0x0066;
			T += 13;
			//M += 3;
			HALT = false;
		}else if(InterruptType == MI && IFF1){
			switch(CPUMode){
				case M0:
					if(this->executeOPCode(interruptCode) != 0){

					}
					T += 2;
					break;
				case M1:
					this->pushStack((PC & 0xFF00) >> 8);
					SP--;
					this->pushStack((PC & 0x00FF));
					PC = 0x0038;
					T += 13;
					//M += 3;
					break;
				case M2:
					this->pushStack((PC & 0xFF00) >> 8);
					SP--;
					this->pushStack((PC & 0x00FF));
					PC = ((I << 8) | interruptCode) & 0xFFFE;
					T += 19;
					//M += 3;
					break;
				default:
					break;
			}
			HALT = false;
		}
		InterruptType = NONE;
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
		case 0x01:
			//BC[0] = (Memory[PC++] << 8) | Memory[PC++];
			T += 10;
			//M += 2;
			break;
		case 0x02:
			//Memory[BC[0]] = AF[0] >> 8;
			T += 10;
			//M += 2;
			break;

		default:
			Flags |= INVALID_OPCODE;
			break;
	}
	return Flags;
}

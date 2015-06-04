//====================================================================================
// Name        : Z80Stack.cpp
// Author      : Jered Tupik
// Version     : 1.0	5/17/2015
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
// Description : CPP file of Z80Stack.
//====================================================================================
#include "Z80Stack.h"

//Constructors / Destructors of the Z80 Stack Implementation
Z80Stack::Z80Stack(){
	SP = 0x0;
	Memory = std::shared_ptr<uint8_t>(new uint8_t[MEMORY_SIZE], std::default_delete<uint8_t[]>());
}

Z80Stack::Z80Stack(const uint16_t StackPointer, uint8_t* M){
	SP = StackPointer;
	Memory = std::shared_ptr<uint8_t>(M, std::default_delete<uint8_t[]>());
}

Z80Stack::Z80Stack(const uint16_t StackPointer, std::shared_ptr<uint8_t> M){
	SP = StackPointer;
	Memory = M;
}

Z80Stack::~Z80Stack(){

}

/**
 * Returns the current value of the Stack Pointer (SP)
 * of the Z80 Stack
 *
 * Returns:		The current value of the Stack Pointer
 */
uint16_t Z80Stack::getStackPointer(){
	return SP;
}

/**
 * Sets the Stack Pointer (SP) to the parameter
 * (Stack Pointer).
 *
 * Parameters:	 Stack Pointer - The new value of
 * 				 SP.
 */
void Z80Stack::setStackPointer(uint16_t StackPointer){
	SP = StackPointer;
}

/**
 * Increases the Stack Pointer (SP) by 1.
 *
 * Returns:		The exit status of the method.
 *
 * Errors:		EXIT_SUCCESS 	- 0
 * 				MEMORY_OVERFLOW - 1
 */
uint8_t Z80Stack::increaseStackPointer(){
	uint8_t ExitStatus(EXIT_SUCCESS);
	if(SP == 0xFFFF){
		ExitStatus |= MEMORY_OVERFLOW;
	}
	SP++;
	return ExitStatus;
}

/**
 * Decreases the Stack Pointer (SP) by 1.
 *
 * Returns:		The exit status of the method.
 *
 * Errors:		EXIT_SUCCESS 	 - 0
 * 				MEMORY_UNDERFLOW - 2
 */
uint8_t Z80Stack::decreaseStackPointer(){
	uint8_t ExitStatus(EXIT_SUCCESS);
	if(SP == 0){
		ExitStatus |= MEMORY_UNDERFLOW;
	}
	SP--;
	return ExitStatus;
}

/**
 * 'Pushes' the parameter (Value) to the top of
 * the stack.
 *
 * Parameters:	Value - The new byte to push to
 * 				the top of the stack.
 *
 * Returns:		The exit status of the push method.
 *
 * Errors:		EXIT_SUCCESS 	- 0
 * 				MEMORY_OVERFLOW - 1
 */
uint8_t Z80Stack::pushByte(uint8_t Value){
	uint8_t ExitStatus(0);
	Memory.get()[--SP] = Value;
	return ExitStatus;
}

/**
 * 'Pushes' the parameter (Value) to the top of
 * the stack. A word is pushed to the stack with
 * the most significant bit at SP, and the least
 * significant bit at SP - 1.
 *
 * Parameters:	Value - The new word to push to
 * 				the top of the stack.
 *
 * Returns:		The exit status of the push method.
 *
 * Errors:		EXIT_SUCCESS 	- 0
 * 				MEMORY_OVERFLOW - 1
 */
uint8_t Z80Stack::pushWord(uint16_t Value){
	uint8_t ExitStatus(0);
	if(SP == 0){
		ExitStatus |= MEMORY_OVERFLOW;
	}
	Memory.get()[--SP] = (Value >> 8);
	Memory.get()[--SP] = (Value & BYTE_MASK);
	return ExitStatus;
}

/**
 * 'Pops' the top byte from the Stack.
 *
 * Returns:		The top byte from the Stack.
 */
uint8_t Z80Stack::popByte(){
	uint8_t StackByte(0);
	StackByte = Memory.get()[SP++];
	return StackByte;
}

/**
 * 'Pops' the top word from the Stack. Since
 * the Stack stores things in byte-form, it pops
 * the current top, and pops the second value as well.
 *
 * Returns:		The top word from the Stack.
 */
uint16_t Z80Stack::popWord(){
	uint16_t StackWord(0);
	if(SP == 0){
		StackWord = 1;
	}
	StackWord = Memory.get()[SP++];
	StackWord = (Memory.get()[SP++] << 8) | StackWord;
	return StackWord;
}

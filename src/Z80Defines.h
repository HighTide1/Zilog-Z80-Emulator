//====================================================================================
// Name        : Z80DEFINES.h
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
// Description : Definition file for Z80 Flags and other defined operands
//====================================================================================
#ifndef Z80DEFINES_H_
#define Z80DEFINES_H_

//Status Register Flags
//Carry Flag
#define CF 0b00000001

//Subtract Flag
#define NF 0b00000010

//Parity/Overflow Flag
#define PVF 0b00000100

//Undocumented, Copy of bit 3
#define F3F 0b00001000

//Half Carry Flag (Carry of bit 3 to bit 4)
#define HF 0b00010000

//Undocumented, Copy of bit 5
#define F5F 0b00100000

//Zero Flag
#define ZF 0b01000000

//Sign Flag
#define SF 0b10000000

//Register References (M - Main, S - Shadow)
#define M_REGISTER    0
#define S_REGISTER    1

//External Memory Size (65536 bytes)
#define MEMORY_SIZE   0x10000

//Interrupt Type Masks
#define INTERRUPT_NONE 0
#define INTERRUPT_MASK 1
#define INTERRUPT_NMSK 2

//Error Codes
#define EXIT_SUCCESS	 0
#define INVALID_FILE 	 1
#define FILE_TO_BIG  	 2

#define MEMORY_OVERFLOW  1
#define MEMORY_UNDERFLOW 2

#define INVALID_OPCODE   1

#endif /* Z80DEFINES_H_ */

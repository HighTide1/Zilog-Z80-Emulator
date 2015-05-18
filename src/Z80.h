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
// Description : Header file of Z80. Contains Method and Variable Declarations.
//====================================================================================
#ifndef Z80_H_
#define Z80_H_

#include <fstream>
#include <iostream>
#include <stdint.h>
#include <string>

#include "InterruptMonitor.h"
#include "Z80Defines.h"
#include "Z80Stack.h"

class Z80{
	private:
		//External RAM for the Z80 Emulator
		uint8_t* Memory;

		/**
		 * Every Main Register on the Z80 has a respective
		 * shadow register (A has A', B has B'). To emulate
		 * this, we have each register acting as an array,
		 * with [0] being the main, and [1] being the shadow.
		 */

		//Accumulator/Flag Registers
		uint16_t AF[2];

		//1st Register Pairing (2 8-bit / 1 16-bit)
		uint16_t BC[2];

		//2nd Register Pairing (2 8-bit / 1 16-bit)
		uint16_t DE[2];

		//3rd Register Pairing (2 8-bit / 1 16-bit)
		uint16_t HL[2];

		//Index X Register
		uint16_t IX;

		//Index Y Register
		uint16_t IY;

		//Z80 Stack
		Z80Stack Stack;

		//Interrupt Vector
		uint8_t I;

		//Refresh Counter
		uint8_t R;

		//Program Counter
		uint16_t PC;

		//Clock Cycles for the Z80 Emulator
		unsigned long long int T;

		//Machine Cycles for the Z80 Emulator
		unsigned long long int M;

		//Interrupt Modes
		enum INTERRUPTMODE{
			M0,
			M1,
			M2
		};
		INTERRUPTMODE CPUMode;

		//Interrupt Poller for the Z80
		InterruptMonitor InterruptPoller;

		//Interrupt Flip Flop Registers
		bool IFF1;
		bool IFF2;

		//HALT Instruction
		bool HALT;

		void initializeRegisters();
		void resetMemory();
	public:
		//Constructors/Destructors
		Z80();
		Z80(const char*);
		Z80(const std::string);
		~Z80();

		//Loading/Reset Commands
		uint8_t loadFile(const std::string);
		void resetZ80();

		void runCycle();
		uint8_t executeOPCode(const uint8_t);
};

#endif

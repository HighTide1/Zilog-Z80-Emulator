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
#include <thread>
#include <vector>

#include "IInterruptDevice.h"
#include "Z80Defines.h"

class Z80{
	private:

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

		//Stack Pointer
		uint16_t SP;

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

		//External RAM for the Z80 Emulator
		uint8_t Memory[MEMORY_SIZE];

		//Interrupt Modes
		enum INTERRUPTMODE{
			M0,
			M1,
			M2
		};
		INTERRUPTMODE CPUMode;

		//Interrupt Devices
		std::vector<IInterruptDevice> InterruptDevices;

		//Interrupts
		enum INTERRUPT{
			NONE,
			MI,		//Maskable Interrupt
			NMI		//Non-Maskable Interrupt
		};
		INTERRUPT InterruptType;

		//Interrupt Monitoring Thread
		std::thread InterruptMonitor;

		//Interrupt Flip Flop Registers
		bool IFF1;
		bool IFF2;

		//Interrupt Data Code
		uint8_t interruptCode;

		//HALT Instruction
		bool HALT;

		void initializeRegisters();

		void interruptHandler(uint16_t);
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

		uint8_t popStack();
		uint8_t pushStack(const uint8_t);

		//ALU Methods
		void ADD(uint16_t&, uint16_t&);
		void SUBTRACT(uint16_t&, uint16_t&);
		void AND(uint16_t&, uint16_t&);
		void OR(uint16_t&, uint16_t&);
		void EXCLUSIVEOR(uint16_t&, uint16_t&);
		void COMPARE(uint16_t&, uint16_t&);
		void ARITHMETICSHIFTBITS(uint16_t&, int16_t);
		void LOGICALSHIFTBITS(uint16_t&, int16_t);
		void ROTATE(uint16_t&, bool);
		void INCREMENT(uint16_t&, bool);
		void DECREMENT(uint16_t&, bool);
		void SETBIT(uint16_t&, uint16_t);
		void RESETBIT(uint16_t&, uint16_t);
		void TESTBIT(uint16_t&, uint16_t);

};

#endif

//====================================================================================
// Name        : Z80ALU.h
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
// Description : Definition file of the Z80ALU
//====================================================================================
#ifndef Z80ALU_H_
#define Z80ALU_H_

#include <stdint.h>

class Z80ALU{
	private:
		//Flags set by the previous operation
		uint8_t Flags = 0;
	public:
		Z80ALU();
		Z80ALU(uint8_t&);
		~Z80ALU();

		uint8_t getFlags();
		void 	setFlags(uint8_t);

		//Addition Operations
		void ADD_B(uint8_t&, uint8_t&);
		void ADD_W(uint16_t&, uint16_t&);

		//Subtraction Operations
		void SUB_B(uint8_t&, uint8_t&);
		void SUB_W(uint16_t&, uint16_t&);

		//AND / OR / EXCLUSIVEOR Operations
		void AND(uint8_t&, uint8_t&);
		void OR(uint8_t&, uint8_t&);
		void XOR(uint8_t&, uint8_t&);

		//Compare Operation
		void COMP(uint8_t&, uint8_t&);

		//Bit Shift Operations (Arithmetic / Logical)
		void SLA(uint8_t&, uint8_t);
		void SLL(uint8_t&, uint8_t);
		void SRA(uint8_t&, uint8_t);
		void SRL(uint8_t&, uint8_t);

		//Rotate Operations
		void RL(uint8_t&);
		void RLC(uint8_t&);
		void RLB(uint8_t&);
		void RLCB(uint8_t&);
		void RR(uint8_t&);
		void RRC(uint8_t&);
		void RRB(uint8_t&);
		void RRCB(uint8_t&);

		//Increase Operations
		void INC_B(uint8_t&);
		void INC_W(uint16_t&);

		//Decrease Operations
		void DEC_B(uint8_t&);
		void DEC_W(uint16_t&);

		//Set Bit Operation
		void SET(uint8_t&, uint8_t);

		//Test Bit Operation
		void BIT(uint8_t&, uint8_t);

		//Reset Bit Operation
		void RES(uint8_t&, uint8_t);
};

#endif /* Z80ALU_H_ */

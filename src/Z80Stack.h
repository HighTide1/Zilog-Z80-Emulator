//====================================================================================
// Name        : Z80Stack.h
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
// Description : Definition file of Z80Stack
//====================================================================================
#ifndef Z80STACK_H_
#define Z80STACK_H_

#include <stdint.h>
#include <memory>

#include "Z80Defines.h"

class Z80Stack{
	private:
		//Stack Pointer of the Z80 Stack
		uint16_t SP;

		//Reference to memory of the Z80 Microprocessor
		std::shared_ptr<uint8_t> Memory;

	public:
		Z80Stack();
		Z80Stack(const uint16_t, uint8_t*);
		Z80Stack(const uint16_t, std::shared_ptr<uint8_t>);
		~Z80Stack();

		uint16_t getStackPointer();
		void 	 setStackPointer(uint16_t);

		uint8_t  increaseStackPointer();
		uint8_t  decreaseStackPointer();

		uint8_t  pushByte(uint8_t);
		uint8_t  pushWord(uint16_t);

		uint8_t  popByte();
		uint16_t popWord();
};

#endif /* Z80STACK_H_ */

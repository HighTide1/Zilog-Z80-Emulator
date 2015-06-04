//============================================================================
// Name        : Z80Emulator
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
// Description : Application file for the Z80 Emulator
//============================================================================
#include "Z80.h"
#include <iomanip>

int main() {
	/*Z80ALU ALU;
	for(uint16_t i = 0; i < 65535; i++){
		for(uint16_t j = 0; j < 65535; j++){
			uint16_t C_I = i;
			//ALU.setFlags(0);
			ALU.ADD_W(C_I, j);
			std::cout << C_I << ", " << (uint16_t)(i+j) << std::endl;
			if(C_I != (uint16_t)(i + j)){
				std::cout << "Error: Calculated Answer: " << C_I << ", Real Answer: " << (i + j) << std::endl;
			}
			/*C_I = i;
			ALU.setFlags(1);
			ALU.SBC_W(C_I, j);
			if(C_I != (uint16_t)(i - j - 1)){
				std::cout << "Error: Calculated Answer: " << C_I << ", Real Answer: " << (uint16_t)(i - j - 1) << std::endl;
			}*/
		//}
	//}

	Z80 Emulator;
	Emulator.loadFile("zexdoc.com", 0x100);
	Emulator.setPC(0x100);
	while(true){
		Emulator.runCycle();
	}
	return EXIT_SUCCESS;
}

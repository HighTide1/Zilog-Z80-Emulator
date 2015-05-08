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

#include "Z80Defines.h"

//Constructor / Destructors
Z80::Z80(){
	initializeRegisters();
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
	SP = 0x0;
	I = 0x0;
	R = 0x0;
	PC = 0x0;
	CC = 0x0;
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

		}
	}
	return Flags;
}


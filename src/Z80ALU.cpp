//====================================================================================
// Name        : Z80ALU.cpp
// Author      : Jered Tupik
// Version     : 1.0	5/18/2015
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
// Description : CPP file of the Z80ALU
//====================================================================================
#include "Z80ALU.h"

//Constructors / Destructors
Z80ALU::Z80ALU(){
	Flags = 0;
}

Z80ALU::Z80ALU(uint8_t& F){
	Flags = F;
}

Z80ALU::~Z80ALU(){

}

uint8_t Z80ALU::getFlags(){
	return Flags;
}

void Z80ALU::setFlags(uint8_t F){
	Flags = F;
}

//Utility Methods
const uint8_t Z80ALU::CHECK(uint8_t& NUM){
	uint8_t F = 0;
	if(CMP_B(NUM) < 0){
		F |= SF;
	}
	if(NUM == 0){
		F |= ZF;
	}
	//F |= (NUM & F5F);
	//F |= (NUM & F3F);
	return F;
}

const uint8_t Z80ALU::PARITY(uint8_t& NUM){
	uint8_t P = 0x1;
	int bitNum = 0;
	while(bitNum < 8){
		if(((NUM & (0x1 << bitNum)) >> bitNum) == 1){
			P ^= 0x1;
		}
		bitNum++;
	}
	return P;
}

int8_t Z80ALU::CMP_B(uint8_t NUM){
	return NUM < 128 ? NUM : NUM - 256;
}

int16_t Z80ALU::CMP_W(uint16_t NUM){
	return NUM < 32768 ? NUM : NUM - 65536;
}

//ALU Methods
void Z80ALU::ADD_B(uint8_t& F_NUM, uint8_t& S_NUM){
	/*uint8_t RESULT = F_NUM + S_NUM;
	uint8_t F = CHECK(RESULT);
	if((uint8_t)(F_NUM & NIBBLE_MASK) + (uint8_t)(S_NUM & NIBBLE_MASK) > 15){
		F |= HF;
	}
	if((CMP_B(F_NUM) > 0) && (CMP_B(S_NUM) > 0) && (CMP_B(RESULT) < 0)){
		F |= PVF;
	}else if((CMP_B(F_NUM) < 0) && (CMP_B(S_NUM) < 0) && (CMP_B(RESULT) > 0)){
		F |= PVF;
	}
	if(((uint16_t)F_NUM) + ((uint16_t)S_NUM) > 0xFF){
		F |= CF;
	}
	F_NUM = RESULT;
	Flags = F;*/
	uint16_t RESULT = F_NUM + S_NUM;
	uint16_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = 0;

	F |= (RESULT & SF);
	F |= ((RESULT & 0xFF) == 0 ? ZF : 0);
	F |= ((CARRY & HF) != 0 ? HF : 0);
	if((CARRY >> 7) != 0 && (CARRY >> 7) != 3){
		F |= PVF;
	}
	F |= (RESULT >> 8);

	F_NUM = (RESULT & 0xFF);
	Flags = F;
}

void Z80ALU::ADC_B(uint8_t& F_NUM, uint8_t& S_NUM){
	/*uint8_t RESULT = F_NUM + S_NUM + (Flags & CF);
	uint8_t F = CHECK(RESULT);
	if((F_NUM & NIBBLE_MASK) + (S_NUM & NIBBLE_MASK) + (Flags & CF) > 15){
		F |= HF;
	}
	if((CMP_B(F_NUM) > 0) && (CMP_B(S_NUM) > 0) && (CMP_B(RESULT) < 0)){
		F |= PVF;
	}else if((CMP_B(F_NUM) < 0) && (CMP_B(S_NUM) < 0) && (CMP_B(RESULT) > 0)){
		F |= PVF;
	}
	if((((uint16_t)F_NUM) + ((uint16_t)S_NUM) + ((uint16_t)(Flags & CF))) > 0xFF){
		F |= CF;
	}
	F_NUM = RESULT;
	Flags = F;*/
	uint16_t RESULT = F_NUM + S_NUM + (Flags & CF);
	uint16_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = 0;

	F |= (RESULT & SF);
	F |= ((RESULT & 0xFF) == 0 ? ZF : 0);
	F |= ((CARRY & HF) != 0 ? HF : 0);
	if((CARRY >> 7) != 0 && (CARRY >> 7) != 3){
		F |= PVF;
	}
	F |= (RESULT >> 8);

	F_NUM = (RESULT & 0xFF);
	Flags = F;
}

void Z80ALU::ADD_W(uint16_t& F_NUM, uint16_t& S_NUM){
	/*uint8_t L_F = F_NUM & BYTE_MASK, L_S = S_NUM & BYTE_MASK;
	uint8_t H_F = F_NUM >> 8, H_S = S_NUM >> 8;
	uint16_t RESULT = 0;
	uint8_t F = (Flags & (SF | ZF | PVF));

	this->ADD_B(L_F, L_S);
	this->ADC_B(H_F, H_S);

	RESULT = (H_F << 8) | (uint16_t)L_F;
	F_NUM = RESULT;
	F |= (Flags & (HF | CF));
	Flags = F;*/
	uint32_t RESULT = F_NUM + S_NUM;
	uint32_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = (Flags & (SF | ZF | PVF));

	F |= (((CARRY >> 8) & HF) != 0 ? HF : 0);
	F |= (RESULT >> 16);

	RESULT &= 0xFFFF;
	F_NUM = RESULT;
	Flags = F;
}

void Z80ALU::ADC_W(uint16_t& F_NUM, uint16_t& S_NUM){
	/*uint8_t L_F = F_NUM & BYTE_MASK, L_S = S_NUM & BYTE_MASK;
	uint8_t H_F = F_NUM >> 8, H_S = S_NUM >> 8;

	this->ADC_B(L_F, L_S);
	this->ADC_B(H_F, H_S);

	uint16_t RESULT = (H_F << 8) | (uint16_t)L_F;
	F_NUM = RESULT;*/
	uint32_t RESULT = F_NUM + S_NUM + (Flags & CF);
	uint32_t CARRY = (F_NUM ^ S_NUM ^ RESULT);
	uint8_t F = 0;

	F |= ((RESULT >> 8) & SF);
	F |= ((RESULT & 0xFFFF) == 0 ? ZF : 0);
	F |= (((CARRY >> 8) & HF) != 0 ? HF : 0);
	if((CARRY >> 15) != 0 && (CARRY >> 15) != 3){
		F |= PVF;
	}
	F |= (RESULT >> 16);

	F_NUM = (RESULT & 0xFFFF);
	Flags = F;
}

void Z80ALU::SUB_B(uint8_t& F_NUM, uint8_t& S_NUM){
	/*uint8_t RESULT = F_NUM - S_NUM;
	uint8_t F = CHECK(RESULT);
	if((F_NUM & NIBBLE_MASK) < (S_NUM & NIBBLE_MASK)){
		F |= HF;
	}
	if((CMP_B(F_NUM) > 0) && (CMP_B(S_NUM) < 0) && (CMP_B(RESULT) > 0)){
		F |= PVF;
	}else if((CMP_B(F_NUM) < 0) && (CMP_B(S_NUM) > 0) && (CMP_B(RESULT) < 0)){
		F |= PVF;
	}
	F |= NF;
	if(F_NUM < S_NUM){
		F |= CF;
	}
	F_NUM = RESULT;
	Flags = F;*/
	uint16_t RESULT = F_NUM - S_NUM;
	uint16_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = 0;

	F |= (RESULT & SF);
	F |= ((RESULT & 0xFF) == 0 ? ZF : 0);
	F |= ((CARRY & HF) != 0 ? HF : 0);
	if(((CARRY >> 7) & 0x3) != 0 && ((CARRY >> 7) & 0x3) != 3){
		F |= PVF;
	}
	F |= NF;
	F |= ((RESULT >> 8) & 0x1);

	F_NUM = (RESULT & 0xFF);
	Flags = F;
}

void Z80ALU::SBC_B(uint8_t& F_NUM, uint8_t& S_NUM){
	/*uint8_t RESULT = F_NUM - S_NUM - (Flags & CF);
	uint8_t F = CHECK(RESULT);
	if((F_NUM & NIBBLE_MASK) < (uint8_t)((S_NUM & NIBBLE_MASK) - (Flags & CF))){
		F |= HF;
	}
	if((CMP_B(F_NUM) > 0) && (CMP_B((uint8_t)S_NUM) < 0) && (CMP_B(RESULT) > 0)){
		F |= PVF;
	}else if((CMP_B(F_NUM) < 0) && (CMP_B((uint8_t)S_NUM) > 0) && (CMP_B(RESULT) < 0)){
		F |= PVF;
	}
	F |= NF;
	uint16_t CARRY = (F_NUM ^ S_NUM ^ (F_NUM - S_NUM - (Flags & CF)));
	if((CARRY >> 8) != 0){
		F |= CF;
	}
	F_NUM = RESULT;
	Flags = F;*/
	uint16_t RESULT = F_NUM - S_NUM - (Flags & CF);
	uint16_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = 0;

	F |= (RESULT & SF);
	F |= ((RESULT & 0xFF) == 0 ? ZF : 0);
	F |= ((CARRY & HF) != 0 ? HF : 0);
	if(((CARRY >> 7) & 0x3) != 0 && ((CARRY >> 7) & 0x3) != 3){
		F |= PVF;
	}
	F |= NF;
	F |= ((RESULT >> 8) & 0x1);

	F_NUM = (RESULT & 0xFF);
	Flags = F;
}

void Z80ALU::SBC_W(uint16_t& F_NUM, uint16_t& S_NUM){
	/*uint8_t L_F = F_NUM & BYTE_MASK, L_S = S_NUM & BYTE_MASK;
	uint8_t H_F = F_NUM >> 8, H_S = S_NUM >> 8;

	this->SBC_B(L_F, L_S);
	this->SBC_B(H_F, H_S);

	uint16_t RESULT = (H_F << 8) | (uint16_t)L_F;
	F_NUM = RESULT;*/
	uint32_t RESULT = F_NUM - S_NUM - (Flags & CF);
	uint16_t CARRY = F_NUM ^ S_NUM ^ RESULT;
	uint8_t F = 0;

	F |= ((RESULT >> 8) & SF);
	F |= ((RESULT & 0xFFFF) == 0 ? ZF : 0);
	F |= (((CARRY >> 8) & HF) != 0 ? HF : 0);
	if(((CARRY >> 15) & 0x3) != 0 && ((CARRY >> 15) & 0x3) != 3){
		F |= PVF;
	}
	F |= NF;
	F |= ((RESULT >> 16) & 0x1);

	F_NUM = (RESULT & 0xFFFF);
	Flags = F;
}

void Z80ALU::AND(uint8_t& F_NUM, uint8_t& S_NUM){
	uint8_t RESULT = F_NUM & S_NUM;
	uint8_t F = CHECK(RESULT);
	F |= HF;
	F |= (PARITY(RESULT) << 2);
	F_NUM = RESULT;
	Flags = F;
}

void Z80ALU::OR(uint8_t& F_NUM, uint8_t& S_NUM){
	uint8_t RESULT = F_NUM | S_NUM;
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F_NUM = RESULT;
	Flags = F;
}

void Z80ALU::XOR(uint8_t& F_NUM, uint8_t& S_NUM){
	uint8_t RESULT = F_NUM ^ S_NUM;
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F_NUM = RESULT;
	Flags = F;
}

void Z80ALU::COMP(uint8_t& F_NUM, uint8_t& S_NUM){
	uint8_t RESULT = F_NUM;
	this->SUB_B(RESULT, S_NUM);
}

void Z80ALU::SLA(uint8_t& NUM, uint8_t NUMBITS){
	uint8_t RESULT = ((NUM << NUMBITS) & ~CF);
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::SLL(uint8_t& NUM, uint8_t NUMBITS){
	uint8_t RESULT = (NUM << NUMBITS) | 1;
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::SRA(uint8_t& NUM, uint8_t NUMBITS){
	uint8_t RESULT = ((NUM >> NUMBITS) | (NUM & SF));
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM & CF);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::SRL(uint8_t& NUM, uint8_t NUMBITS){
	uint8_t RESULT = (NUM >> NUMBITS);
	RESULT &= ~SF;
	uint8_t F = CHECK(RESULT);
	F &= ~SF;
	F |= (PARITY(RESULT) << 2);
	F |= (NUM & 1);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RL(uint8_t& NUM){
	uint8_t RESULT = ((NUM << 1) | (Flags & CF));
	uint8_t F = (Flags & (SF | ZF | PVF));
	//F |= (RESULT & F5F);
	//F |= (RESULT & F3F);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RLC(uint8_t& NUM){
	uint8_t RESULT = ((NUM << 1) | (NUM >> 7));
	uint8_t F = (Flags & (SF | ZF | PVF));
	//F |= (RESULT & F5F);
	//F |= (RESULT & F3F);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RLB(uint8_t& NUM){
	uint8_t RESULT = ((NUM << 1) | (Flags & CF));
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RLCB(uint8_t& NUM){
	uint8_t RESULT = ((NUM << 1) | (NUM >> 7));
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM >> 7);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RR(uint8_t& NUM){
	uint8_t RESULT = ((NUM >> 1) | ((Flags & CF) << 7));
	uint8_t F = (Flags & (SF | ZF | PVF));
	//F |= (RESULT & F5F);
	//F |= (RESULT & F3F);
	F |= (NUM & CF);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RRC(uint8_t& NUM){
	uint8_t RESULT = ((NUM >> 1) | ((NUM & CF) << 7));
	uint8_t F = (Flags & (SF | ZF | PVF));
	//F |= (RESULT & F5F);
	//F |= (RESULT & F3F);
	F |= (NUM & CF);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RRB(uint8_t& NUM){
	uint8_t RESULT = ((NUM >> 1) | ((Flags & CF) << 7));
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM & CF);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::RRCB(uint8_t& NUM){
	uint8_t RESULT = ((NUM >> 1) | ((NUM & CF) << 7));
	uint8_t F = CHECK(RESULT);
	F |= (PARITY(RESULT) << 2);
	F |= (NUM & CF);
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::INC_B(uint8_t& NUM){
	uint8_t RESULT = NUM + 1;
	uint8_t F = (CHECK(RESULT) | (Flags & CF));
	if((NUM & NIBBLE_MASK) + 1 > 15){
		F |= HF;
	}
	if(NUM == 0x7F){
		F |= PVF;
	}
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::INC_W(uint16_t& NUM){
	NUM += 1;
}

void Z80ALU::DEC_B(uint8_t& NUM){
	uint8_t RESULT = NUM - 1;
	uint8_t F = (CHECK(RESULT) | (Flags & CF));
	if((NUM & NIBBLE_MASK) < 1){
		F |= HF;
	}
	if(NUM == 0x80){
		F |= PVF;
	}
	F |= NF;
	NUM = RESULT;
	Flags = F;
}

void Z80ALU::DEC_W(uint16_t& NUM){
	NUM -= 1;
}

void Z80ALU::SET(uint8_t& NUM, uint8_t BIT){
	NUM = NUM | (0x1 << BIT);
}

void Z80ALU::RES(uint8_t& NUM, uint8_t BIT){
	NUM = NUM & ~((0x1 << BIT));
}

void Z80ALU::BIT(uint8_t& NUM, uint8_t BIT){
	uint8_t F = (Flags & CF);
	bool BIT_STATUS = ((NUM >> BIT) & 0x1);
	if(!BIT_STATUS){
		F |= ZF;
	}
	F |= HF;
	Flags = F;
}

void Z80ALU::NEG(uint8_t& NUM){
	uint8_t RESULT = (0 - NUM);
	uint8_t F = CHECK(RESULT);
	if((NUM & NIBBLE_MASK) > 0){
		F |= HF;
	}
	if(NUM == 0x80){
		F |= PVF;
	}
	F |= NF;
	if(NUM != 0){
		F |= CF;
	}
	NUM = RESULT;
	Flags = F;
}

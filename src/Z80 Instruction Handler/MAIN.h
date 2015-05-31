//====================================================================================
// Name        : MAIN.h
// Author      : Jered Tupik
// Version     : 1.0	5/27/2015
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
// Description : Case File for Main Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_MAIN_H_
#define Z80_INSTRUCTION_HANDLER_MAIN_H_

case 0x00:
	break;
case 0x01:
	BC[M_REGISTER] = getMemoryWord();
	break;
case 0x02:
	Memory.get()[BC[M_REGISTER]] = A;
	break;
case 0x03:
	ALU.INC_W(BC[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x04:
	ALU.INC_B(B);
	F = ALU.getFlags();
	break;
case 0x05:
	ALU.DEC_B(B);
	F = ALU.getFlags();
	break;
case 0x06:
	B = getMemoryByte();
	break;
case 0x07:
	ALU.RLC(A);
	F = ALU.getFlags();
	break;
case 0x08:
{
	uint16_t AF_C = AF[M_REGISTER];
	A = (AF[S_REGISTER] >> 8);
	F = (AF[S_REGISTER] & BYTE_MASK);
	AF[S_REGISTER] = AF_C;
	break;
}
case 0x09:
	ALU.ADD_W(HL[M_REGISTER], BC[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x0A:
	A = Memory.get()[BC[M_REGISTER]];
	break;
case 0x0B:
	ALU.DEC_W(BC[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x0C:
	ALU.INC_B(C);
	F = ALU.getFlags();
	break;
case 0x0D:
	ALU.DEC_B(C);
	F = ALU.getFlags();
	break;
case 0x0E:
	C = getMemoryByte();
	break;
case 0x0F:
	ALU.RRC(A);
	F = ALU.getFlags();
	break;
case 0x10:
	ALU.DEC_B(B);
	if((ALU.getFlags() & ZF) == 0){
		uint16_t C_PC = PC;
		PC = (C_PC - 1) + ALU.CMP_B(getMemoryByte());
		mP = true;
	}
	break;
case 0x11:
	DE[M_REGISTER] = getMemoryWord();
	break;
case 0x12:
	Memory.get()[DE[M_REGISTER]] = A;
	break;
case 0x13:
	ALU.INC_W(DE[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x14:
	ALU.INC_B(D);
	F = ALU.getFlags();
	break;
case 0x15:
	ALU.DEC_B(D);
	F = ALU.getFlags();
	break;
case 0x16:
	D = getMemoryByte();
	break;
case 0x17:
	ALU.RL(A);
	F = ALU.getFlags();
	break;
case 0x18:
{
	uint16_t C_PC = PC;
	PC = (C_PC - 1) + ALU.CMP_B(getMemoryByte());
	mP = true;
	break;
}
case 0x19:
	ALU.ADD_W(HL[M_REGISTER], DE[M_REGISTER]);
	break;
case 0x1A:
	A = Memory.get()[DE[M_REGISTER]];
	break;
case 0x1B:
	ALU.DEC_W(DE[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x1C:
	ALU.INC_B(E);
	F = ALU.getFlags();
	break;
case 0x1D:
	ALU.DEC_B(E);
	F = ALU.getFlags();
	break;
case 0x1E:
	E = getMemoryByte();
	break;
case 0x1F:
	ALU.RR(A);
	F = ALU.getFlags();
	break;
case 0x20:
	if((F & ZF) == 0){
		uint16_t C_PC = PC;
		PC = C_PC + ALU.CMP_B(getMemoryByte());
		mP = true;
	}
	break;
case 0x21:
	HL[M_REGISTER] = getMemoryWord();
	break;
case 0x22:
	Memory.get()[getMemoryWord()] = HL[M_REGISTER];
	break;
case 0x23:
	ALU.INC_W(HL[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x24:
	ALU.INC_B(H);
	F = ALU.getFlags();
	break;
case 0x25:
	ALU.DEC_B(H);
	F = ALU.getFlags();
	break;
case 0x26:
	H = getMemoryByte();
	break;
case 0x27:
	//DAA Instruction - NEED TO CHECK IF ADD HEX OR DEC
{
	uint8_t H_A = (A >> 4), L_A = (A & NIBBLE_MASK);
	F &= ~CF;
	if((F & NF) == 0){
		if((F & CF) == 0){
			if((F & HF) == 0){
				if((H_A >= 0 && H_A <= 8) && (L_A >= 0xA && L_A <= 0xF)){
					A += 0x6;
				}else if((H_A >= 0xA && H_A <= 0xF) && (L_A >= 0 && L_A <= 9)){
					A += 0x60;
					F |= CF;
				}else if((H_A >= 9 && H_A <= 0xF) && (L_A >= 0xA && L_A <= 0xF)){
					A += 0x66;
					F |= CF;
				}
			}else{
				if((H_A >= 0 && H_A <= 9) && (L_A >= 0 && L_A <= 3)){
					A += 0x6;
				}else if((H_A >= 0xA && H_A <= 0xF) && (L_A >= 0 && L_A <= 3)){
					A += 0x66;
					F |= CF;
				}
			}
		}else{
			if((F & HF) == 0){
				if((H_A >= 0 && H_A <= 2) && (L_A >= 0 && L_A <= 9)){
					A += 0x60;
				}else if((H_A >= 0 && H_A <= 2) && (L_A >= 0xA && L_A <= 0xF)){
					A += 0x66;
				}
			}else{
				if((H_A >= 0 && H_A <= 3) && (L_A >= 0 && L_A <= 3)){
					A += 0x66;
				}
			}
			F |= CF;
		}
	}else{
		if((F & CF) == 0){
			if((F & HF) != 0){
				if((H_A >= 0 && H_A <= 8) && (L_A >= 6 && L_A <= 0xF)){
					A += 0xFA;
				}
			}
		}else{
			if((F & HF) == 0){
				if((H_A >= 7 && H_A <= 0xF) && (L_A >= 0 && L_A <= 9)){
					A += 0xA0;
				}
			}else{
				if((H_A >= 6 && H_A <= 7) && (L_A >= 6 && L_A <= 0xF)){
					A += 0x9A;
				}
			}
			F |= CF;
		}
	}
	break;
}
case 0x28:
	if((F & ZF) != 0){
		uint16_t C_PC = PC;
		PC = C_PC + ALU.CMP_B(getMemoryByte());
		mP = true;
	}
	break;
case 0x29:
	ALU.ADD_W(HL[M_REGISTER], HL[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x2A:
	HL[M_REGISTER] = Memory.get()[getMemoryWord()];
	break;
case 0x2B:
	ALU.DEC_W(HL[M_REGISTER]);
	//F = ALU.getFlags();
	break;
case 0x2C:
	ALU.INC_B(L);
	F = ALU.getFlags();
	break;
case 0x2D:
	ALU.DEC_B(L);
	F = ALU.getFlags();
	break;
case 0x2E:
	L = getMemoryByte();
	break;
case 0x2F:
	A = ~A;
	F |= HF;
	F |= NF;
	break;
case 0x30:
	if((F & CF) == 0){
		uint16_t C_PC = PC;
		PC = C_PC + ALU.CMP_B(getMemoryByte());
		mP = true;
	}
	break;
case 0x31:
	Stack.setStackPointer(getMemoryWord());
	break;
case 0x32:
	Memory.get()[getMemoryWord()] = HL[M_REGISTER];
	break;
case 0x33:
	ALU.INC_W(SP);
	Stack.setStackPointer(SP);
	//F = ALU.getFlags();
	break;
case 0x34:
	ALU.INC_B(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x35:
	ALU.DEC_B(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x36:
	Memory.get()[HL[M_REGISTER]] = getMemoryByte();
	break;
case 0x37:
	F |= CF;
	break;
case 0x38:
	if((F & CF) != 0){
		uint16_t C_PC = PC;
		PC = C_PC + ALU.CMP_B(getMemoryByte());
		mP = true;
	}
	break;
case 0x39:
	ALU.ADD_W(HL[M_REGISTER], SP);
	//F = ALU.getFlags();
	break;
case 0x3A:
	A = Memory.get()[getMemoryWord()];
	break;
case 0x3B:
	ALU.DEC_W(SP);
	//F = ALU.getFlags();
	break;
case 0x3C:
	ALU.INC_B(A);
	F = ALU.getFlags();
	break;
case 0x3D:
	ALU.DEC_B(A);
	F = ALU.getFlags();
	break;
case 0x3E:
	A = getMemoryByte();
	break;
case 0x3F:
	F ^= CF;
	break;
case 0x40:
	//B = B;
	break;
case 0x41:
	B = C;
	break;
case 0x42:
	B = D;
	break;
case 0x43:
	B = E;
	break;
case 0x44:
	B = H;
	break;
case 0x45:
	B = L;
	break;
case 0x46:
	B = Memory.get()[HL[M_REGISTER]];
	break;
case 0x47:
	B = A;
	break;
case 0x48:
	C = B;
	break;
case 0x49:
	//C = C;
	break;
case 0x4A:
	C = D;
	break;
case 0x4B:
	C = E;
	break;
case 0x4C:
	C = H;
	break;
case 0x4D:
	C = L;
	break;
case 0x4E:
	C = Memory.get()[HL[M_REGISTER]];
	break;
case 0x4F:
	C = A;
	break;
case 0x50:
	D = B;
	break;
case 0x51:
	D = C;
	break;
case 0x52:
	//D = D;
	break;
case 0x53:
	D = E;
	break;
case 0x54:
	D = H;
	break;
case 0x55:
	D = L;
	break;
case 0x56:
	D = Memory.get()[HL[M_REGISTER]];
	break;
case 0x57:
	D = A;
	break;
case 0x58:
	E = B;
	break;
case 0x59:
	E = C;
	break;
case 0x5A:
	E = D;
	break;
case 0x5B:
	//E = E;
	break;
case 0x5C:
	E = H;
	break;
case 0x5D:
	E = L;
	break;
case 0x5E:
	E = Memory.get()[HL[M_REGISTER]];
	break;
case 0x5F:
	E = A;
	break;
case 0x60:
	H = B;
	break;
case 0x61:
	H = C;
	break;
case 0x62:
	H = D;
	break;
case 0x63:
	H = E;
	break;
case 0x64:
	//H = H;
	break;
case 0x65:
	H = L;
	break;
case 0x66:
	H = Memory.get()[HL[M_REGISTER]];
	break;
case 0x67:
	H = A;
	break;
case 0x68:
	L = B;
	break;
case 0x69:
	L = C;
	break;
case 0x6A:
	L = D;
	break;
case 0x6B:
	L = E;
	break;
case 0x6C:
	L = H;
	break;
case 0x6D:
	//L = L;
	break;
case 0x6E:
	L = Memory.get()[HL[M_REGISTER]];
	break;
case 0x6F:
	L = A;
	break;
case 0x70:
	Memory.get()[HL[M_REGISTER]] = B;
	break;
case 0x71:
	Memory.get()[HL[M_REGISTER]] = C;
	break;
case 0x72:
	Memory.get()[HL[M_REGISTER]] = D;
	break;
case 0x73:
	Memory.get()[HL[M_REGISTER]] = E;
	break;
case 0x74:
	Memory.get()[HL[M_REGISTER]] = H;
	break;
case 0x75:
	Memory.get()[HL[M_REGISTER]] = L;
	break;
case 0x76:
	HALT = true;
	break;
case 0x77:
	Memory.get()[HL[M_REGISTER]] = A;
	break;
case 0x78:
	A = B;
	break;
case 0x79:
	A = C;
	break;
case 0x7A:
	A = D;
	break;
case 0x7B:
	A = E;
	break;
case 0x7C:
	A = H;
	break;
case 0x7D:
	A = L;
	break;
case 0x7E:
	A = Memory.get()[HL[M_REGISTER]];
	break;
case 0x7F:
	//A = A;
	break;
case 0x80:
	ALU.ADD_B(A, B);
	F = ALU.getFlags();
	break;
case 0x81:
	ALU.ADD_B(A, C);
	F = ALU.getFlags();
	break;
case 0x82:
	ALU.ADD_B(A, D);
	F = ALU.getFlags();
	break;
case 0x83:
	ALU.ADD_B(A, E);
	F = ALU.getFlags();
	break;
case 0x84:
	ALU.ADD_B(A, H);
	F = ALU.getFlags();
	break;
case 0x85:
	ALU.ADD_B(A, L);
	F = ALU.getFlags();
	break;
case 0x86:
	ALU.ADD_B(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x87:
	ALU.ADD_B(A, A);
	F = ALU.getFlags();
	break;
case 0x88:
	ALU.ADC_B(A, B);
	F = ALU.getFlags();
	break;
case 0x89:
	ALU.ADC_B(A, C);
	F = ALU.getFlags();
	break;
case 0x8A:
	ALU.ADC_B(A, D);
	F = ALU.getFlags();
	break;
case 0x8B:
	ALU.ADC_B(A, E);
	F = ALU.getFlags();
	break;
case 0x8C:
	ALU.ADC_B(A, H);
	F = ALU.getFlags();
	break;
case 0x8D:
	ALU.ADC_B(A, L);
	F = ALU.getFlags();
	break;
case 0x8E:
	ALU.ADC_B(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x8F:
	ALU.ADC_B(A, A);
	F = ALU.getFlags();
	break;
case 0x90:
	ALU.SUB_B(A, B);
	F = ALU.getFlags();
	break;
case 0x91:
	ALU.SUB_B(A, C);
	F = ALU.getFlags();
	break;
case 0x92:
	ALU.SUB_B(A, D);
	F = ALU.getFlags();
	break;
case 0x93:
	ALU.SUB_B(A, E);
	F = ALU.getFlags();
	break;
case 0x94:
	ALU.SUB_B(A, H);
	F = ALU.getFlags();
	break;
case 0x95:
	ALU.SUB_B(A, L);
	F = ALU.getFlags();
	break;
case 0x96:
	ALU.SUB_B(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x97:
	ALU.SUB_B(A, A);
	F = ALU.getFlags();
	break;
case 0x98:
	ALU.SBC_B(A, B);
	F = ALU.getFlags();
	break;
case 0x99:
	ALU.SBC_B(A, C);
	F = ALU.getFlags();
	break;
case 0x9A:
	ALU.SBC_B(A, D);
	F = ALU.getFlags();
	break;
case 0x9B:
	ALU.SBC_B(A, E);
	F = ALU.getFlags();
	break;
case 0x9C:
	ALU.SBC_B(A, H);
	F = ALU.getFlags();
	break;
case 0x9D:
	ALU.SBC_B(A, L);
	F = ALU.getFlags();
	break;
case 0x9E:
	ALU.SBC_B(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x9F:
	ALU.SBC_B(A, A);
	F = ALU.getFlags();
	break;
case 0xA0:
	ALU.AND(A, B);
	F = ALU.getFlags();
	break;
case 0xA1:
	ALU.AND(A, C);
	F = ALU.getFlags();
	break;
case 0xA2:
	ALU.AND(A, D);
	F = ALU.getFlags();
	break;
case 0xA3:
	ALU.AND(A, E);
	F = ALU.getFlags();
	break;
case 0xA4:
	ALU.AND(A, H);
	F = ALU.getFlags();
	break;
case 0xA5:
	ALU.AND(A, L);
	F = ALU.getFlags();
	break;
case 0xA6:
	ALU.AND(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0xA7:
	ALU.AND(A, A);
	F = ALU.getFlags();
	break;
case 0xA8:
	ALU.XOR(A, B);
	F = ALU.getFlags();
	break;
case 0xA9:
	ALU.XOR(A, C);
	F = ALU.getFlags();
	break;
case 0xAA:
	ALU.XOR(A, D);
	F = ALU.getFlags();
	break;
case 0xAB:
	ALU.XOR(A, E);
	F = ALU.getFlags();
	break;
case 0xAC:
	ALU.XOR(A, H);
	F = ALU.getFlags();
	break;
case 0xAD:
	ALU.XOR(A, L);
	F = ALU.getFlags();
	break;
case 0xAE:
	ALU.XOR(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0xAF:
	ALU.XOR(A, A);
	F = ALU.getFlags();
	break;
case 0xB0:
	ALU.OR(A, B);
	F = ALU.getFlags();
	break;
case 0xB1:
	ALU.OR(A, C);
	F = ALU.getFlags();
	break;
case 0xB2:
	ALU.OR(A, D);
	F = ALU.getFlags();
	break;
case 0xB3:
	ALU.OR(A, E);
	F = ALU.getFlags();
	break;
case 0xB4:
	ALU.OR(A, H);
	F = ALU.getFlags();
	break;
case 0xB5:
	ALU.OR(A, L);
	F = ALU.getFlags();
	break;
case 0xB6:
	ALU.OR(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0xB7:
	ALU.OR(A, A);
	F = ALU.getFlags();
	break;
case 0xB8:
	ALU.COMP(A, B);
	F = ALU.getFlags();
	break;
case 0xB9:
	ALU.COMP(A, C);
	F = ALU.getFlags();
	break;
case 0xBA:
	ALU.COMP(A, D);
	F = ALU.getFlags();
	break;
case 0xBB:
	ALU.COMP(A, E);
	F = ALU.getFlags();
	break;
case 0xBC:
	ALU.COMP(A, H);
	F = ALU.getFlags();
	break;
case 0xBD:
	ALU.COMP(A, L);
	F = ALU.getFlags();
	break;
case 0xBE:
	ALU.COMP(A, Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0xBF:
	ALU.COMP(A, A);
	F = ALU.getFlags();
	break;
case 0xC0:
	if((F & ZF) == 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xC1:
	BC[M_REGISTER] = Stack.popWord();
	break;
case 0xC2:
	if((F & ZF) == 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xC3:
	PC = getMemoryWord();
	mP = true;
	break;
case 0xC4:
	if((F & ZF) == 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xC5:
	Stack.pushWord(BC[M_REGISTER]);
	break;
case 0xC6:
{
	uint8_t M_B = getMemoryByte();
	ALU.ADD_B(A, M_B);
	break;
}
case 0xC7:
	Stack.pushWord(PC + 1);
	PC = 0x00;
	mP = true;
	break;
case 0xC8:
	if((F & ZF) != 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xC9:
	PC = Stack.popWord();
	mP = true;
	break;
case 0xCA:
	if((F & ZF) != 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xCC:
	if((F & ZF) != 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xCD:
	Stack.pushWord(PC + 3);
	PC = getMemoryWord();
	mP = true;
	break;
case 0xCE:
{
	uint8_t M_B = getMemoryByte();
	ALU.ADC_B(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xCF:
	Stack.pushWord(PC + 1);
	PC = 0x08;
	mP = true;
	break;
case 0xD0:
	if((F & CF) == 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xD1:
	DE[M_REGISTER] = Stack.popWord();
	break;
case 0xD2:
	if((F & CF) == 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xD3:
	//writeBus(A, getMemoryByte());
	//std::exit(0);
	break;
case 0xD4:
	if((F & CF) == 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xD5:
	Stack.pushWord(DE[M_REGISTER]);
	break;
case 0xD6:
{
	uint8_t M_B = getMemoryByte();
	ALU.SUB_B(A, M_B);
	break;
}
case 0xD7:
	Stack.pushWord(PC + 1);
	PC = 0x10;
	mP = true;
	break;
case 0xD8:
	if((F & CF) != 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xD9:
{
	uint16_t C_R = BC[M_REGISTER];
	B = (BC[S_REGISTER] >> 8);
	C = (BC[S_REGISTER] & BYTE_MASK);
	BC[S_REGISTER] = C_R;
	C_R = DE[M_REGISTER];
	D = (DE[S_REGISTER] >> 8);
	E = (DE[S_REGISTER] & BYTE_MASK);
	DE[S_REGISTER] = C_R;
	C_R = HL[M_REGISTER];
	H = (HL[S_REGISTER] >> 8);
	L = (HL[S_REGISTER] & BYTE_MASK);
	HL[S_REGISTER] = C_R;
	break;
}
case 0xDA:
	if((F & CF) != 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xDB:
	//A = BUS[getMemoryByte()];
	if(C == 2){
		std::cout << Memory.get()[E] << std::endl;
	}else if(C == 9){
		uint16_t Offset = 0;
		while(Memory.get()[DE[M_REGISTER] + Offset] != '$'){
			std::cout << Memory.get()[DE[M_REGISTER] + Offset];
			Offset += 1;
		}
		std::cout << std::endl;
	}
	break;
case 0xDC:
	if((F & CF) != 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xDE:
{
	uint8_t M_B = getMemoryByte();
	ALU.SBC_B(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xDF:
	Stack.pushWord(PC + 1);
	PC = 0x18;
	mP = true;
	break;
case 0xE0:
	if((F & PVF) != 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xE1:
	HL[M_REGISTER] = Stack.popWord();
	break;
case 0xE2:
	if((F & PVF) != 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xE3:
{
	uint8_t C_R = L;
	L = Memory.get()[Stack.getStackPointer()];
	Memory.get()[Stack.getStackPointer()] = C_R;
	C_R = H;
	H = Memory.get()[Stack.getStackPointer() + 1];
	Memory.get()[Stack.getStackPointer() + 1] = C_R;
	break;
}
case 0xE4:
	if((F & PVF) != 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xE5:
	Stack.pushWord(HL[M_REGISTER]);
	break;
case 0xE6:
{
	uint8_t M_B = getMemoryByte();
	ALU.AND(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xE7:
	Stack.pushWord(PC + 1);
	PC = 0x20;
	mP = true;
	break;
case 0xE8:
	if((F & PVF) == 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xE9:
	PC = Memory.get()[HL[M_REGISTER]];
	mP = true;
	break;
case 0xEA:
	if((F & PVF) == 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xEB:
{
	uint16_t C_R = HL[M_REGISTER];
	H = (BC[M_REGISTER] >> 8);
	L = (BC[M_REGISTER] & BYTE_MASK);
	B = (C_R >> 8);
	C = (C_R & BYTE_MASK);
	break;
}
case 0xEC:
	if((F & PVF) == 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xEE:
{
	uint8_t M_B = getMemoryByte();
	ALU.XOR(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xEF:
	Stack.pushWord(PC + 1);
	PC = 0x28;
	mP = true;
	break;
case 0xF0:
	if((F & PVF) != 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xF1:
	AF[M_REGISTER] = Stack.popWord();
	break;
case 0xF2:
	if((F & SF) == 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xF3:
	IFF1 = false;
	IFF2 = false;
	break;
case 0xF4:
	if((F & SF) == 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xF5:
	Stack.pushWord(AF[M_REGISTER]);
	break;
case 0xF6:
{
	uint8_t M_B = getMemoryByte();
	ALU.OR(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xF7:
	Stack.pushWord(PC + 1);
	PC = 0x30;
	mP = true;
	break;
case 0xF8:
	if((F & SF) != 0){
		PC = Stack.popWord();
		mP = true;
	}
	break;
case 0xF9:
	Stack.setStackPointer(HL[M_REGISTER]);
	break;
case 0xFA:
	if((F & SF) != 0){
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xFB:
	IFF1 = true;
	IFF2 = true;
	break;
case 0xFC:
	if((F & SF) != 0){
		Stack.pushWord(PC + 3);
		PC = getMemoryWord();
		mP = true;
	}
	break;
case 0xFE:
{
	uint8_t M_B = getMemoryByte();
	ALU.COMP(A, M_B);
	F = ALU.getFlags();
	break;
}
case 0xFF:
	Stack.pushWord(PC + 1);
	PC = 0x38;
	mP = true;
	break;
default:
	ExitStatus |= INVALID_OPCODE;
	break;

#endif /* Z80_INSTRUCTION_HANDLER_MAIN_H_ */

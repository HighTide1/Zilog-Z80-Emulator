//====================================================================================
// Name        : EXTENDED.h
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
// Description : Case File for Extended Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_EXTENDED_H_
#define Z80_INSTRUCTION_HANDLER_EXTENDED_H_

case 0x40:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	B = INP;
	break;
}
case 0x41:
	BUS[C] = B;
	break;
case 0x42:
	ALU.SBC_W(HL[M_REGISTER], BC[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x43:
	Memory.get()[getMemoryWord()] = BC[M_REGISTER];
	break;
case 0x44:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x45:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x46:
	CPUMode = M0;
	break;
case 0x47:
	I = A;
	break;
case 0x48:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	C = INP;
	break;
}
case 0x49:
	BUS[C] = C;
	break;
case 0x4A:
	ALU.ADC_W(HL[M_REGISTER], BC[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x4B:
	BC[M_REGISTER] = Memory.get()[getMemoryWord()];
	break;
case 0x4C:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x4D:
	PC = Stack.popWord();
	mP = true;
	break;
case 0x4E:
	//
	break;
case 0x4F:
	R = A;
	break;
case 0x50:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	D = INP;
	break;
}
case 0x51:
	BUS[C] = D;
	break;
case 0x52:
	ALU.SBC_W(HL[M_REGISTER], DE[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x53:
	Memory.get()[getMemoryWord()] = DE[M_REGISTER];
	break;
case 0x54:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x55:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x56:
	CPUMode = M1;
	break;
case 0x57:
	A = I;
	break;
case 0x58:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	E = INP;
	break;
}
case 0x59:
	BUS[C] = E;
	break;
case 0x5A:
	ALU.ADC_W(HL[M_REGISTER], DE[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x5B:
	DE[M_REGISTER] = Memory.get()[getMemoryWord()];
	break;
case 0x5C:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x5D:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x5E:
	CPUMode = M2;
	break;
case 0x5F:
	A = R;
	break;
case 0x60:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	H = INP;
	break;
}
case 0x61:
	BUS[C] = H;
	break;
case 0x62:
	ALU.SBC_W(HL[M_REGISTER], HL[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x63:
	Memory.get()[getMemoryWord()] = HL[M_REGISTER];
	break;
case 0x64:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x65:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x66:
	CPUMode = M0;
	break;
case 0x67:
{
	uint8_t L_M = (Memory.get()[HL[M_REGISTER]] & NIBBLE_MASK);
	uint8_t L_A = (A & NIBBLE_MASK);
	uint8_t H_M = (Memory.get()[HL[M_REGISTER]] >> NIBBLE_MASK);
	A = (A & (NIBBLE_MASK << 4)) | L_M;
	Memory.get()[HL[M_REGISTER]] = ((L_A << 4) | H_M);
	F = (ALU.CHECK(A) | (F & CF));
	F |= (~ALU.PARITY(A) << 2);
	break;
}
case 0x68:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	L = INP;
	break;
}
case 0x69:
	BUS[C] = L;
	break;
case 0x6A:
	ALU.ADC_W(HL[M_REGISTER], HL[M_REGISTER]);
	F = ALU.getFlags();
	break;
case 0x6B:
	HL[M_REGISTER] = Memory.get()[getMemoryWord()];
	break;
case 0x6C:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x6D:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x6E:
	//
	break;
case 0x6F:
{
	uint8_t L_M = (Memory.get()[HL[M_REGISTER]] & NIBBLE_MASK);
	uint8_t L_A = (A & NIBBLE_MASK);
	uint8_t H_M = (Memory.get()[HL[M_REGISTER]] >> NIBBLE_MASK);
	A = (A & (NIBBLE_MASK << 4)) | H_M;
	Memory.get()[HL[M_REGISTER]] = ((L_M << 4) | L_A);
	F = (ALU.CHECK(A) | (F & CF));
	F |= (~ALU.PARITY(A) << 2);
	break;
}
case 0x70:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	break;
}
case 0x71:
	BUS[C] = 0;
	break;
case 0x72:
	ALU.SBC_W(HL[M_REGISTER], SP);
	F = ALU.getFlags();
	break;
case 0x73:
	Memory.get()[getMemoryWord()] = Stack.getStackPointer();
	break;
case 0x74:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x75:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x76:
	CPUMode = M1;
	break;
case 0x78:
{
	uint8_t INP = BUS[C];
	F = (ALU.CHECK(INP) | (F & CF));
	F |= (ALU.PARITY(INP) << 2);
	A = INP;
	break;
}
case 0x79:
	BUS[C] = A;
	break;
case 0x7A:
	ALU.ADC_W(HL[M_REGISTER], SP);
	F = ALU.getFlags();
	break;
case 0x7B:
	Stack.setStackPointer(Memory.get()[getMemoryWord()]);
	break;
case 0x7C:
	ALU.NEG(A);
	F = ALU.getFlags();
	break;
case 0x7D:
	PC = Stack.popWord();
	mP = true;
	IFF1 = IFF2;
	break;
case 0x7E:
	CPUMode = M2;
	break;
case 0xA0:
	Memory.get()[DE[M_REGISTER]] = Memory.get()[HL[M_REGISTER]];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.INC_W(DE[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	if(BC[M_REGISTER] != 0){
		F |= PVF;
	}else{
		F &= ~PVF;
	}
	F &= ~HF;
	F &= ~NF;
	break;
case 0xA1:
	ALU.COMP(A, Memory.get()[HL[M_REGISTER]]);
	F = (ALU.getFlags() | (F & CF));
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	if(BC[M_REGISTER] != 0){
		F |= PVF;
	}else{
		F &= ~PVF;
	}
	F |= NF;
	break;
case 0xA2:
	Memory.get()[HL[M_REGISTER]] = BUS[C];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = (NF & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	break;
case 0xA3:
	BUS[C] = Memory.get()[HL[M_REGISTER]];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = (NF & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	break;
case 0xA8:
	Memory.get()[DE[M_REGISTER]] = Memory.get()[HL[M_REGISTER]];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_W(DE[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	if(BC[M_REGISTER] != 0){
		F |= PVF;
	}else{
		F &= ~PVF;
	}
	F &= ~HF;
	F &= ~NF;
	break;
case 0xA9:
	ALU.COMP(A, Memory.get()[HL[M_REGISTER]]);
	F = (ALU.getFlags() | (F & CF));
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	if(BC[M_REGISTER] != 0){
		F |= PVF;
	}else{
		F &= ~PVF;
	}
	F |= NF;
	break;
case 0xAA:
	Memory.get()[HL[M_REGISTER]] = BUS[C];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = NF;
	if(B == 0){
		F |= PVF;
	}
	break;
case 0xAB:
	BUS[C] = Memory.get()[HL[M_REGISTER]];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = NF;
	if(B == 0){
		F |= PVF;
	}
	break;
case 0xB0:
	Memory.get()[DE[M_REGISTER]] = Memory.get()[HL[M_REGISTER]];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.INC_W(DE[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	F = (F & (SF | ZF | CF));
	if(BC != 0){
		rI = true;
	}
	break;
case 0xB1:
	ALU.COMP(A, Memory.get()[HL[M_REGISTER]]);
	F = (ALU.getFlags() | (F & CF));
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	F &= ~PVF;
	F |= NF;
	if(BC != 0 && (F & ZF) == 0){
		rI = true;
	}
	break;
case 0xB2:
	Memory.get()[HL[M_REGISTER]] = BUS[C];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = ((NF | ZF) & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	if(B != 0){
		rI = true;
	}
	break;
case 0xB3:
	BUS[C] = Memory.get()[HL[M_REGISTER]];
	ALU.INC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = ((NF | ZF) & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	if(B != 0){
		rI = true;
	}
	break;
case 0xB8:
	Memory.get()[DE[M_REGISTER]] = Memory.get()[HL[M_REGISTER]];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_W(DE[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	F = (F & (SF | ZF | CF));
	if(BC != 0){
		rI = true;
	}
	break;
case 0xB9:
	ALU.COMP(A, Memory.get()[HL[M_REGISTER]]);
	F = (ALU.getFlags() | (F & CF));
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_W(BC[M_REGISTER]);
	F &= ~PVF;
	F |= NF;
	if(BC != 0 && (F & ZF) == 0){
		rI = true;
	}
	break;
case 0xBA:
	Memory.get()[HL[M_REGISTER]] = BUS[C];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = ((NF | ZF) & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	if(B != 0){
		rI = true;
	}
	break;
case 0xBB:
	BUS[C] = Memory.get()[HL[M_REGISTER]];
	ALU.DEC_W(HL[M_REGISTER]);
	ALU.DEC_B(B);
	F = ((NF | ZF) & (F & CF));
	if(B == 0){
		F |= PVF;
	}
	if(B != 0){
		rI = true;
	}
	break;
default:
	ExitStatus |= INVALID_OPCODE;
	break;

#endif /* Z80_INSTRUCTION_HANDLER_EXTENDED_H_ */

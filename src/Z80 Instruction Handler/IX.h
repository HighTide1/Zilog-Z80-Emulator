//====================================================================================
// Name        : IX.h
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
// Description : Case File for IX Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_IX_H_
#define Z80_INSTRUCTION_HANDLER_IX_H_

case 0x09:
	ALU.ADD_W(IX, BC[M_REGISTER]);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x19:
	ALU.ADD_W(IX, DE[M_REGISTER]);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x21:
	IX = getMemoryWord();
	break;
case 0x22:
	Memory.get()[getMemoryWord()] = IX;
	break;
case 0x23:
	ALU.INC_W(IX);
	F = ALU.getFlags();
	break;
case 0x24:
	ALU.INC_B(IXH);
	F = ALU.getFlags();
	break;
case 0x25:
	ALU.DEC_B(IXH);
	F = ALU.getFlags();
	break;
case 0x26:
	IXH = getMemoryByte();
	break;
case 0x29:
	ALU.ADD_W(IX, IX);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x2A:
	IX = Memory.get()[getMemoryWord()];
	break;
case 0x2B:
	ALU.DEC_W(IX);
	F = ALU.getFlags();
	break;
case 0x2C:
	ALU.INC_B(IXL);
	F = ALU.getFlags();
	break;
case 0x2D:
	ALU.DEC_B(IXL);
	F = ALU.getFlags();
	break;
case 0x2E:
	IXL = getMemoryByte();
	break;
case 0x34:
	ALU.INC_B(Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x35:
	ALU.DEC_B(Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x36:
	Memory.get()[IX + getMemoryByte()] = getMemoryByte();
	break;
case 0x39:
	ALU.ADD_W(IX, SP);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x44:
	B = IXH;
	break;
case 0x45:
	B = IXL;
	break;
case 0x46:
	B = Memory.get()[IX + getMemoryByte()];
	break;
case 0x4C:
	C = IXH;
	break;
case 0x4D:
	C = IXL;
	break;
case 0x4E:
	C = Memory.get()[IX + getMemoryByte()];
	break;
case 0x54:
	D = IXH;
	break;
case 0x55:
	D = IXL;
	break;
case 0x56:
	D = Memory.get()[IX + getMemoryByte()];
	break;
case 0x5C:
	E = IXH;
	break;
case 0x5D:
	E = IXL;
	break;
case 0x5E:
	E = Memory.get()[IX + getMemoryByte()];
	break;
case 0x60:
	IXH = B;
	break;
case 0x61:
	IXH = C;
	break;
case 0x62:
	IXH = D;
	break;
case 0x63:
	IXH = E;
	break;
case 0x64:
	//IXH = IXH;
	break;
case 0x65:
	IXH = IXL;
	break;
case 0x66:
	H = Memory.get()[IX + getMemoryByte()];
	break;
case 0x67:
	IXH = A;
	break;
case 0x68:
	IXL = B;
	break;
case 0x69:
	IXL = C;
	break;
case 0x6A:
	IXL = D;
	break;
case 0x6B:
	IXL = E;
	break;
case 0x6C:
	IXL = IXH;
	break;
case 0x6D:
	//IXL = IXL;
	break;
case 0x6E:
	L = Memory.get()[IX + getMemoryByte()];
	break;
case 0x6F:
	IXL = A;
	break;
case 0x70:
	Memory.get()[IX + getMemoryByte()] = B;
	break;
case 0x71:
	Memory.get()[IX + getMemoryByte()] = C;
	break;
case 0x72:
	Memory.get()[IX + getMemoryByte()] = D;
	break;
case 0x73:
	Memory.get()[IX + getMemoryByte()] = E;
	break;
case 0x74:
	Memory.get()[IX + getMemoryByte()] = H;
	break;
case 0x75:
	Memory.get()[IX + getMemoryByte()] = L;
	break;
case 0x77:
	Memory.get()[IX + getMemoryByte()] = A;
	break;
case 0x7C:
	A = IXH;
	break;
case 0x7D:
	A = IXL;
	break;
case 0x7E:
	A = Memory.get()[IX + getMemoryByte()];
	break;
case 0x84:
	ALU.ADD_B(A, IXH);
	F = ALU.getFlags();
	break;
case 0x85:
	ALU.ADD_B(A, IXL);
	F = ALU.getFlags();
	break;
case 0x86:
	ALU.ADD_B(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x8C:
	ALU.ADC_B(A, IXH);
	F = ALU.getFlags();
	break;
case 0x8D:
	ALU.ADC_B(A, IXL);
	F = ALU.getFlags();
	break;
case 0x8E:
	ALU.ADC_B(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x94:
	ALU.SUB_B(A, IXH);
	F = ALU.getFlags();
	break;
case 0x95:
	ALU.SUB_B(A, IXL);
	F = ALU.getFlags();
	break;
case 0x96:
	ALU.SUB_B(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x9C:
	ALU.SBC_B(A, IXH);
	F = ALU.getFlags();
	break;
case 0x9D:
	ALU.SBC_B(A, IXL);
	F = ALU.getFlags();
	break;
case 0x9E:
	ALU.SBC_B(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xA4:
	ALU.AND(A, IXH);
	F = ALU.getFlags();
	break;
case 0xA5:
	ALU.AND(A, IXL);
	F = ALU.getFlags();
	break;
case 0xA6:
	ALU.AND(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xAC:
	ALU.XOR(A, IXH);
	F = ALU.getFlags();
	break;
case 0xAD:
	ALU.XOR(A, IXL);
	F = ALU.getFlags();
	break;
case 0xAE:
	ALU.XOR(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xB4:
	ALU.OR(A, IXH);
	F = ALU.getFlags();
	break;
case 0xB5:
	ALU.OR(A, IXL);
	F = ALU.getFlags();
	break;
case 0xB6:
	ALU.OR(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xBC:
	ALU.COMP(A, IXH);
	F = ALU.getFlags();
	break;
case 0xBD:
	ALU.COMP(A, IXL);
	F = ALU.getFlags();
	break;
case 0xBE:
	ALU.COMP(A, Memory.get()[IX + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xE1:
	IXL = Stack.popByte();
	IXH = Stack.popByte();
	break;
case 0xE3:
{
	uint8_t C_R = IXL;
	IXL = Memory.get()[Stack.getStackPointer()];
	Memory.get()[Stack.getStackPointer()] = C_R;
	C_R = IXH;
	IXH = Memory.get()[Stack.getStackPointer() + 1];
	Memory.get()[Stack.getStackPointer() + 1] = C_R;
	break;
}
case 0xE5:
	Stack.pushWord(IX);
	break;
case 0xE9:
	PC = Memory.get()[IX];
	break;
case 0xF9:
	Stack.setStackPointer(IX);
	break;
default:
	ExitStatus |= INVALID_OPCODE;
	break;

#endif /* Z80_INSTRUCTION_HANDLER_IX_H_ */

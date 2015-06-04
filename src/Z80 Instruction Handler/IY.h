//====================================================================================
// Name        : IY.h
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
// Description : Case File for IY Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_IY_H_
#define Z80_INSTRUCTION_HANDLER_IY_H_

case 0x09:
	ALU.ADD_W(IY, BC[M_REGISTER]);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x19:
	ALU.ADD_W(IY, DE[M_REGISTER]);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x21:
	IY = getMemoryWord();
	break;
case 0x22:
{
	uint16_t ADDRESS = getMemoryWord();
	Memory.get()[ADDRESS] = IYL;
	Memory.get()[ADDRESS + 1] = IYH;
	break;
}
case 0x23:
	ALU.INC_W(IY);
	F = ALU.getFlags();
	break;
case 0x24:
	ALU.INC_B(IYH);
	F = ALU.getFlags();
	break;
case 0x25:
	ALU.DEC_B(IYH);
	F = ALU.getFlags();
	break;
case 0x26:
	IYH = getMemoryByte();
	break;
case 0x29:
	ALU.ADD_W(IY, IY);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x2A:
{
	uint16_t ADDRESS = getMemoryWord();
	IYL = Memory.get()[ADDRESS];
	IYH = Memory.get()[ADDRESS + 1];
	break;
}
case 0x2B:
	ALU.DEC_W(IY);
	F = ALU.getFlags();
	break;
case 0x2C:
	ALU.INC_B(IYL);
	F = ALU.getFlags();
	break;
case 0x2D:
	ALU.DEC_B(IYL);
	F = ALU.getFlags();
	break;
case 0x2E:
	IYL = getMemoryByte();
	break;
case 0x34:
	ALU.INC_B(Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x35:
	ALU.DEC_B(Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x36:
	Memory.get()[IY + getMemoryByte()] = getMemoryByte();
	break;
case 0x39:
	ALU.ADD_W(IY, SP);
	F = (ALU.getFlags() & (HF | CF)) | (F & (SF | ZF | PVF));
	break;
case 0x44:
	B = IYH;
	break;
case 0x45:
	B = IYL;
	break;
case 0x46:
	B = Memory.get()[IY + getMemoryByte()];
	break;
case 0x4C:
	C = IYH;
	break;
case 0x4D:
	C = IYL;
	break;
case 0x4E:
	C = Memory.get()[IY + getMemoryByte()];
	break;
case 0x54:
	D = IYH;
	break;
case 0x55:
	D = IYL;
	break;
case 0x56:
	D = Memory.get()[IY + getMemoryByte()];
	break;
case 0x5C:
	E = IYH;
	break;
case 0x5D:
	E = IYL;
	break;
case 0x5E:
	E = Memory.get()[IY + getMemoryByte()];
	break;
case 0x60:
	IYH = B;
	break;
case 0x61:
	IYH = C;
	break;
case 0x62:
	IYH = D;
	break;
case 0x63:
	IYH = E;
	break;
case 0x64:
	//IYH = IYH;
	break;
case 0x65:
	IYH = IYL;
	break;
case 0x66:
	H = Memory.get()[IY + getMemoryByte()];
	break;
case 0x67:
	IYH = A;
	break;
case 0x68:
	IYL = B;
	break;
case 0x69:
	IYL = C;
	break;
case 0x6A:
	IYL = D;
	break;
case 0x6B:
	IYL = E;
	break;
case 0x6C:
	IYL = IYH;
	break;
case 0x6D:
	//IYL = IYL;
	break;
case 0x6E:
	L = Memory.get()[IY + getMemoryByte()];
	break;
case 0x6F:
	IYL = A;
	break;
case 0x70:
	Memory.get()[IY + getMemoryByte()] = B;
	break;
case 0x71:
	Memory.get()[IY + getMemoryByte()] = C;
	break;
case 0x72:
	Memory.get()[IY + getMemoryByte()] = D;
	break;
case 0x73:
	Memory.get()[IY + getMemoryByte()] = E;
	break;
case 0x74:
	Memory.get()[IY + getMemoryByte()] = H;
	break;
case 0x75:
	Memory.get()[IY + getMemoryByte()] = L;
	break;
case 0x77:
	Memory.get()[IY + getMemoryByte()] = A;
	break;
case 0x7C:
	A = IYH;
	break;
case 0x7D:
	A = IYL;
	break;
case 0x7E:
	A = Memory.get()[IY + getMemoryByte()];
	break;
case 0x84:
	ALU.ADD_B(A, IYH);
	F = ALU.getFlags();
	break;
case 0x85:
	ALU.ADD_B(A, IYL);
	F = ALU.getFlags();
	break;
case 0x86:
	ALU.ADD_B(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x8C:
	ALU.ADC_B(A, IYH);
	F = ALU.getFlags();
	break;
case 0x8D:
	ALU.ADC_B(A, IYL);
	F = ALU.getFlags();
	break;
case 0x8E:
	ALU.ADC_B(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x94:
	ALU.SUB_B(A, IYH);
	F = ALU.getFlags();
	break;
case 0x95:
	ALU.SUB_B(A, IYL);
	F = ALU.getFlags();
	break;
case 0x96:
	ALU.SUB_B(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x9C:
	ALU.SBC_B(A, IYH);
	F = ALU.getFlags();
	break;
case 0x9D:
	ALU.SBC_B(A, IYL);
	F = ALU.getFlags();
	break;
case 0x9E:
	ALU.SBC_B(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xA4:
	ALU.AND(A, IYH);
	F = ALU.getFlags();
	break;
case 0xA5:
	ALU.AND(A, IYL);
	F = ALU.getFlags();
	break;
case 0xA6:
	ALU.AND(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xAC:
	ALU.XOR(A, IYH);
	F = ALU.getFlags();
	break;
case 0xAD:
	ALU.XOR(A, IYL);
	F = ALU.getFlags();
	break;
case 0xAE:
	ALU.XOR(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xB4:
	ALU.OR(A, IYH);
	F = ALU.getFlags();
	break;
case 0xB5:
	ALU.OR(A, IYL);
	F = ALU.getFlags();
	break;
case 0xB6:
	ALU.OR(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xBC:
	ALU.COMP(A, IYH);
	F = ALU.getFlags();
	break;
case 0xBD:
	ALU.COMP(A, IYL);
	F = ALU.getFlags();
	break;
case 0xBE:
	ALU.COMP(A, Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0xE1:
	IY = Stack.popWord();
	break;
case 0xE3:
{
	uint8_t C_R = IYL;
	IYL = Memory.get()[Stack.getStackPointer()];
	Memory.get()[Stack.getStackPointer()] = C_R;
	C_R = IYH;
	IYH = Memory.get()[Stack.getStackPointer() + 1];
	Memory.get()[Stack.getStackPointer() + 1] = C_R;
	break;
}
case 0xE5:
	Stack.pushWord(IY);
	break;
case 0xE9:
	PC = Memory.get()[IY];
	break;
case 0xF9:
	Stack.setStackPointer(IY);
	break;
default:
	ExitStatus |= INVALID_OPCODE;
	break;

#endif /* Z80_INSTRUCTION_HANDLER_IY_H_ */

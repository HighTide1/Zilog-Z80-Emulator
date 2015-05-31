//====================================================================================
// Name        : IY_BIT.h
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
// Description : Case File for IY Bit Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_IY_BIT_H_
#define Z80_INSTRUCTION_HANDLER_IY_BIT_H_

case 0x00:
	ALU.RLCB(C_R);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x01:
	ALU.RLCB(C_R);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x02:
	ALU.RLCB(C_R);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x03:
	ALU.RLCB(C_R);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x04:
	ALU.RLCB(C_R);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x05:
	ALU.RLCB(C_R);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x06:
	ALU.RLCB(Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x07:
	ALU.RLCB(C_R);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x08:
	ALU.RRCB(C_R);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x09:
	ALU.RRCB(C_R);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x0A:
	ALU.RRCB(C_R);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x0B:
	ALU.RRCB(C_R);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x0C:
	ALU.RRCB(C_R);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x0D:
	ALU.RRCB(C_R);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x0E:
	ALU.RRCB(Memory.get()[IY + O]);
	F = ALU.getFlags();
	break;
case 0x0F:
	ALU.RRCB(C_R);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x10:
	ALU.RLB(C_R);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x11:
	ALU.RLB(C_R);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x12:
	ALU.RLB(C_R);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x13:
	ALU.RLB(C_R);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x14:
	ALU.RLB(C_R);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x15:
	ALU.RLB(C_R);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x16:
	ALU.RLB(Memory.get()[IY + getMemoryByte()]);
	F = ALU.getFlags();
	break;
case 0x17:
	ALU.RLB(C_R);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x18:
	ALU.RRB(C_R);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x19:
	ALU.RRB(C_R);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x1A:
	ALU.RRB(C_R);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x1B:
	ALU.RRB(C_R);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x1C:
	ALU.RRB(C_R);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x1D:
	ALU.RRB(C_R);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x1E:
	ALU.RRB(Memory.get()[IY + O]);
	F = ALU.getFlags();
	break;
case 0x1F:
	ALU.RRB(C_R);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x20:
	ALU.SLA(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x21:
	ALU.SLA(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x22:
	ALU.SLA(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x23:
	ALU.SLA(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x24:
	ALU.SLA(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x25:
	ALU.SLA(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x26:
	ALU.SLA(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0x27:
	ALU.SLA(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x28:
	ALU.SRA(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x29:
	ALU.SRA(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x2A:
	ALU.SRA(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x2B:
	ALU.SRA(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x2C:
	ALU.SRA(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x2D:
	ALU.SRA(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x2E:
	ALU.SRA(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0x2F:
	ALU.SRA(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x30:
	ALU.SLL(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x31:
	ALU.SLL(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x32:
	ALU.SLL(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x33:
	ALU.SLL(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x34:
	ALU.SLL(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x35:
	ALU.SLL(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x36:
	ALU.SLL(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0x37:
	ALU.SLL(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x38:
	ALU.SRL(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x39:
	ALU.SRL(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x3A:
	ALU.SRL(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x3B:
	ALU.SRL(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x3C:
	ALU.SRL(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x3D:
	ALU.SRL(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x3E:
	ALU.SRL(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0x3F:
	ALU.SRL(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x40:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x41:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x42:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x43:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x44:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x45:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x46:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x47:
	ALU.BIT(C_R, 0);
	F = ALU.getFlags();
	break;
case 0x48:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x49:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4A:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4B:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4C:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4D:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4E:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x4F:
	ALU.BIT(C_R, 1);
	F = ALU.getFlags();
	break;
case 0x50:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x51:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x52:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x53:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x54:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x55:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x56:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x57:
	ALU.BIT(C_R, 2);
	F = ALU.getFlags();
	break;
case 0x58:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x59:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5A:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5B:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5C:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5D:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5E:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x5F:
	ALU.BIT(C_R, 3);
	F = ALU.getFlags();
	break;
case 0x60:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x61:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x62:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x63:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x64:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x65:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x66:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x67:
	ALU.BIT(C_R, 4);
	F = ALU.getFlags();
	break;
case 0x68:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x69:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6A:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6B:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6C:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6D:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6E:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x6F:
	ALU.BIT(C_R, 5);
	F = ALU.getFlags();
	break;
case 0x70:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x71:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x72:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x73:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x74:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x75:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x76:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x77:
	ALU.BIT(C_R, 6);
	F = ALU.getFlags();
	break;
case 0x78:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x79:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7A:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7B:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7C:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7D:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7E:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x7F:
	ALU.BIT(C_R, 7);
	F = ALU.getFlags();
	break;
case 0x80:
	ALU.RES(C_R, 0);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x81:
	ALU.RES(C_R, 0);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x82:
	ALU.RES(C_R, 0);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x83:
	ALU.RES(C_R, 0);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x84:
	ALU.RES(C_R, 0);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x85:
	ALU.RES(C_R, 0);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x86:
	ALU.RES(Memory.get()[IY + O], 0);
	F = ALU.getFlags();
	break;
case 0x87:
	ALU.RES(C_R, 0);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x88:
	ALU.RES(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x89:
	ALU.RES(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x8A:
	ALU.RES(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x8B:
	ALU.RES(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x8C:
	ALU.RES(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x8D:
	ALU.RES(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x8E:
	ALU.RES(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0x8F:
	ALU.RES(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x90:
	ALU.RES(C_R, 2);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x91:
	ALU.RES(C_R, 2);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x92:
	ALU.RES(C_R, 2);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x93:
	ALU.RES(C_R, 2);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x94:
	ALU.RES(C_R, 2);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x95:
	ALU.RES(C_R, 2);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x96:
	ALU.RES(Memory.get()[IY + O], 2);
	F = ALU.getFlags();
	break;
case 0x97:
	ALU.RES(C_R, 2);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0x98:
	ALU.RES(C_R, 3);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0x99:
	ALU.RES(C_R, 3);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0x9A:
	ALU.RES(C_R, 3);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0x9B:
	ALU.RES(C_R, 3);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0x9C:
	ALU.RES(C_R, 3);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0x9D:
	ALU.RES(C_R, 3);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0x9E:
	ALU.RES(Memory.get()[IY + O], 3);
	F = ALU.getFlags();
	break;
case 0x9F:
	ALU.RES(C_R, 3);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xA0:
	ALU.RES(C_R, 4);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xA1:
	ALU.RES(C_R, 4);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xA2:
	ALU.RES(C_R, 4);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xA3:
	ALU.RES(C_R, 4);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xA4:
	ALU.RES(C_R, 4);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xA5:
	ALU.RES(C_R, 4);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xA6:
	ALU.RES(Memory.get()[IY + O], 4);
	F = ALU.getFlags();
	break;
case 0xA7:
	ALU.RES(C_R, 4);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xA8:
	ALU.RES(C_R, 5);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xA9:
	ALU.RES(C_R, 5);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xAA:
	ALU.RES(C_R, 5);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xAB:
	ALU.RES(C_R, 5);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xAC:
	ALU.RES(C_R, 5);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xAD:
	ALU.RES(C_R, 5);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xAE:
	ALU.RES(Memory.get()[IY + O], 5);
	F = ALU.getFlags();
	break;
case 0xAF:
	ALU.RES(C_R, 5);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xB0:
	ALU.RES(C_R, 6);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xB1:
	ALU.RES(C_R, 6);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xB2:
	ALU.RES(C_R, 6);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xB3:
	ALU.RES(C_R, 6);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xB4:
	ALU.RES(C_R, 6);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xB5:
	ALU.RES(C_R, 6);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xB6:
	ALU.RES(Memory.get()[IY + O], 6);
	F = ALU.getFlags();
	break;
case 0xB7:
	ALU.RES(C_R, 6);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xB8:
	ALU.RES(C_R, 7);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xB9:
	ALU.RES(C_R, 7);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xBA:
	ALU.RES(C_R, 7);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xBB:
	ALU.RES(C_R, 7);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xBC:
	ALU.RES(C_R, 7);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xBD:
	ALU.RES(C_R, 7);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xBE:
	ALU.RES(Memory.get()[IY + O], 7);
	F = ALU.getFlags();
	break;
case 0xBF:
	ALU.RES(C_R, 7);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xC0:
	ALU.SET(C_R, 0);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xC1:
	ALU.SET(C_R, 0);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xC2:
	ALU.SET(C_R, 0);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xC3:
	ALU.SET(C_R, 0);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xC4:
	ALU.SET(C_R, 0);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xC5:
	ALU.SET(C_R, 0);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xC6:
	ALU.SET(Memory.get()[IY + O], 0);
	F = ALU.getFlags();
	break;
case 0xC7:
	ALU.SET(C_R, 0);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xC8:
	ALU.SET(C_R, 1);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xC9:
	ALU.SET(C_R, 1);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xCA:
	ALU.SET(C_R, 1);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xCB:
	ALU.SET(C_R, 1);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xCC:
	ALU.SET(C_R, 1);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xCD:
	ALU.SET(C_R, 1);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xCE:
	ALU.SET(Memory.get()[IY + O], 1);
	F = ALU.getFlags();
	break;
case 0xCF:
	ALU.SET(C_R, 1);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xD0:
	ALU.SET(C_R, 2);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xD1:
	ALU.SET(C_R, 2);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xD2:
	ALU.SET(C_R, 2);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xD3:
	ALU.SET(C_R, 2);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xD4:
	ALU.SET(C_R, 2);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xD5:
	ALU.SET(C_R, 2);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xD6:
	ALU.SET(Memory.get()[IY + O], 2);
	F = ALU.getFlags();
	break;
case 0xD7:
	ALU.SET(C_R, 2);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xD8:
	ALU.SET(C_R, 3);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xD9:
	ALU.SET(C_R, 3);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xDA:
	ALU.SET(C_R, 3);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xDB:
	ALU.SET(C_R, 3);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xDC:
	ALU.SET(C_R, 3);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xDD:
	ALU.SET(C_R, 3);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xDE:
	ALU.SET(Memory.get()[IY + O], 3);
	F = ALU.getFlags();
	break;
case 0xDF:
	ALU.SET(C_R, 3);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xE0:
	ALU.SET(C_R, 4);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xE1:
	ALU.SET(C_R, 4);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xE2:
	ALU.SET(C_R, 4);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xE3:
	ALU.SET(C_R, 4);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xE4:
	ALU.SET(C_R, 4);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xE5:
	ALU.SET(C_R, 4);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xE6:
	ALU.SET(Memory.get()[IY + O], 4);
	F = ALU.getFlags();
	break;
case 0xE7:
	ALU.SET(C_R, 4);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xE8:
	ALU.SET(C_R, 5);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xE9:
	ALU.SET(C_R, 5);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xEA:
	ALU.SET(C_R, 5);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xEB:
	ALU.SET(C_R, 5);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xEC:
	ALU.SET(C_R, 5);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xED:
	ALU.SET(C_R, 5);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xEE:
	ALU.SET(Memory.get()[IY + O], 5);
	F = ALU.getFlags();
	break;
case 0xEF:
	ALU.SET(C_R, 5);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xF0:
	ALU.SET(C_R, 6);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xF1:
	ALU.SET(C_R, 6);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xF2:
	ALU.SET(C_R, 6);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xF3:
	ALU.SET(C_R, 6);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xF4:
	ALU.SET(C_R, 6);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xF5:
	ALU.SET(C_R, 6);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xF6:
	ALU.SET(Memory.get()[IY + O], 6);
	F = ALU.getFlags();
	break;
case 0xF7:
	ALU.SET(C_R, 6);
	A = C_R;
	F = ALU.getFlags();
	break;
case 0xF8:
	ALU.SET(C_R, 7);
	B = C_R;
	F = ALU.getFlags();
	break;
case 0xF9:
	ALU.SET(C_R, 7);
	C = C_R;
	F = ALU.getFlags();
	break;
case 0xFA:
	ALU.SET(C_R, 7);
	D = C_R;
	F = ALU.getFlags();
	break;
case 0xFB:
	ALU.SET(C_R, 7);
	E = C_R;
	F = ALU.getFlags();
	break;
case 0xFC:
	ALU.SET(C_R, 7);
	H = C_R;
	F = ALU.getFlags();
	break;
case 0xFD:
	ALU.SET(C_R, 7);
	L = C_R;
	F = ALU.getFlags();
	break;
case 0xFE:
	ALU.SET(Memory.get()[IY + O], 7);
	F = ALU.getFlags();
	break;
case 0xFF:
	ALU.SET(C_R, 7);
	A = C_R;
	F = ALU.getFlags();
	break;

#endif /* Z80_INSTRUCTION_HANDLER_IY_BIT_H_ */

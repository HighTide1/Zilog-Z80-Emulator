//====================================================================================
// Name        : BIT.h
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
// Description : Case File for Main Bit Instructions
//====================================================================================
#ifndef Z80_INSTRUCTION_HANDLER_BIT_H_
#define Z80_INSTRUCTION_HANDLER_BIT_H_

case 0x00:
	ALU.RLCB(B);
	F = ALU.getFlags();
	break;
case 0x01:
	ALU.RLCB(C);
	F = ALU.getFlags();
	break;
case 0x02:
	ALU.RLCB(D);
	F = ALU.getFlags();
	break;
case 0x03:
	ALU.RLCB(E);
	F = ALU.getFlags();
	break;
case 0x04:
	ALU.RLCB(H);
	F = ALU.getFlags();
	break;
case 0x05:
	ALU.RLCB(L);
	F = ALU.getFlags();
	break;
case 0x06:
	ALU.RLCB(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x07:
	ALU.RLCB(A);
	F = ALU.getFlags();
	break;
case 0x08:
	ALU.RRCB(B);
	F = ALU.getFlags();
	break;
case 0x09:
	ALU.RRCB(C);
	F = ALU.getFlags();
	break;
case 0x0A:
	ALU.RRCB(D);
	F = ALU.getFlags();
	break;
case 0x0B:
	ALU.RRCB(E);
	F = ALU.getFlags();
	break;
case 0x0C:
	ALU.RRCB(H);
	F = ALU.getFlags();
	break;
case 0x0D:
	ALU.RRCB(L);
	F = ALU.getFlags();
	break;
case 0x0E:
	ALU.RRCB(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x0F:
	ALU.RRCB(A);
	F = ALU.getFlags();
	break;
case 0x10:
	ALU.RLB(B);
	F = ALU.getFlags();
	break;
case 0x11:
	ALU.RLB(C);
	F = ALU.getFlags();
	break;
case 0x12:
	ALU.RLB(D);
	F = ALU.getFlags();
	break;
case 0x13:
	ALU.RLB(E);
	F = ALU.getFlags();
	break;
case 0x14:
	ALU.RLB(H);
	F = ALU.getFlags();
	break;
case 0x15:
	ALU.RLB(L);
	F = ALU.getFlags();
	break;
case 0x16:
	ALU.RLB(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x17:
	ALU.RLB(A);
	F = ALU.getFlags();
	break;
case 0x18:
	ALU.RRB(B);
	F = ALU.getFlags();
	break;
case 0x19:
	ALU.RRB(C);
	F = ALU.getFlags();
	break;
case 0x1A:
	ALU.RRB(D);
	F = ALU.getFlags();
	break;
case 0x1B:
	ALU.RRB(E);
	F = ALU.getFlags();
	break;
case 0x1C:
	ALU.RRB(H);
	F = ALU.getFlags();
	break;
case 0x1D:
	ALU.RRB(L);
	F = ALU.getFlags();
	break;
case 0x1E:
	ALU.RRB(Memory.get()[HL[M_REGISTER]]);
	F = ALU.getFlags();
	break;
case 0x1F:
	ALU.RRB(A);
	F = ALU.getFlags();
	break;
case 0x20:
	ALU.SLA(B, 1);
	F = ALU.getFlags();
	break;
case 0x21:
	ALU.SLA(C, 1);
	F = ALU.getFlags();
	break;
case 0x22:
	ALU.SLA(D, 1);
	F = ALU.getFlags();
	break;
case 0x23:
	ALU.SLA(E, 1);
	F = ALU.getFlags();
	break;
case 0x24:
	ALU.SLA(H, 1);
	F = ALU.getFlags();
	break;
case 0x25:
	ALU.SLA(L, 1);
	F = ALU.getFlags();
	break;
case 0x26:
	ALU.SLA(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x27:
	ALU.SLA(A, 1);
	F = ALU.getFlags();
	break;
case 0x28:
	ALU.SRA(B, 1);
	F = ALU.getFlags();
	break;
case 0x29:
	ALU.SRA(C, 1);
	F = ALU.getFlags();
	break;
case 0x2A:
	ALU.SRA(D, 1);
	F = ALU.getFlags();
	break;
case 0x2B:
	ALU.SRA(E, 1);
	F = ALU.getFlags();
	break;
case 0x2C:
	ALU.SRA(H, 1);
	F = ALU.getFlags();
	break;
case 0x2D:
	ALU.SRA(L, 1);
	F = ALU.getFlags();
	break;
case 0x2E:
	ALU.SRA(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x2F:
	ALU.SRA(A, 1);
	F = ALU.getFlags();
	break;
case 0x30:
	ALU.SLL(B, 1);
	F = ALU.getFlags();
	break;
case 0x31:
	ALU.SLL(C, 1);
	F = ALU.getFlags();
	break;
case 0x32:
	ALU.SLL(D, 1);
	F = ALU.getFlags();
	break;
case 0x33:
	ALU.SLL(E, 1);
	F = ALU.getFlags();
	break;
case 0x34:
	ALU.SLL(H, 1);
	F = ALU.getFlags();
	break;
case 0x35:
	ALU.SLL(L, 1);
	F = ALU.getFlags();
	break;
case 0x36:
	ALU.SLL(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x37:
	ALU.SLL(A, 1);
	F = ALU.getFlags();
	break;
case 0x38:
	ALU.SRL(B, 1);
	F = ALU.getFlags();
	break;
case 0x39:
	ALU.SRL(C, 1);
	F = ALU.getFlags();
	break;
case 0x3A:
	ALU.SRL(D, 1);
	F = ALU.getFlags();
	break;
case 0x3B:
	ALU.SRL(E, 1);
	F = ALU.getFlags();
	break;
case 0x3C:
	ALU.SRL(H, 1);
	F = ALU.getFlags();
	break;
case 0x3D:
	ALU.SRL(L, 1);
	F = ALU.getFlags();
	break;
case 0x3E:
	ALU.SRL(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x3F:
	ALU.SRL(A, 0);
	F = ALU.getFlags();
	break;
case 0x40:
	ALU.BIT(B, 0);
	F = ALU.getFlags();
	break;
case 0x41:
	ALU.BIT(C, 0);
	F = ALU.getFlags();
	break;
case 0x42:
	ALU.BIT(D, 0);
	F = ALU.getFlags();
	break;
case 0x43:
	ALU.BIT(E, 0);
	F = ALU.getFlags();
	break;
case 0x44:
	ALU.BIT(H, 0);
	F = ALU.getFlags();
	break;
case 0x45:
	ALU.BIT(L, 0);
	F = ALU.getFlags();
	break;
case 0x46:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 0);
	F = ALU.getFlags();
	break;
case 0x47:
	ALU.BIT(A, 0);
	F = ALU.getFlags();
	break;
case 0x48:
	ALU.BIT(B, 1);
	F = ALU.getFlags();
	break;
case 0x49:
	ALU.BIT(C, 1);
	F = ALU.getFlags();
	break;
case 0x4A:
	ALU.BIT(D, 1);
	F = ALU.getFlags();
	break;
case 0x4B:
	ALU.BIT(E, 1);
	F = ALU.getFlags();
	break;
case 0x4C:
	ALU.BIT(H, 1);
	F = ALU.getFlags();
	break;
case 0x4D:
	ALU.BIT(L, 1);
	F = ALU.getFlags();
	break;
case 0x4E:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x4F:
	ALU.BIT(A, 1);
	F = ALU.getFlags();
	break;
case 0x50:
	ALU.BIT(B, 2);
	F = ALU.getFlags();
	break;
case 0x51:
	ALU.BIT(C, 2);
	F = ALU.getFlags();
	break;
case 0x52:
	ALU.BIT(D, 2);
	F = ALU.getFlags();
	break;
case 0x53:
	ALU.BIT(E, 2);
	F = ALU.getFlags();
	break;
case 0x54:
	ALU.BIT(H, 2);
	F = ALU.getFlags();
	break;
case 0x55:
	ALU.BIT(L, 2);
	F = ALU.getFlags();
	break;
case 0x56:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 2);
	F = ALU.getFlags();
	break;
case 0x57:
	ALU.BIT(A, 2);
	F = ALU.getFlags();
	break;
case 0x58:
	ALU.BIT(B, 3);
	F = ALU.getFlags();
	break;
case 0x59:
	ALU.BIT(C, 3);
	F = ALU.getFlags();
	break;
case 0x5A:
	ALU.BIT(D, 3);
	F = ALU.getFlags();
	break;
case 0x5B:
	ALU.BIT(E, 3);
	F = ALU.getFlags();
	break;
case 0x5C:
	ALU.BIT(H, 3);
	F = ALU.getFlags();
	break;
case 0x5D:
	ALU.BIT(L, 3);
	F = ALU.getFlags();
	break;
case 0x5E:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 3);
	F = ALU.getFlags();
	break;
case 0x5F:
	ALU.BIT(A, 3);
	F = ALU.getFlags();
	break;
case 0x60:
	ALU.BIT(B, 4);
	F = ALU.getFlags();
	break;
case 0x61:
	ALU.BIT(C, 4);
	F = ALU.getFlags();
	break;
case 0x62:
	ALU.BIT(D, 4);
	F = ALU.getFlags();
	break;
case 0x63:
	ALU.BIT(E, 4);
	F = ALU.getFlags();
	break;
case 0x64:
	ALU.BIT(H, 4);
	F = ALU.getFlags();
	break;
case 0x65:
	ALU.BIT(L, 4);
	F = ALU.getFlags();
	break;
case 0x66:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 4);
	F = ALU.getFlags();
	break;
case 0x67:
	ALU.BIT(A, 4);
	F = ALU.getFlags();
	break;
case 0x68:
	ALU.BIT(B, 5);
	F = ALU.getFlags();
	break;
case 0x69:
	ALU.BIT(C, 5);
	F = ALU.getFlags();
	break;
case 0x6A:
	ALU.BIT(D, 5);
	F = ALU.getFlags();
	break;
case 0x6B:
	ALU.BIT(E, 5);
	F = ALU.getFlags();
	break;
case 0x6C:
	ALU.BIT(H, 5);
	F = ALU.getFlags();
	break;
case 0x6D:
	ALU.BIT(L, 5);
	F = ALU.getFlags();
	break;
case 0x6E:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 5);
	F = ALU.getFlags();
	break;
case 0x6F:
	ALU.BIT(A, 5);
	F = ALU.getFlags();
	break;
case 0x70:
	ALU.BIT(B, 6);
	F = ALU.getFlags();
	break;
case 0x71:
	ALU.BIT(C, 6);
	F = ALU.getFlags();
	break;
case 0x72:
	ALU.BIT(D, 6);
	F = ALU.getFlags();
	break;
case 0x73:
	ALU.BIT(E, 6);
	F = ALU.getFlags();
	break;
case 0x74:
	ALU.BIT(H, 6);
	F = ALU.getFlags();
	break;
case 0x75:
	ALU.BIT(L, 6);
	F = ALU.getFlags();
	break;
case 0x76:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 6);
	F = ALU.getFlags();
	break;
case 0x77:
	ALU.BIT(A, 6);
	F = ALU.getFlags();
	break;
case 0x78:
	ALU.BIT(B, 7);
	F = ALU.getFlags();
	break;
case 0x79:
	ALU.BIT(C, 7);
	F = ALU.getFlags();
	break;
case 0x7A:
	ALU.BIT(D, 7);
	F = ALU.getFlags();
	break;
case 0x7B:
	ALU.BIT(E, 7);
	F = ALU.getFlags();
	break;
case 0x7C:
	ALU.BIT(H, 7);
	F = ALU.getFlags();
	break;
case 0x7D:
	ALU.BIT(L, 7);
	F = ALU.getFlags();
	break;
case 0x7E:
	ALU.BIT(Memory.get()[HL[M_REGISTER]], 7);
	F = ALU.getFlags();
	break;
case 0x7F:
	ALU.BIT(A, 7);
	F = ALU.getFlags();
	break;
case 0x80:
	ALU.RES(B, 0);
	F = ALU.getFlags();
	break;
case 0x81:
	ALU.RES(C, 0);
	F = ALU.getFlags();
	break;
case 0x82:
	ALU.RES(D, 0);
	F = ALU.getFlags();
	break;
case 0x83:
	ALU.RES(E, 0);
	F = ALU.getFlags();
	break;
case 0x84:
	ALU.RES(H, 0);
	F = ALU.getFlags();
	break;
case 0x85:
	ALU.RES(L, 0);
	F = ALU.getFlags();
	break;
case 0x86:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 0);
	F = ALU.getFlags();
	break;
case 0x87:
	ALU.RES(A, 0);
	F = ALU.getFlags();
	break;
case 0x88:
	ALU.RES(B, 1);
	F = ALU.getFlags();
	break;
case 0x89:
	ALU.RES(C, 1);
	F = ALU.getFlags();
	break;
case 0x8A:
	ALU.RES(D, 1);
	F = ALU.getFlags();
	break;
case 0x8B:
	ALU.RES(E, 1);
	F = ALU.getFlags();
	break;
case 0x8C:
	ALU.RES(H, 1);
	F = ALU.getFlags();
	break;
case 0x8D:
	ALU.RES(L, 1);
	F = ALU.getFlags();
	break;
case 0x8E:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0x8F:
	ALU.RES(A, 1);
	F = ALU.getFlags();
	break;
case 0x90:
	ALU.RES(B, 2);
	F = ALU.getFlags();
	break;
case 0x91:
	ALU.RES(C, 2);
	F = ALU.getFlags();
	break;
case 0x92:
	ALU.RES(D, 2);
	F = ALU.getFlags();
	break;
case 0x93:
	ALU.RES(E, 2);
	F = ALU.getFlags();
	break;
case 0x94:
	ALU.RES(H, 2);
	F = ALU.getFlags();
	break;
case 0x95:
	ALU.RES(L, 2);
	F = ALU.getFlags();
	break;
case 0x96:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 2);
	F = ALU.getFlags();
	break;
case 0x97:
	ALU.RES(A, 2);
	F = ALU.getFlags();
	break;
case 0x98:
	ALU.RES(B, 3);
	F = ALU.getFlags();
	break;
case 0x99:
	ALU.RES(C, 3);
	F = ALU.getFlags();
	break;
case 0x9A:
	ALU.RES(D, 3);
	F = ALU.getFlags();
	break;
case 0x9B:
	ALU.RES(E, 3);
	F = ALU.getFlags();
	break;
case 0x9C:
	ALU.RES(H, 3);
	F = ALU.getFlags();
	break;
case 0x9D:
	ALU.RES(L, 3);
	F = ALU.getFlags();
	break;
case 0x9E:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 3);
	F = ALU.getFlags();
	break;
case 0x9F:
	ALU.RES(A, 3);
	F = ALU.getFlags();
	break;
case 0xA0:
	ALU.RES(B, 4);
	F = ALU.getFlags();
	break;
case 0xA1:
	ALU.RES(C, 4);
	F = ALU.getFlags();
	break;
case 0xA2:
	ALU.RES(D, 4);
	F = ALU.getFlags();
	break;
case 0xA3:
	ALU.RES(E, 4);
	F = ALU.getFlags();
	break;
case 0xA4:
	ALU.RES(H, 4);
	F = ALU.getFlags();
	break;
case 0xA5:
	ALU.RES(L, 4);
	F = ALU.getFlags();
	break;
case 0xA6:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 4);
	F = ALU.getFlags();
	break;
case 0xA7:
	ALU.RES(A, 4);
	F = ALU.getFlags();
	break;
case 0xA8:
	ALU.RES(B, 5);
	F = ALU.getFlags();
	break;
case 0xA9:
	ALU.RES(C, 5);
	F = ALU.getFlags();
	break;
case 0xAA:
	ALU.RES(D, 5);
	F = ALU.getFlags();
	break;
case 0xAB:
	ALU.RES(E, 5);
	F = ALU.getFlags();
	break;
case 0xAC:
	ALU.RES(H, 5);
	F = ALU.getFlags();
	break;
case 0xAD:
	ALU.RES(L, 5);
	F = ALU.getFlags();
	break;
case 0xAE:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 5);
	F = ALU.getFlags();
	break;
case 0xAF:
	ALU.RES(A, 5);
	F = ALU.getFlags();
	break;
case 0xB0:
	ALU.RES(B, 6);
	F = ALU.getFlags();
	break;
case 0xB1:
	ALU.RES(C, 6);
	F = ALU.getFlags();
	break;
case 0xB2:
	ALU.RES(D, 6);
	F = ALU.getFlags();
	break;
case 0xB3:
	ALU.RES(E, 6);
	F = ALU.getFlags();
	break;
case 0xB4:
	ALU.RES(H, 6);
	F = ALU.getFlags();
	break;
case 0xB5:
	ALU.RES(L, 6);
	F = ALU.getFlags();
	break;
case 0xB6:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 6);
	F = ALU.getFlags();
	break;
case 0xB7:
	ALU.RES(A, 6);
	F = ALU.getFlags();
	break;
case 0xB8:
	ALU.RES(B, 7);
	F = ALU.getFlags();
	break;
case 0xB9:
	ALU.RES(C, 7);
	F = ALU.getFlags();
	break;
case 0xBA:
	ALU.RES(D, 7);
	F = ALU.getFlags();
	break;
case 0xBB:
	ALU.RES(E, 7);
	F = ALU.getFlags();
	break;
case 0xBC:
	ALU.RES(H, 7);
	F = ALU.getFlags();
	break;
case 0xBD:
	ALU.RES(L, 7);
	F = ALU.getFlags();
	break;
case 0xBE:
	ALU.RES(Memory.get()[HL[M_REGISTER]], 7);
	F = ALU.getFlags();
	break;
case 0xBF:
	ALU.RES(A, 7);
	F = ALU.getFlags();
	break;
case 0xC0:
	ALU.SET(B, 0);
	F = ALU.getFlags();
	break;
case 0xC1:
	ALU.SET(C, 0);
	F = ALU.getFlags();
	break;
case 0xC2:
	ALU.SET(D, 0);
	F = ALU.getFlags();
	break;
case 0xC3:
	ALU.SET(E, 0);
	F = ALU.getFlags();
	break;
case 0xC4:
	ALU.SET(H, 0);
	F = ALU.getFlags();
	break;
case 0xC5:
	ALU.SET(L, 0);
	F = ALU.getFlags();
	break;
case 0xC6:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 0);
	F = ALU.getFlags();
	break;
case 0xC7:
	ALU.SET(A, 0);
	F = ALU.getFlags();
	break;
case 0xC8:
	ALU.SET(B, 1);
	F = ALU.getFlags();
	break;
case 0xC9:
	ALU.SET(C, 1);
	F = ALU.getFlags();
	break;
case 0xCA:
	ALU.SET(D, 1);
	F = ALU.getFlags();
	break;
case 0xCB:
	ALU.SET(E, 1);
	F = ALU.getFlags();
	break;
case 0xCC:
	ALU.SET(H, 1);
	F = ALU.getFlags();
	break;
case 0xCD:
	ALU.SET(L, 1);
	F = ALU.getFlags();
	break;
case 0xCE:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 1);
	F = ALU.getFlags();
	break;
case 0xCF:
	ALU.SET(A, 1);
	F = ALU.getFlags();
	break;
case 0xD0:
	ALU.SET(B, 2);
	F = ALU.getFlags();
	break;
case 0xD1:
	ALU.SET(C, 2);
	F = ALU.getFlags();
	break;
case 0xD2:
	ALU.SET(D, 2);
	F = ALU.getFlags();
	break;
case 0xD3:
	ALU.SET(E, 2);
	F = ALU.getFlags();
	break;
case 0xD4:
	ALU.SET(H, 2);
	F = ALU.getFlags();
	break;
case 0xD5:
	ALU.SET(L, 2);
	F = ALU.getFlags();
	break;
case 0xD6:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 2);
	F = ALU.getFlags();
	break;
case 0xD7:
	ALU.SET(A, 2);
	F = ALU.getFlags();
	break;
case 0xD8:
	ALU.SET(B, 3);
	F = ALU.getFlags();
	break;
case 0xD9:
	ALU.SET(C, 3);
	F = ALU.getFlags();
	break;
case 0xDA:
	ALU.SET(D, 3);
	F = ALU.getFlags();
	break;
case 0xDB:
	ALU.SET(E, 3);
	F = ALU.getFlags();
	break;
case 0xDC:
	ALU.SET(H, 3);
	F = ALU.getFlags();
	break;
case 0xDD:
	ALU.SET(L, 3);
	F = ALU.getFlags();
	break;
case 0xDE:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 3);
	F = ALU.getFlags();
	break;
case 0xDF:
	ALU.SET(A, 3);
	F = ALU.getFlags();
	break;
case 0xE0:
	ALU.SET(B, 4);
	F = ALU.getFlags();
	break;
case 0xE1:
	ALU.SET(C, 4);
	F = ALU.getFlags();
	break;
case 0xE2:
	ALU.SET(D, 4);
	F = ALU.getFlags();
	break;
case 0xE3:
	ALU.SET(E, 4);
	F = ALU.getFlags();
	break;
case 0xE4:
	ALU.SET(H, 4);
	F = ALU.getFlags();
	break;
case 0xE5:
	ALU.SET(L, 4);
	F = ALU.getFlags();
	break;
case 0xE6:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 4);
	F = ALU.getFlags();
	break;
case 0xE7:
	ALU.SET(A, 4);
	F = ALU.getFlags();
	break;
case 0xE8:
	ALU.SET(B, 5);
	F = ALU.getFlags();
	break;
case 0xE9:
	ALU.SET(C, 5);
	F = ALU.getFlags();
	break;
case 0xEA:
	ALU.SET(D, 5);
	F = ALU.getFlags();
	break;
case 0xEB:
	ALU.SET(E, 5);
	F = ALU.getFlags();
	break;
case 0xEC:
	ALU.SET(H, 5);
	F = ALU.getFlags();
	break;
case 0xED:
	ALU.SET(L, 5);
	F = ALU.getFlags();
	break;
case 0xEE:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 5);
	F = ALU.getFlags();
	break;
case 0xEF:
	ALU.SET(A, 5);
	F = ALU.getFlags();
	break;
case 0xF0:
	ALU.SET(B, 6);
	F = ALU.getFlags();
	break;
case 0xF1:
	ALU.SET(C, 6);
	F = ALU.getFlags();
	break;
case 0xF2:
	ALU.SET(D, 6);
	F = ALU.getFlags();
	break;
case 0xF3:
	ALU.SET(E, 6);
	F = ALU.getFlags();
	break;
case 0xF4:
	ALU.SET(H, 6);
	F = ALU.getFlags();
	break;
case 0xF5:
	ALU.SET(L, 6);
	F = ALU.getFlags();
	break;
case 0xF6:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 6);
	F = ALU.getFlags();
	break;
case 0xF7:
	ALU.SET(A, 6);
	F = ALU.getFlags();
	break;
case 0xF8:
	ALU.SET(B, 7);
	F = ALU.getFlags();
	break;
case 0xF9:
	ALU.SET(C, 7);
	F = ALU.getFlags();
	break;
case 0xFA:
	ALU.SET(D, 7);
	F = ALU.getFlags();
	break;
case 0xFB:
	ALU.SET(E, 7);
	F = ALU.getFlags();
	break;
case 0xFC:
	ALU.SET(H, 7);
	F = ALU.getFlags();
	break;
case 0xFD:
	ALU.SET(L, 7);
	F = ALU.getFlags();
	break;
case 0xFE:
	ALU.SET(Memory.get()[HL[M_REGISTER]], 7);
	F = ALU.getFlags();
	break;
case 0xFF:
	ALU.SET(A, 7);
	F = ALU.getFlags();
	break;

#endif /* Z80_INSTRUCTION_HANDLER_BIT_H_ */

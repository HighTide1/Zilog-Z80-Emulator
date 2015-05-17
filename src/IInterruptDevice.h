//====================================================================================
// Name        : IInterruptDevice.h
// Author      : Jered Tupik
// Version     : 1.0	5/15/2015
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
// Description : Interface File for the InterruptDevice Abstract Class/Interface
//====================================================================================
#ifndef IINTERRUPTDEVICE_H_
#define IINTERRUPTDEVICE_H_

class IInterruptDevice{
	public:

		virtual ~IInterruptDevice() {}

		virtual uint8_t PollDevice() 	  = 0;
		virtual bool 	isNonMaskable()   =	0;
};

#endif /* IINTERRUPTDEVICE_H_ */

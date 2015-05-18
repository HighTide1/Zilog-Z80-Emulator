//====================================================================================
// Name        : InterruptMonitor.h
// Author      : Jered Tupik
// Version     : 1.0	5/17/2015
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
// Description : Definition file of the InterruptMonitor for the Z80.
//====================================================================================
#ifndef INTERRUPTMONITOR_H_
#define INTERRUPTMONITOR_H_

#include <thread>
#include <vector>

#include "IInterruptDevice.h"
#include "Z80Defines.h"

class InterruptMonitor{
	private:
		//Devices to monitor for interrupts.
		std::vector<IInterruptDevice*> ConnectedDevices;

		//Last unprocessed Interrupt Code
		uint16_t InterruptCode = 0;

		//Interrupt Process Status
		bool processedInterrupt = false;

		//Interrupt Monitoring Thread
		std::thread InterruptPoller;

		//InterruptPoller method for monitoring devices
		void processDevices(uint16_t);
	public:
		InterruptMonitor();
		InterruptMonitor(std::vector<IInterruptDevice*>&);
		~InterruptMonitor();

		void addDevice(IInterruptDevice*);

		uint16_t processInterrupt();

		void stopInterruptMonitor();
};

#endif /* INTERRUPTMONITOR_H_ */

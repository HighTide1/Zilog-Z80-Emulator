//====================================================================================
// Name        : InterruptMonitor.cpp
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
// Description : CPP file of the InterruptMonitor for the Z80.
//====================================================================================
#include "InterruptMonitor.h"

//Constructors / Destructors
InterruptMonitor::InterruptMonitor(){
	ConnectedDevices = std::vector<IInterruptDevice*>();
	InterruptPoller = std::thread(&InterruptMonitor::processDevices, this, 100);
}

InterruptMonitor::InterruptMonitor(std::vector<IInterruptDevice*>& Devices){
	ConnectedDevices = Devices;
	InterruptPoller = std::thread(&InterruptMonitor::processDevices, this, 100);
}

InterruptMonitor::~InterruptMonitor(){
	this->stopInterruptMonitor();
}

/**
 * InterruptPoller method for monitoring the devices
 * in ConnectedDevices. Will continuosly poll the
 * connected devices and records the first-encountered
 * non-processed interrupt code.
 *
 * The interrupt-code recorded is stored in the following
 * format: INTERRUPT_TYPE (Most Significant Byte), INTERRUPT_
 * CODE(Least Significant Byte)
 *
 * Parameters:	Delay - The Delay between polling.
 */
void InterruptMonitor::processDevices(uint16_t Delay){
	while(true){
		for(auto i = ConnectedDevices.begin(); i != ConnectedDevices.end(); i++){
			uint8_t Interrupt = (*i)->PollDevice();
			if(Interrupt != 0 && processedInterrupt){
				if((*i)->isNonMaskable()){
					InterruptCode = (INTERRUPT_NMSK << 8) | Interrupt;
				}else{
					InterruptCode = (INTERRUPT_MASK << 8) | Interrupt;
				}
				processedInterrupt = false;
			}
			std::this_thread::sleep_for(std::chrono::nanoseconds(Delay));
		}
		std::this_thread::sleep_for(std::chrono::nanoseconds(Delay));
	}
}

/**
 * Returns the last unprocessed interrupt encountered in
 * ConnectedDevices.
 */
uint16_t InterruptMonitor::processInterrupt(){
	processedInterrupt = true;
	uint16_t lastInterrupt = InterruptCode;
	InterruptCode = INTERRUPT_NONE;
	return lastInterrupt;
}

/**
 * Stops the InterruptPoller thread, thus killing the
 * InterruptMonitor.
 */
void InterruptMonitor::stopInterruptMonitor(){
	if(InterruptPoller.joinable()){
		InterruptPoller.join();
	}
}

/**
 * Adds the Device to the ConnectedDevices list
 *
 * Parameters:		Device - The IInterruptDevice
 * 					to add to ConnectedDevices
 */
void InterruptMonitor::addDevice(IInterruptDevice* Device){
	ConnectedDevices.push_back(Device);
}

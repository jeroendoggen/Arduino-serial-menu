// SerialConfigMenu.h - Library to show a menu over the serial port
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
// 
// Version History:
//   Version 0.1: Print a line, print a menu
// Roadmap:
//  Version 0.2: ??
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef SerialConfigMenu_h
#define SerialConfigMenu_h

#include <defines.h>
#include <Arduino.h>

class SerialConfigMenu
{
  public:
	SerialConfigMenu();

	void begin();
	void begin(long speed);
	
	void show();						// Show the default menu
	void show(char name);				// Show a specific menu
	void getLine(uint8_t stringIndex);	// Fetch a line from PROGMEM
	void printLine(uint8_t line);
	void goHome();
	void clearScreen();

  private:
	char _buffer[TEXT_BUFFER_SIZE];		// Buffer to hold the line of text
};
#endif
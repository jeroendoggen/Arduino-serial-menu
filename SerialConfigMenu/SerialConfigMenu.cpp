// SerialConfigMenu.cpp - Library to show a menu over the serial port
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//  For more information: variable declaration, changelog,... see SerialConfigMenu.h
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


/// <summary>
/// SerialConfigMenu.cpp - Library to show a menu over the serial port
/// For more information: variable declaration, changelog,... see SerialConfigMenu.h
/// </summary>

#include <SerialConfigMenu.h>

// Strings stored in Program memory
prog_char s_MENU_LINE0[] PROGMEM = "+---------------------------+" ;   // re-use this line where needed 
prog_char s_MENU_LINE1[] PROGMEM = "| My Module: Configuration  |" ; 
prog_char s_MENU_LINE2[] PROGMEM = "|  1. Set Option 1          |" ; 
prog_char s_MENU_LINE3[] PROGMEM = "|  2. Set Option 2          |" ; 
prog_char s_MENU_LINE4[] PROGMEM = "|  3. Set Option 3          |" ; 
prog_char s_MENU_LINE5[] PROGMEM = "|  3. Set Option 4          |" ; 
prog_char s_MENU_LINE6[] PROGMEM = "|  3. Set Option 5          |" ; 
prog_char s_MENU_LINE7[] PROGMEM = "|  3. Set Option 6          |" ; 
prog_char s_MENU_LINE8[] PROGMEM = "|                           |" ; 
prog_char s_MENU_LINE9[] PROGMEM = "|  Settings OK              |" ; 



// String Table in Program space
PROGMEM const char *ConfigMenu_string_table[] = 	   
{ 
  // 0-based index, see list above.  
  s_MENU_LINE0,
  s_MENU_LINE1,
  s_MENU_LINE2,
  s_MENU_LINE3,
  s_MENU_LINE4,
  s_MENU_LINE5,
  s_MENU_LINE6,
  s_MENU_LINE7,
  s_MENU_LINE8,
  s_MENU_LINE9,
};

/// <summary>
/// Constructor
/// </summary>
SerialConfigMenu::SerialConfigMenu()
{
}

/// <summary>
/// Begin variables: default value for serial speed: 115200
/// </summary>
void SerialConfigMenu::begin()
{
	begin (115200);
}

/// <summary>
/// Begin using custom speed settings for the serial port
/// </summary>
void SerialConfigMenu::begin(long speed)
{
	Serial.begin(speed);
}

/// <summary>
/// Show menu empty menu
/// </summary>
void SerialConfigMenu::show()
{
	show('e');
}

/// <summary>
/// Show menu: specify a menu name: d -> default, e -> empty
/// </summary>
void SerialConfigMenu::show(char name)
{
	if(name == 'd'){ 
		printLine(MENU_HORIZONTAL_LINE);
		printLine(MENU_TITLE);
		printLine(MENU_HORIZONTAL_LINE);
		printLine(MENU_OPTION1);
		printLine(MENU_OPTION2);
		printLine(MENU_OPTION3);
		printLine(MENU_OPTION4);
		printLine(MENU_HORIZONTAL_LINE);
	}
	
	if(name == 'e'){ 
		printLine(MENU_HORIZONTAL_LINE);
		printLine(MENU_TITLE);
		printLine(MENU_HORIZONTAL_LINE);
		printLine(MENU_EMPTY);
		printLine(MENU_EMPTY);
		printLine(MENU_EMPTY);
		printLine(MENU_EMPTY);
		printLine(MENU_HORIZONTAL_LINE);
	}
	goHome();
}

/// <summary>
/// Print one line of text on the terminal window
/// </summary>
void SerialConfigMenu::printLine(uint8_t line)
{
	getLine(line);
	Serial.println(_buffer);
}

/// <summary>
/// Get one line of text from the program memory and put it into the buffer
/// </summary>
void SerialConfigMenu::getLine(uint8_t stringIndex)
{
	strcpy_P(_buffer, (char*)pgm_read_word(&(ConfigMenu_string_table[stringIndex]))); // Necessary casts and dereferencing, just copy. 
}

/// <summary>
/// Place the cursor in the beginning of the serial window
/// </summary>
void SerialConfigMenu::goHome()
{
	Serial.write(27); // ESC
	Serial.print("[H"); // cursor to home
}

/// <summary>
/// Clear the serial port window
/// </summary>
void SerialConfigMenu::clearScreen()
{
	Serial.write(27); // ESC
	Serial.print("[2J"); // clear screen
}


// SerialConfigMenu.ino - Demo application to show a configuration menu
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
// 
// Info:
//		- All strings are stored in program memory to save RAM
//		- 
// Program flow:
//		- Menu text is read from PROGMEM
//		- Menu is shown over the serial port

#include <SerialConfigMenu.h>

SerialConfigMenu Menu;
int temp;

void setup()
{
	Menu.begin(115200);
	Menu.show('d');
	delay(10); //wait for the menu to print
}

void loop()
{
	Menu.readLine();
	Menu.printLine();
}
// SerialConfigMenu.ino - Demo application to show a configuration menu: selection example
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Info:
//      - All strings are stored in program memory to save RAM
//
// Program flow:
//      - Default menu is shown over the serial port
//      - The user types a character to select an option (0, 1 or 2)
//      - A text in printed in the menu (showing the selection)

#include <SerialConfigMenu.h>
SerialConfigMenu Menu;

void setup()
{
  Menu.begin(115200);
  Menu.show('d');
  delay(10);                                      //wait for the menu to print
}

void loop()
{
  Menu.readChar();
  Menu.show('s');
  delay(100);
}

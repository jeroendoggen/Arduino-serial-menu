// Menu_ReadLine.ino - Demo application to show a configuration menu: readline example
// Copyright 2012-2013 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Info:
//      - All strings are stored in program memory to save RAM
//
// Program flow:
//      - Default menu is shown over the serial port
//      - The user types a line of text, ending with an ENTER
//      - A text in printed in the menu (showing the line of text and the line length)

#include <SerialMenu.h>
SerialMenu Menu;

void setup()
{
  Menu.begin(115200);
  Menu.show('d');
  delay(10);                                      //wait for the menu to print
}

void loop()
{
  Menu.readLine();
  Menu.show('l');
  delay(100);
}

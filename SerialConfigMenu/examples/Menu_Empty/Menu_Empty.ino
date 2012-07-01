// SerialConfigMenu.ino - Demo application to show a configuration menu: empty menu example
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Info:
//      - All strings are stored in program memory to save RAM
//
// Program flow:
//      - Empty menu is shown over the serial port

#include <SerialConfigMenu.h>
SerialConfigMenu Menu;

void setup()
{
  Menu.begin(115200);
}

void loop()
{
  Menu.show('e');                                 // empty menu
  delay(1000);                                    // wait for 1 second
}

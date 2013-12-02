// Menu_empty.ino - Demo application to show a configuration menu: empty menu example
// Copyright 2012-2013 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Info:
//      - All strings are stored in program memory to save RAM
//
// Program flow:
//      - Empty menu is shown over the serial port

#include <SerialMenu.h>
SerialMenu Menu;

void setup()
{
  Menu.begin(115200);
}

void loop()
{
  Menu.show('e');                                 // empty menu
  delay(1000);                                    // wait for 1 second
}

// SerialConfigMenu.h - Library for configuration a menus over the serial port
// Copyright 2012 Jeroen Doggen (jeroendoggen@gmail.com)
//
// Version History:
//   Version 0.1: Print a line, print a menu
//   Version 0.2: Read a char & print it in the menu
//   Version 0.3: Read a line & print it in the menu
// Roadmap:
//  Version 0.4: ??
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
    SerialConfigMenu ();                          // Constructor

    void begin ();                                // Begin using default serial speed: 115200
    void begin (long speed);                      // Begin using custom serial speed
    void show ();                                 // Show the default menu
    void show (char name);                        // Show a specific menu
    void getLine (uint8_t stringIndex);           // Fetch a line from PROGMEM
    void printLine (uint8_t line);                // Print a line from PROGMEM
    void goHome ();                               // Place the cursor in the beginning of the terminal
    void clearScreen ();                          // Clear screen
    char readChar ();                             // Read one character from the serial port buffer
    char readCharBlocking ();                     // Read one character from the serial port buffer (blocking)
    void readLine ();                             // Read one line from the serial port (until ENTER)
    void printLine ();                            // Print a line of text that was typed by the user

  private:
    char _buffer[TEXT_BUFFER_SIZE];               // Buffer to hold the line of text coming from PROGMEM
    char _incomingByte;                           // Incoming byte (over the serial port)
    char _incomingLine[LINE_LENGTH];              // Incoming line (over the serial port)
    uint8_t _lineLength;                          // Length of the incoming line (including the ENTER character)
};
#endif

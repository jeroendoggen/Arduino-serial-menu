// SerialMenu.h - Library for configuration a menus over the serial port
// Copyright 2012-2013 Jeroen Doggen (jeroendoggen@gmail.com)

#ifndef SerialMenu_h
#define SerialMenu_h

#include <defines.h>
#include <Arduino.h>

class SerialMenu
{
  public:
    SerialMenu ();                          // Constructor

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

# Arduino Serial Menu

Arduino library to show configuration menus over the serial port

## Usage:
 1. Download the source
 2. Place the SerialConfigMenu folder in your Arduino1.0+ "libraries" folder
 3. Open an example sketch: "file", "Examples", "SerialConfigMenu", "Menu_Default" or "MenuEmpty"
 4. Compile & upload code
 5. Monitor the serial port with minicom or any other 'real' terminal monitor (not the default Arduino serial monitor) (startup: "minicom -o")

## How it works:
 * The 'strings' for the menu are placed in PROGMEM to minimize RAM usage
 * Every 'menu' is just a collection of these 'strings'
 * After the menu is printed, the cursor returns to the first line
 * When the menu is printed again (when the loop restarts), exactly the same text is printed again, giving the impression of a static menu.

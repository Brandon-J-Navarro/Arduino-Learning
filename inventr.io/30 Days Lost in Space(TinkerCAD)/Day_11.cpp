// C++ code
//

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte ROW_PINS[ROWS] = {9, 8, 7, 6};
byte COL_PINS[COLS] = {5, 4, 3, 2};

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char pressedButton = heroKeypad.waitForKey();
  
  Serial.println(pressedButton);
}

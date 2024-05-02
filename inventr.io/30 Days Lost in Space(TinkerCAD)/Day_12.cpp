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

const unsigned int TONE[ROWS][COLS] = {
  { 31, 93, 147, 208 },
  { 247, 311, 370, 440 },
  { 523, 587, 698, 880 },
  { 1397, 2637, 3729, 0 }
};

const byte BUZZER_PIN = 10;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char pressedButton = heroKeypad.waitForKey();
  
  unsigned int tone_frequency = 0;
  
  for(byte i = 0; i < ROWS; i++) {
    for(byte j = 0; j < COLS; j++){
      if(pressedButton == BUTTONS[i][j]){
        tone_frequency = TONE[i][j];
      }
    }
  }
  Serial.print("Key: ");
  Serial.println(pressedButton);
  Serial.print("Freq: ");
  Serial.println(tone_frequency);
  
  if(tone_frequency > 0) {
    tone(BUZZER_PIN, tone_frequency);
  } else {
    Serial.println("stop tone");
    noTone(BUZZER_PIN);
  }
}

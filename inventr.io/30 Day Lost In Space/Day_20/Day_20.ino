// C++ code
//

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte ROW_PINS[ROWS] = {13, 12, 11, 9};
byte COL_PINS[COLS] = {8, 7, 6, 5};

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

Adafruit_7segment lander_display = Adafruit_7segment();

const byte BUZZER_PIN = 10;

const unsigned int LOOP_DELAY = 1000;

const byte all_on = 0b11111111;

int display = 0;
char inputCharacter[4];

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);

  lander_display.begin(0x70);
  lander_display.setBrightness(15);
  lander_display.writeDisplay();
}

void loop()
{
  char button_character = heroKeypad.waitForKey();
  if (button_character == '#'){
    programDisplay();
  }
  if (display != 0){
    countDown();
  }
}

void allOn() {
  lander_display.clear();
  lander_display.writeDisplay();
  
  lander_display.writeDigitRaw(0,all_on);
  lander_display.writeDigitRaw(1,all_on);
  lander_display.writeDigitRaw(2,all_on);
  lander_display.writeDigitRaw(3,all_on);
  lander_display.writeDigitRaw(4,all_on);
  lander_display.writeDisplay();
  
  delay(1000);
  
  lander_display.clear();
  lander_display.writeDisplay();
}


char programDisplay() {
  for (int i = 0; i < 4; i++){
    char input_character = heroKeypad.waitForKey();
    inputCharacter[i] = input_character;
    if(input_character == '#'){
      display = atoi(inputCharacter);
      return display;
    }
  }
  display = atoi(inputCharacter);
  return display;
}

void countDown() {
  for (int i = 0; i < display; i++){
    display--;
    lander_display.print(display);
    lander_display.writeDisplay();
    delay(LOOP_DELAY);
    if (display == 0){
      for (int i = 0; i < 4; i++){ 
        allOn();
        tone(BUZZER_PIN, 800, 100);
        delay(LOOP_DELAY);
      }
    }
  }
}

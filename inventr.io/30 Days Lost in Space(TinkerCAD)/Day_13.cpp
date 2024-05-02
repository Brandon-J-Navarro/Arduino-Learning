// C++ code
//

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PIN_LENGTH = 4;
char current_pin[PIN_LENGTH] =  { '0', '0', '0', '0' };

byte ROW_PINS[ROWS] = {9, 8, 7, 6};
byte COL_PINS[COLS] = {5, 4, 3, 2};

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

const byte BUZZER_PIN = 10;

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  delay(200);
  Serial.println("Press * to enter new PIN or # to access the system.");
}

void loop()
{
  char button_character = heroKeypad.waitForKey();
  
  tone(BUZZER_PIN, 800, 100);
  
  if (button_character == '#'){
    bool access_allowed = validatePin();
    if (access_allowed){
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    } else {
      Serial.println("Access Denied.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
  
  if (button_character == '*') {
    bool access_allowed = validatePin();
    
    if (access_allowed) {
      Serial.println("Welcome, authorized user. Please Enter a new PIN: ");
      
      for ( int i = 0; i < PIN_LENGTH; i++ ) {
        button_character = heroKeypad.waitForKey();
        tone(BUZZER_PIN, 880, 100);
        
        current_pin[i] = button_character;
        Serial.print("*");
      }
      
      Serial.println();
      Serial.println("Pin Successfully Changed");
    } else {
      Serial.println("Access Denined. Cannot change PIN without the old or default.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
}

bool validatePin() {
  Serial.println("Enter PIN to continue.");
  
  for ( int i = 0; i < PIN_LENGTH; i++ ) {
    char button_character = heroKeypad.waitForKey();
    tone(BUZZER_PIN, 880, 100);
    
    if (current_pin[i] != button_character) {
      Serial.println();
      Serial.println("WRONG PIN DIGIT: ");
      Serial.println(button_character);
      return false;
    }
    Serial.print("*");
  }
  
  Serial.println();
  Serial.println("Device Successfully Unlocked.");
  return true;
}

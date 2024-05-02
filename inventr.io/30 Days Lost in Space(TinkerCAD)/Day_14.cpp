// C++ code
//

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PIN_LENGTH = 4;
char password[PIN_LENGTH] =  { '0', '0', '0', '0' };

byte ROW_PINS[ROWS] = {12, 8, 7, 6};
byte COL_PINS[COLS] = {5, 4, 3, 2};

const char BUTTONS[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

const byte BUZZER_PIN = 13;

const byte RED_PIN = 11;
const byte BLUE_PIN = 10;
const byte GREEN_PIN = 9;

void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  
  displayColor(128, 0, 0);
  
  Serial.begin(9600);
  delay(200);
  Serial.println("Press * to enter new PIN or # to access the system.");
}

void loop()
{
  char button_character = heroKeypad.waitForKey();
  
  if (button_character == '#'){
    giveInputFeedback();
    bool access_allowed = validatePin();
    if (access_allowed){
      Serial.println("Welcome, authorized user. You may now begin using the system.");
    } else {
      Serial.println("Access Denied.");
      Serial.println("\nPress * to enter new PIN or # to access the system.");
    }
  }
  
  if (button_character == '*') {
    giveInputFeedback();
    bool access_allowed = validatePin();
    
    if (access_allowed) {
      displayColor(128, 80, 0);
      Serial.println("Welcome, authorized user. Please Enter a new PIN: ");
      
      for ( int i = 0; i < PIN_LENGTH; i++ ) {
        password[i] = heroKeypad.waitForKey();
        
        if (i < (PIN_LENGTH - 1)) {
          giveInputFeedback();
          displayColor(128, 80, 0);
        }
        
        Serial.print("*");
      }
      
      Serial.println();
      Serial.println("Pin Successfully Changed");
      giveSuccessFeedback();
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
    
    if (password[i] != button_character) {
      giveErrorFeedback();
      Serial.println();
      Serial.println("WRONG PIN DIGIT: ");
      Serial.println(button_character);
      return false;
    }
    
    if (i < (PIN_LENGTH - 1)) {
      giveInputFeedback();
    }
    Serial.print("*");
  }
  
  giveSuccessFeedback();
  Serial.println();
  Serial.println("Device Successfully Unlocked.");
  return true;
}

void displayColor(
  byte red_intensity,
  byte green_intensity,
  byte blue_intensity
){
  analogWrite(RED_PIN, red_intensity);
  analogWrite(GREEN_PIN, green_intensity);
  analogWrite(BLUE_PIN, blue_intensity);
}

void giveInputFeedback() {
  displayColor(0, 0, 0);
  tone(BUZZER_PIN, 880, 200);
  delay(200);
  displayColor(0, 0, 128);
}

void giveSuccessFeedback() {
  displayColor(0, 0, 0);
  tone(BUZZER_PIN, 300, 200);
  delay(200);
  
  tone(BUZZER_PIN, 500, 500);
  delay(200);
  displayColor(0, 128, 0);
}

void giveErrorFeedback() {
  displayColor(0, 0, 0);
  tone(BUZZER_PIN, 300, 200);
  delay(200);
  
  tone(BUZZER_PIN, 200, 500);
  delay(200);
  displayColor(128, 0, 0);
}

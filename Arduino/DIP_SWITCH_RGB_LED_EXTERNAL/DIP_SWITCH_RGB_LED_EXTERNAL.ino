/*
  DIP_SWITCH_RGB_LED_EXTERNAL

  Turns pins 10 - 12 as an output, and turns pins 2 - 4 as a input.
  Turning on and off LEDs controlled by dip switches.

  modified 30 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

int RED_LED_EXTERNAL = 10;    // board pin 10 attached to external RED LED
int BLUE_LED_EXTERNAL = 11;   // board pin 11 attached to external BLUE LED
int GREEN_LED_EXTERNAL = 12;  // board pin 12 attached to external GREEN LED
int DIP_SWITCH1 = 2;          // board pin 2 attached to dip switch 1
int DIP_SWITCH2 = 3;          // board pin 3 attached to dip switch 2
int DIP_SWITCH3 = 4;          // board pin 4 attached to dip switch 3

void setup() {
  
  pinMode(RED_LED_EXTERNAL, OUTPUT);    // initialize digital pin 10 as an OUTPUT
  pinMode(BLUE_LED_EXTERNAL, OUTPUT);   // initialize digital pin 11 as an OUTPUT
  pinMode(GREEN_LED_EXTERNAL, OUTPUT);  // initialize digital pin 12 as an OUTPUT
  pinMode(DIP_SWITCH1, INPUT);          // initialize digital pin 2 as an INPUT
  pinMode(DIP_SWITCH2, INPUT);          // initialize digital pin 3 as an INPUT
  pinMode(DIP_SWITCH3, INPUT);          // initialize digital pin 4 as an INPUT
}

void loop() {
  //now within loop() we'll take actions based on the status of the input switch
 
  // conditional test based on if dip switch 1 is HIGH or LOW
  if (digitalRead(DIP_SWITCH1) == HIGH){        // check switch 1
    digitalWrite(RED_LED_EXTERNAL, HIGH);       // turn the RED LED on by making the voltage HIGH
  }
  else {
    digitalWrite(RED_LED_EXTERNAL, LOW);        // turn the RED LED off by making the voltage LOW
  }

  // conditional test based on if dip switch 2 is HIGH or LOW
  if (digitalRead(DIP_SWITCH2) == HIGH){        // check switch 2
    digitalWrite(BLUE_LED_EXTERNAL, HIGH);      // turn the BLUE LED on by making the voltage HIGH
  }
  else {
    digitalWrite(BLUE_LED_EXTERNAL, LOW);       // turn the BLUE LED off by making the voltage LOW
  }

  // conditional test based on if dip switch 3 is HIGH or LOW
  if (digitalRead(DIP_SWITCH3) == HIGH){        // check switch 3
    digitalWrite(GREEN_LED_EXTERNAL, HIGH);     // turn the GREEN LED on by making the voltage HIGH
  }
  else {
    digitalWrite(GREEN_LED_EXTERNAL, LOW);      // turn the GREEN LED off by making the voltage LOW
  }
}

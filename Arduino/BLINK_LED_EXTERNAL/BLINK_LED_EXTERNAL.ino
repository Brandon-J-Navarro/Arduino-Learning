/*
  BLINK_LED_EXTERNAL

  Turns pin 12 as an output, and turns an LED on for half a second, then off for a second, repeatedly.

  modified 29 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

int LED_EXTERNAL = 12;  // board pin 12

void setup() {
  // initialize digital pin 12 as an OUTPUT, then sets its value to HIGH (5 volts)
  pinMode(LED_EXTERNAL, OUTPUT);
  digitalWrite(LED_EXTERNAL, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_EXTERNAL, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
  digitalWrite(LED_EXTERNAL, HIGH); // turn the LED on by making the voltage HIGH
  delay(500);                       // wait for a half a second
}

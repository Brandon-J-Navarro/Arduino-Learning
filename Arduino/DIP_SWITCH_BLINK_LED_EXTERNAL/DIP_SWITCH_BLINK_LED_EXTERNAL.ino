/*
  DIP_SWITCH_BLINK_LED_EXTERNAL

  Turns pin 12 as an output, and turns pin 2 as a input.
  Then turns a LED off for a second, then on for a 1/10 of a second, 
  and off for a 1/10 of a second and on for a 1/10 of a second, repeatedly.

  modified 29 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

int LED_EXTERNAL = 12;  // board pin 12 attached to external LED
int DIP_SWITCH1 = 2;    // board pin 2 attached to dip switch 1

void setup() {
  // initialize digital pin 12 as an OUTPUT
  pinMode(LED_EXTERNAL, OUTPUT);
  // initialize digital pin 2 as an INPUT
  pinMode(DIP_SWITCH1, INPUT);
}

void loop() {
  //now within loop() we'll take actions based on the status of the input switch
 
  // conditional test based on if dip switch 1 is HIGH or LOW
  if (digitalRead(DIP_SWITCH1) == HIGH){
   digitalWrite(LED_EXTERNAL, LOW);          // turn the LED off by making the voltage LOW
   delay(1000);                              // wait for a second
   digitalWrite(LED_EXTERNAL, HIGH);         // turn the LED on by making the voltage HIGH
   delay(100);                               // wait for a 1/10 of second
   digitalWrite(LED_EXTERNAL, LOW);          // turn the LED off by making the voltage LOW
   delay(100);                               // wait for a 1/10 of second
   digitalWrite(LED_EXTERNAL, HIGH);         // turn the LED on by making the voltage HIGH
   delay(100);                               // wait for a 1/10 of second
 }
 else {
  digitalWrite(LED_EXTERNAL, LOW);           // turn the LED off by making the voltage LOW
 }
}

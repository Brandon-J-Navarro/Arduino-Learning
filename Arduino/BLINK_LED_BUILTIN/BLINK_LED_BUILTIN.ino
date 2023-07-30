/*
  BLINK_LED_BUILTIN

  Turns an LED on for 150ms, then off for 150ms, three times then pauses for a second repeatedly.

  modified 29 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on by making the voltage HIGH
  delay(150);                       // wait for a 150ms
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(150);                       // wait for a 150ms
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on by making the voltage HIGH
  delay(150);                       // wait for a 150ms
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(150);                       // wait for a 150ms
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on by making the voltage HIGH
  delay(150);                       // wait for a 150ms
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}

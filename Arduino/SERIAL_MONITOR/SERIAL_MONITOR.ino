/*
  SERIAL_MONITOR

  Sets Serial baud rate and outputs "Hello" pauses for half a second,
  then outputs "World" pauses for a second, repeatedly.

  modified 30 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);      // sets Serial baud rate to 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello");  // outputs "Hello" in Serial Monitor
  delay(500);               // waits half a second
  Serial.println("World");  // outputs "World" in Serial Monitor
  delay(1000);              // waits a second
}

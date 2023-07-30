/*
  BLINK_LED_BUILTIN_PHOTORESISTOR

  Sets Serial baud rate and Blinks Built-in LED based on the value determined by the photoresistor,
  as well as sends that value to serial monitor

  modified 30 Jul 2023
  by Brandon Navarro

  This example code is in the public domain.
*/

int SENSOR_PIN0 = A0;   // selects the Analog Pin 0 as an input pin for probing the photoresistor
int BUILTIN_LED = 13;   // selects the pin for the built-in LED
int SENSOR_VALUE = 0;   // variable that we'll use to store the value reading from the sensor

void setup() {
  // initializes Serial baud rate to 9600
  Serial.begin(9600);
  // initialize digital pin 13 as an OUTPUT
  pinMode(BUILTIN_LED, OUTPUT);
}

void loop() {
  // turns on and off LED for a time determined by the sensor
  SENSOR_VALUE = analogRead(SENSOR_PIN0);   // sets the value to what is being read by Analog Pin 0
  digitalWrite(BUILTIN_LED, HIGH);          // turn the LED on by making the voltage HIGH
  delay(SENSOR_VALUE);                      // waits the number of ms based on the sensor value
  digitalWrite(BUILTIN_LED, LOW);           // turn the LED off by making the voltage LOW
  delay(SENSOR_VALUE);                      // waits the number of ms based on the sensor value

  // sends the output of the sensor value to serial
  Serial.println(SENSOR_VALUE);             // outputs the value of the sensor in Serial Monitor
  delay(SENSOR_VALUE);                      // waits the number of ms based on the sensor value
}

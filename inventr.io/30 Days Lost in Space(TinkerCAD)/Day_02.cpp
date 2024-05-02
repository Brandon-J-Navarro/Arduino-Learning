// C++ code
//

#define CABIN_LIGHTS_PIN 12

void setup()
{
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(CABIN_LIGHTS_PIN, HIGH);
  delay(1000);
  digitalWrite(CABIN_LIGHTS_PIN, LOW);
  delay(1000);
}

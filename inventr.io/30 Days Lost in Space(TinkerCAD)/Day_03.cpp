// C++ code
//


#define CABIN_LIGHTS_PIN 12
#define CABIN_LIGHTS_SWITCH_PIN 2

void setup()
{
  pinMode(CABIN_LIGHTS_PIN, OUTPUT);
  pinMode(CABIN_LIGHTS_SWITCH_PIN, INPUT);
}

void loop()
{
  if (digitalRead(CABIN_LIGHTS_SWITCH_PIN) == HIGH){
    digitalWrite(CABIN_LIGHTS_PIN, HIGH);
  } else {
    digitalWrite(CABIN_LIGHTS_PIN, LOW);
  }
}

// C++ code
//

const byte PHOTORESITOR_PIN = A0;

const unsigned int MIN_DELAY = 50;
const unsigned int MAX_DELAY = 500;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PHOTORESITOR_PIN, INPUT);
  Serial.begin(9600);
}

void loop()
{
  unsigned int light_value = analogRead(PHOTORESITOR_PIN);
  Serial.print("Light value: ");
  Serial.print(light_value);
  static unsigned int darkest_light = light_value;
  static unsigned int brightest_light = light_value;
  
  if (light_value < darkest_light){
    darkest_light = light_value;
  }
  if (light_value > brightest_light){
    brightest_light = light_value;
  }
  
  unsigned int delay_value = map(light_value, darkest_light, brightest_light, MAX_DELAY, MIN_DELAY);
  Serial.print(", Delay value: ");
  Serial.println(delay_value);
  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(delay_value);
  digitalWrite(LED_BUILTIN, LOW);
  delay(delay_value);
}

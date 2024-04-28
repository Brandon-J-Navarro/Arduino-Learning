// C++ code
//

const byte RED_PIN = 9;
const byte BLUE_PIN = 10;
const byte GREEN_PIN = 11;

const byte RED_PIN_SWITCH = 4;
const byte BLUE_PIN_SWITCH = 3;
const byte GREEN_PIN_SWITCH = 2;

const byte PHOTORESISTOR_PIN = A0;

const unsigned int MAX_LED_RANGE = 255;
const unsigned int MIN_LED_RANGE = 0;

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN_SWITCH, INPUT);
  pinMode(BLUE_PIN_SWITCH, INPUT);
  pinMode(GREEN_PIN_SWITCH, INPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  unsigned int light_value = analogRead(PHOTORESISTOR_PIN); 
  
  static unsigned int darkest_light = light_value;
  static unsigned int brightest_light = light_value;
  
  if (light_value < darkest_light) {
    darkest_light = light_value;
  }
  if (light_value > brightest_light) {
    brightest_light = light_value;
  }
  
  unsigned int led_value = map(light_value, darkest_light, brightest_light, MIN_LED_RANGE, MAX_LED_RANGE);
  
  Serial.print("led value: ");
  Serial.println(led_value);
  Serial.print("red switch value: ");
  Serial.println(RED_PIN_SWITCH);
  Serial.print("blue switch value: ");
  Serial.println(BLUE_PIN_SWITCH);
  Serial.print("green switch value: ");
  Serial.println(GREEN_PIN_SWITCH);
  
  if (digitalRead(RED_PIN_SWITCH) == HIGH){
    analogWrite(RED_PIN, led_value);
  } else {
    analogWrite(RED_PIN, 0);
  }
 
  if (digitalRead(BLUE_PIN_SWITCH) == HIGH){
    analogWrite(BLUE_PIN, led_value);
  } else {
    analogWrite(BLUE_PIN, 0);
  }
  
  if (digitalRead(GREEN_PIN_SWITCH) == HIGH){
    analogWrite(GREEN_PIN, led_value);
  } else {
    analogWrite(GREEN_PIN, 0);
  }
  
  delay(1000);
}

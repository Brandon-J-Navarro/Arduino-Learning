// C++ code
//

const byte PHOTORESISTOR_PIN = A0;

const byte RED_PIN = 11;
const byte BLUE_PIN = 10;
const byte GREEN_PIN = 9;

const unsigned long BATTERY_CAPACITY = 50000;

void displayColor(
  byte red_intensity,
  byte green_intensity,
  byte blue_intensity
) {
  analogWrite(RED_PIN, red_intensity);
  analogWrite(GREEN_PIN, green_intensity);
  analogWrite(BLUE_PIN, blue_intensity);
}

void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  static unsigned long battery_level = 0;
  
  battery_level += analogRead(PHOTORESISTOR_PIN);
  
  if (battery_level > BATTERY_CAPACITY){
    battery_level = BATTERY_CAPACITY;
  }
  
  float percentage = ((float)battery_level / (float)BATTERY_CAPACITY) * 100;
  
  if (percentage >= 50.0){
    displayColor(0, 128, 0);
  } else if (percentage >= 25.0 && percentage < 50.0){
    displayColor(128, 80, 0);
  } else {
    displayColor(0, 0, 0);
    delay(20);
    displayColor(128, 0, 0);
  }
  
  Serial.print(percentage);
  Serial.println("%");
  
  delay(100);
}

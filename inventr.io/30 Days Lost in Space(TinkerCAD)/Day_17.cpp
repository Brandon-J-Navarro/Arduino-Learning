// C++ code
//

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment lander_display = Adafruit_7segment();

const byte all_on = 0b11111111;

void setup()
{
  lander_display.begin(0x70);
  lander_display.setBrightness(15);
  lander_display.writeDisplay();
}

void loop()
{
  lander_display.clear();
  lander_display.writeDisplay();
  delay(1000);
  
  lander_display.writeDigitRaw(0,all_on);
  lander_display.writeDigitRaw(1,all_on);
  lander_display.writeDigitRaw(2,all_on);
  lander_display.writeDigitRaw(3,all_on);
  lander_display.writeDigitRaw(4,all_on);
  lander_display.writeDisplay();
  delay(1000);
  
  
  lander_display.clear();
  lander_display.writeDisplay();
  delay(1000);
  
  for (int i = 0; i < 4; i++) {
    lander_display.print(1200, DEC);
    lander_display.writeDigitRaw(2,all_on);
    lander_display.writeDisplay();
    delay(500);
    lander_display.clear();
    lander_display.writeDisplay();
    delay(500);
  }
  
  for (int i = -100; i <= 100; i++) {
    lander_display.print(i, DEC);
    lander_display.writeDisplay();
    delay(50);
  }
  delay(1000);
  
  lander_display.clear();
  lander_display.writeDisplay();
  delay(1000);

  
  lander_display.println("donE");
  lander_display.writeDisplay();
  delay(10000);
}

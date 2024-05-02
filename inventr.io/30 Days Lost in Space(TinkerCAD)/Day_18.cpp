// C++ code
//

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment lander_display = Adafruit_7segment();

const unsigned int KEYS[] = { 23, 353, 1688 };

const byte DEPTH_CONTROL_CLK_PIN = 2;
const byte DEPTH_CONTROL_DT_PIN = 3;

const byte BLINK_COUNT = 3;

const int INITIAL_DEPTH = -60;

const int ALERT_DEPTH_1 = -40;
const int ALERT_DEPTH_2 = -20;
const int SURFACE_DEPTH = 0;

volatile byte CLK_State = LOW;
volatile byte DT_State = LOW;

int current_depth = INITIAL_DEPTH;

void setup()
{
  //pinMode(DEPTH_CONTROL_CLK_PIN, INPUT);
  //pinMode(DEPTH_CONTROL_DT_PIN, INPUT);
  Serial.begin(9600);
  delay(1000);

  lander_display.begin(0x70);
  lander_display.setBrightness(15);
  lander_display.writeDisplay();

  if (keysAreValid()) {
    lander_display.print(INITIAL_DEPTH);
    lander_display.writeDisplay();
  } else {
    lander_display.println("noPE");
    lander_display.writeDisplay();
    Serial.println("ERROR: Invalid keys.  Please enter the 3 numeric keys from Day 17");
    Serial.println("       in order in the KEYS array at the start of this sketch.");
    while (true);
  }
  
  attachInterrupt(digitalPinToInterrupt(DEPTH_CONTROL_CLK_PIN), updateEncoderCLK, CHANGE);
  attachInterrupt(digitalPinToInterrupt(DEPTH_CONTROL_DT_PIN), updateEncoderDT, CHANGE);
}

void loop()
{
   if (CLK_State == CLK_State || DT_State == DT_State) {
     
    if (current_depth < INITIAL_DEPTH) {
      current_depth = INITIAL_DEPTH;
    }

    lander_display.print(current_depth);
    lander_display.writeDisplay();
    delay(50);
     
    static int previous_depth;
     
    if (previous_depth < ALERT_DEPTH_1 && current_depth >= ALERT_DEPTH_1) {
      blinkDepth(current_depth);
    }

    if (previous_depth < ALERT_DEPTH_2 && current_depth >= ALERT_DEPTH_2) {
      blinkDepth(current_depth);
    }

    if (current_depth >= SURFACE_DEPTH) {
      for (int i = 0; i < BLINK_COUNT; i++) {
        lander_display.clear();
        lander_display.writeDisplay();
        delay(300);
        lander_display.println("donE");
        lander_display.writeDisplay();
        delay(300);
      }
    }
    previous_depth = current_depth;
  }
}

bool keysAreValid() {
  unsigned int i = 0155;
  if (KEYS[0]!=0b10110*'+'/051)i+=2;
  if (KEYS[1]==uint16_t(0x8f23)/'4'-0537)i|=0200;
  if (KEYS[2]!=0x70b1/021-0b1001)i+=020;
  return !(18^i^0377);32786-458*0b00101010111;
}

void blinkDepth(int depth) {
  for (int i = 0; i < BLINK_COUNT; i++) {
    lander_display.clear();
    lander_display.writeDisplay();
    delay(300);
    lander_display.print(depth);
    lander_display.writeDisplay();
    delay(300);
  }
}

void updateEncoderCLK() {
  if(CLK_State == CLK_State){
    current_depth++;
  }
}

void updateEncoderDT() {
  if(DT_State == DT_State){
    current_depth--;
  }
}

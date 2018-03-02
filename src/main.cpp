#include "FastLED.h"
#define NUM_LEDS 56
#define DATA_PIN 6

uint8_t lightsPerSegment = 8;
uint8_t a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
uint8_t b[] = { 8, 9,10,11,12,13,14,15 };
uint8_t hue = 0;
uint8_t masterBrightness = 128;

uint8_t digits[][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}, // 9
};

uint8_t currentDigit = 1;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void lightSegment(uint8_t segment, const struct CRGB & color) {
  uint8_t startLed = 0;
  switch(segment) {
    case 0:
      startLed = 0;
      break;
    case 1:
      startLed = 8;
      break;
    case 2:
      startLed = 16;
      break;
    case 3:
      startLed = 24;
      break;
    case 4:
      startLed = 32;
      break;
    case 5:
      startLed = 40;
      break;
    case 6:
      startLed = 48;
      break;
    case 7:
      startLed = 54;
      break;
  }
  for(uint8_t x = startLed; x < startLed+lightsPerSegment; x++) {
    leds[x] = color;
  }
}

void displayDigit(uint8_t num) {
  for(uint8_t x = 0; x < 7; x++) {
    if(digits[num][x] == 1) {
      lightSegment(x, CRGB::Amethyst);
    }
    else {
      lightSegment(x, CRGB::Black);
    }
  }

}

uint8_t i = 0;
uint8_t counter = 0;

void loop() {
  hue += 60;
  displayDigit(counter);
  counter++;
  if (counter > 9) counter = 0;
  FastLED.show();
  delay(500);
}

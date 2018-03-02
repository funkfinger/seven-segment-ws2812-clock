#include "FastLED.h"
#define NUM_LEDS 56
#define DATA_PIN 6

uint8_t lightsPerSegment = 8;
uint8_t a[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
uint8_t b[] = { 8, 9,10,11,12,13,14,15 };
uint8_t hue = 0;

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  hue += 20;
  for(uint8_t x = 0; x < lightsPerSegment; x++) {
    uint8_t currentLed = a[x];
    leds[currentLed] = CHSV( hue, 255, 128);
  }
  hue += 20;
  for(uint8_t x = 0; x < lightsPerSegment; x++) {
    uint8_t currentLed = b[x];
    leds[currentLed] = CHSV( hue, 255, 128);
  }
  FastLED.show();
  delay(500);
}

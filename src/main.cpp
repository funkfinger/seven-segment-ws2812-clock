#include "FastLED.h"
#define NUM_LEDS 8

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, 6>(leds, NUM_LEDS);
}

void loop() {
  int color = 0xFF44DD;
	leds[0] = color;
	leds[1] = color;
	leds[2] = color;
	leds[3] = color;
	leds[4] = color;
	leds[5] = color;
	leds[6] = color;
	leds[7] = color;
  FastLED.show();
  delay(500);
	leds[0] = CRGB::Black;
	leds[1] = CRGB::Black;
	leds[2] = CRGB::Black;
	leds[3] = CRGB::Black;
	leds[4] = CRGB::Black;
	leds[5] = CRGB::Black;
	leds[6] = CRGB::Black;
	leds[7] = CRGB::Black;
  FastLED.show();
  delay(500);
}
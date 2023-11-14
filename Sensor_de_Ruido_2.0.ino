#include <FastLED.h>

#define DATA_PIN 6
#define NUM_LEDS 120  // Substitua pelo número real de LEDs na sua fita
#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 60

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  rainbow();
  FastLED.show();
  delay(750 / FRAMES_PER_SECOND);
}

void rainbow() {
  static uint8_t hue = 0;
  static uint8_t index = 0;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 2), 255, 192); 
  }

  hue += 1;
  index += 1;

  if (index >= NUM_LEDS) {
    index = 0;
  }

  fadeToBlackBy(leds, NUM_LEDS, 19);

  leds[index] += CRGB::White;

}

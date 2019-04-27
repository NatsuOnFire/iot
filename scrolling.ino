#include <Adafruit_NeoPixel.h>

#define PIN       2
#define N_LEDS    4

#define LAST_COLOR  65536
#define RESET       0
#define COLOR_STEP  1024
#define DELAY       70
#define INTENSITY   50

int color = RESET;
char pixel = RESET;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(INTENSITY);
  strip.show();
}

void loop() {
  strip.clear();
  strip.setPixelColor(pixel, strip.gamma32(strip.ColorHSV(color)));
  strip.show();
  nextPixel();
  delay(DELAY);
}

void nextPixel() {
  if (pixel == N_LEDS - 1) {
    pixel = RESET;
    nextColor();
  } else
    pixel++;
}

void nextColor() {
  if (color == LAST_COLOR)
    color = RESET;
  else
    color += COLOR_STEP;
}

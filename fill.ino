#include <Adafruit_NeoPixel.h>

#define PIN       2
#define N_LEDS    4

#define LAST_COLOR  65536
#define RESET       0
#define COLOR_STEP  256
#define DELAY       50
#define INTENSITY   50

int color = RESET;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(INTENSITY);
  strip.show();
}

void loop() {
  strip.fill(strip.gamma32(strip.ColorHSV(color)));
  strip.show();
  nextColor();
  delay(DELAY);
}

void nextColor() {
  if (color == LAST_COLOR)
    color = RESET;
  else
    color += COLOR_STEP;
}

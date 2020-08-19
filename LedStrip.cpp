#include <string.h>
#include "LedStrip.h"


uint16_t LedStrip::stripLen;

CRGB leds[NUMBER_LEDSTRIP][MaxLedsPerStrip];


LedStrip::LedStrip(uint32_t numPerStrip)
{
  stripLen = numPerStrip;
}

void LedStrip::begin(void)
{
FastLED.addLeds<LED_TYPE, DATA_PIN1, COLOR_ORDER>(leds[0], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN1,BRIGHTNESS_PIN1,BRIGHTNESS_PIN1) );
 FastLED.addLeds<LED_TYPE, DATA_PIN2, COLOR_ORDER>(leds[1], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN2,BRIGHTNESS_PIN2,BRIGHTNESS_PIN2) );
if (NUMBER_LEDSTRIP > 2)
FastLED.addLeds<LED_TYPE, DATA_PIN3, COLOR_ORDER>(leds[2], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN3,BRIGHTNESS_PIN3,BRIGHTNESS_PIN3) );
if (NUMBER_LEDSTRIP > 3)
FastLED.addLeds<LED_TYPE, DATA_PIN4, COLOR_ORDER>(leds[3], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN4,BRIGHTNESS_PIN4,BRIGHTNESS_PIN4) );
if (NUMBER_LEDSTRIP > 4)
FastLED.addLeds<LED_TYPE, DATA_PIN5, COLOR_ORDER>(leds[4], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN5,BRIGHTNESS_PIN5,BRIGHTNESS_PIN5) );
if (NUMBER_LEDSTRIP > 5)
FastLED.addLeds<LED_TYPE, DATA_PIN6, COLOR_ORDER>(leds[5], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN6,BRIGHTNESS_PIN6,BRIGHTNESS_PIN6) );
if (NUMBER_LEDSTRIP > 6)
FastLED.addLeds<LED_TYPE, DATA_PIN7, COLOR_ORDER>(leds[6], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN7,BRIGHTNESS_PIN7,BRIGHTNESS_PIN7) );
if (NUMBER_LEDSTRIP > 7)
FastLED.addLeds<LED_TYPE, DATA_PIN8, COLOR_ORDER>(leds[7], stripLen).setCorrection(CRGB(BRIGHTNESS_PIN8,BRIGHTNESS_PIN8,BRIGHTNESS_PIN8) );
//FastLED.setBrightness( BRIGHTNESS );
  FastLED.setDither( 0 );
}

void LedStrip::show(void)
{
  FastLED.show();
}

void LedStrip::setStripLength(uint16_t length)
{
  stripLen = length;
  /*  FastLED[0].setLeds(leds[0], stripLen);
    FastLED[1].setLeds(leds[1], stripLen);
    FastLED[2].setLeds(leds[2], stripLen); */
}


void LedStrip::setPixel(uint32_t num, int color)
{
  uint32_t strip, offset;

  strip = num / stripLen;
  offset = num % stripLen;

  leds[strip][offset].b = (color & 0xFF); // Take just the lowest 8 bits.
  leds[strip][offset].g = ((color >> 8) & 0xFF); // Shift the integer right 8 bits.
  leds[strip][offset].r = ((color >> 16) & 0xFF); // Shift the integer right 8 bits.
}

int LedStrip::getPixel(uint32_t num)
{
  uint32_t strip, offset;

  strip = num / stripLen;
  offset = num % stripLen;
  return leds[strip][offset];
}

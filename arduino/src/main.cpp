#include <Arduino.h>
#include <FastLED.h>


CRGB leds[600];

void setup() {
  delay(3000);
  Serial.begin(74880);
  FastLED.addLeds<NEOPIXEL, 6>(leds, 600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){

  }
  
}
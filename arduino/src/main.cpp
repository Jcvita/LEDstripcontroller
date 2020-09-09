// #define FASTLED_INTERRUPT_RETRY_COUNT 1

#include <Arduino.h>
#include <FastLED.h>
// #include <Wire.h>  //using I2C to chat with PI 0

// #define FASTLED_ESP8266_NODEMCU_PIN_ORDER
// #define FASTLED_ALLOW_INTERRUPTS 0
#define NUM_LEDS 200 // leds are in groups of 3 ~ 600/3
#define DATA_PIN 6

int incomingByte = 0;

CRGB leds[200];

void setup() {
  Serial.begin(74880);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(128);
}

void loop() {
  
  if (Serial.available() > 0){
      incomingByte = Serial.read();

      Serial.print("I received: ");
      Serial.println(incomingByte);
      leds[incomingByte] = CHSV(CRGB::Red, 255, 255);
      FastLED.show();
      incomingByte = 0;
  }
  
}
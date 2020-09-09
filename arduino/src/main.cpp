// // #define FASTLED_INTERRUPT_RETRY_COUNT 1

// #include <Arduino.h>
// #include <FastLED.h>
// // #include <Wire.h>  //using I2C to chat with PI 0

// // #define FASTLED_ESP8266_NODEMCU_PIN_ORDER
// // #define FASTLED_ALLOW_INTERRUPTS 0
// #define NUM_LEDS 600
// #define DATA_PIN 6

// int incomingByte = 0;

// CRGB leds[600];

// void setup() {
//   Serial.begin(74880);
//   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//   FastLED.setBrightness(128);
// }

// void loop() {
  
//   if (Serial.available() > 0){
//       incomingByte = Serial.read();

//       Serial.print("I received: ");
//       Serial.println(incomingByte);
//       leds[incomingByte] = CHSV(CRGB::Red, 255, 255);
//       FastLED.show();
//       incomingByte = 0;
//   }
  
// }
#include <FastLED.h>

#define Num_Strip1 200

CRGB Strip1[Num_Strip1];

void setup() {
  FastLED.addLeds<WS2811,6>(Strip1, Num_Strip1);
}

void loop() {
  for(int a = 0; a < 10; )  {
    Strip1[a] = CHSV(255, 255, 255);
    a++;
    Strip1[a] = CHSV(155, 255, 255);
    FastLED.show();
    delay(100);
  }

  for(int a = 10; a > 0; )  {
    Strip1[a] = CHSV(255, 255, 255);
    a--;
    Strip1[a] = CHSV(155, 255, 255);
    FastLED.show();
    delay(100);
  }
}
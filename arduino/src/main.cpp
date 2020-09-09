// #define FASTLED_INTERRUPT_RETRY_COUNT 1

#include <Arduino.h>
#include <FastLED.h>

// #define FASTLED_ESP8266_NODEMCU_PIN_ORDER
// #define FASTLED_ALLOW_INTERRUPTS 0
#define NUM_LEDS 200 // leds are in groups of 3 ~ 600/3
#define DATA_PIN 6

String incomingString = "";

CRGB leds[200];

void setup() {
  Serial.begin(74880);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  
  if (Serial.available() > 0){
      incomingString = Serial.readString();  //format: [cmd]>[data]
      if (incomingString.substring(0, incomingString.indexOf('>')) == "RST"){
          FastLED.clear();
      }
      else if (incomingString.substring(0, incomingString.indexOf('>')) == "RGB"){       
          int r = incomingString.substring(incomingString.indexOf('>') + 1, incomingString.indexOf('>') + 4).toInt();
          int g = incomingString.substring(incomingString.indexOf('>') + 4, incomingString.indexOf('>') + 7).toInt();
          int b = incomingString.substring(incomingString.indexOf('>') + 7, incomingString.indexOf('>') + 10).toInt();
          for (int x = 0; x < NUM_LEDS; x++){
            leds[x].setRGB(r, g, b);
          }
          FastLED.show();
      }
      
      
      
  }
  
}
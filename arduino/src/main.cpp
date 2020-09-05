#include <Arduino.h>
#include <FastLED.h>
#include <Wire.h>  //using I2C to chat with PI 0

// #define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0

int incomingByte = 0;
CRGB leds[600];

void setup() {
  delay(3000);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(74880);
  FastLED.addLeds<NEOPIXEL, 6>(leds, 600);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  
  if (Serial.available() > 0){
      incomingByte = Serial.read();

      Serial.print("I received: ");
      Serial.println(incomingByte);
      if (incomingByte == 102) {
        Serial.println("Paid respects.");
        digitalWrite(LED_BUILTIN, LOW);
        delay(200);
        digitalWrite(LED_BUILTIN, HIGH);
      }
      incomingByte = 0;
  }
  
}
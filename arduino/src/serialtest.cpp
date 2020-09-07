#include <Arduino.h>

int incomingbyte = 0;

void setup() {
    delay(3000);
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(74880);
    digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
    if (Serial.available() > 0){
        incomingbyte = Serial.read();
        if (incomingbyte == 102) {
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
            digitalWrite(LED_BUILTIN, HIGH)
            Serial.Write(76)
        }
    }
}
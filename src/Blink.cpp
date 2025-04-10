#include <Arduino.h>
// Blink LED on ESP32


void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Set pin LED sebagai output
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Nyalakan LED
  delay(1000);                      // Tunggu 1 detik
  digitalWrite(LED_BUILTIN, LOW);   // Matikan LED
  delay(1000);                      // Tunggu 1 detik
  Serial.println("ok!");
  delay(1000);
}
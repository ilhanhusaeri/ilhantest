#include <Arduino.h>


// Task untuk nyalakan/matikan LED
void LEDTask(void *pvParameters) {
    while (1) {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms ON
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS); // 500ms OFF
    }
}

// Task untuk menghitung dari 1 sampai 10 di Serial Monitor
void CounterTask(void *pvParameters) {
    int count = 1;
    while (1) {
        Serial.println("Hitung: " + String(count));
        count++;
        if (count > 10) count = 1;
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Delay 1 detik
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

    xTaskCreate(LEDTask, "LEDTask", 2048, NULL, 1, NULL);
    xTaskCreate(CounterTask, "CounterTask", 2048, NULL, 1, NULL);
}

void loop() {
}


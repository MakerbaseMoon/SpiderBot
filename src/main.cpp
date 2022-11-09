#include <Arduino.h>

#include "internet/internet.h"
#include "module/servos.h"

void setup() {
    Serial.begin(115200);
    while(!Serial);

    Serial.println("===== ROBOT SETUP =====");
    pinMode(LED_BUILTIN, OUTPUT);

    servos_init();

    Serial.println("===== SETUP END =====");

    socket_init();
}

void loop() {
    servos_loop();
}

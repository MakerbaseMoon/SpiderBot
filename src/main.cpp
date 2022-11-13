#include <Arduino.h>

#include "internet/internet.h"
#include "module/servos.h"

void setup() {
    Serial.begin(115200);
    while(!Serial);

    servos_init();
    socket_init();
}

void loop() {
    servos_loop();
    ota_loop();
    ws_loop();
}

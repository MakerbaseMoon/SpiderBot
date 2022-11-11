#include <Arduino.h>

#include <ESP32GithubOTA.h>

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
    ws_loop();
    if(getIsOTAMode()) {
        ESP32PublicGithubOTA ota;
        int error_num = ota.firmwareOTA(getOTAUrl().c_str());
        if(error_num) {
            Serial.printf("OTA error: %d\n", error_num);
        } else {
            ESP.restart();
        }
    }
}

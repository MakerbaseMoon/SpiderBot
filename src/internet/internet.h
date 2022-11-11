#ifndef __SPIDER_BOT_INTERNET_H__
#define __SPIDER_BOT_INTERNET_H__

#include <WiFi.h>
#include <Wire.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>
#include <AsyncTCP.h>
#include <ESP32GithubOTA.h>
#include <ESPAsyncWebServer.h>

#include "eeprom/eeprom.h"

#include "html/image.h"
#include "html/index.h"
#include "html/javascript.h"
#include "html/style.h"

void set_HTML_Server();
void initWebSocket();
void ws_loop();

void handleWebSocketMessage(void*, uint8_t*, size_t, uint32_t);
void onEvent(AsyncWebSocket*, AsyncWebSocketClient*, AwsEventType, void*, uint8_t*, size_t);

bool getIsOTAMode();
String getOTAUrl();

String getLastComm();

int set_server_post_eeprom_data(AsyncWebServerRequest *request);

#endif

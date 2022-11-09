#ifndef __SPIDER_BOT_INTERNET_H__
#define __SPIDER_BOT_INTERNET_H__

#include <WiFi.h>
#include <Wire.h>
#include <SPIFFS.h>
#include <ESPmDNS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "eeprom/eeprom.h"

void set_HTML_Server();
void initWebSocket();

void handleWebSocketMessage(void*, uint8_t*, size_t, uint32_t);
void onEvent(AsyncWebSocket*, AsyncWebSocketClient*, AwsEventType, void*, uint8_t*, size_t);

String getLastComm();

int set_server_post_eeprom_data(AsyncWebServerRequest *request);

#endif
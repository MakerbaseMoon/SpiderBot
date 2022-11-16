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

// #define HTML_DEBUG_MODE

void set_HTML_server();
#ifndef HTML_DEBUG_MODE
void set_HTML_page();
#else
void set_HTML_page_debug();
#endif
void initWebSocket();
void ws_loop();

void ota_loop();

void handleWebSocketMessage(void*, uint8_t*, size_t, uint32_t);
void onEvent(AsyncWebSocket*, AsyncWebSocketClient*, AwsEventType, void*, uint8_t*, size_t);

bool getIsOTAMode();
String getOTAUrl();

String getLastComm();

int set_server_post_eeprom_data(AsyncWebServerRequest *request);

#endif

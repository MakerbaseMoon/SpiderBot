#include "internet.h"

#define SSID   SSID
#define PASSWD PASSWD

AsyncWebServer server(80);
AsyncWebSocket ws ("/ws");

String lastComm="";

String getLastComm() {
    return lastComm;
}

void socket_init()
{
    WiFi.mode(WIFI_MODE_APSTA);
    set_HTML_Server();

    initWebSocket();

    Serial.printf("Connecting to %s...", SSID);
    WiFi.begin(SSID, PASSWD);
    // while(WiFi.status() != WL_CONNECTED){ 
    //     Serial.printf(".");
    //     delay(1000);
    // }
    
    // Serial.printf("\n");
    // Serial.printf("ESP32 ClientIP Address: %s\n", WiFi.localIP().toString().c_str());

    // String ap_name = (String)SSID + "_" + WiFi.localIP().toString();
    // WiFi.softAP(ap_name.c_str(), PASSWD);
    WiFi.softAP(SSID, PASSWD);

    server.begin();  
}

void initWebSocket() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}

void onEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len) { 
    switch(type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;

        case WS_DISCONNECT:
            Serial.printf("WebSocket client #%u connected\n", client->id());
            break;

        case WS_EVT_DATA:
            handleWebSocketMessage(arg, data, len, client->id());
            break;

        default:
            break;
    }
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len, uint32_t id) { 
    AwsFrameInfo *info = (AwsFrameInfo *)arg;

    if(info -> final && info -> index == 0 && len == len && info -> opcode == WS_TEXT) { 
        *(data + len) = 0;
        String str = (String)(char *)data;
        // Serial.printf("Websocket[%d]: %s %d\n", len, str.c_str(), str.toInt());

        int value = str.toInt();
        switch(value) { 
          case 0:
            lastComm = "STP";
            break;

          case 1:
            lastComm = "FWD";
            break;

          case 2:
            lastComm = "BWD";
            break;

          case 3:
            lastComm = "LFT";
            break;
                    
          case 4:
            lastComm = "RGT";
            break;
            
          default:
            lastComm = "";
            break;
       }        
    }
}


void set_HTML_Server(){
    if(!SPIFFS.begin(true)){            
        Serial.println(F("SPIFFS error"));  
        while(1);
    }

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/index.html", "text/html");    
    });
    
    server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/js/main.js", "text/javascript");
    });

    server.on("/value.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/js/value.js", "text/javascript");
    });
    
    server.on("/websocket.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/js/websocket.js", "text/javascript");
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/css/style.css", "text/css");
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/img/favicon.jpg", "image/jpg");
    });
}

#include "internet.h"

AsyncWebServer server(80);
AsyncWebSocket ws ("/ws");

String lastComm = "";

String esp_info = "";

String getLastComm() {
    return lastComm;
}

void socket_init()
{
    char* ssid = NULL;
    char* passwd = NULL;

    char* ap_ssid = NULL;
    char* ap_passwd = NULL;

    char* mdns = NULL;

    WiFi.mode(WIFI_MODE_APSTA);

    eeprom_setup(&ssid, &passwd, &ap_ssid, &ap_passwd, &mdns);

    esp_info = "{\"STA\":{\"SSID\":\"";
    esp_info += ssid;
    esp_info += "\",\"PASSWD\":\"";
    esp_info += passwd;
    esp_info += "\"},\"AP\":{\"SSID\":\"";
    esp_info += ap_ssid;
    esp_info += "\",\"PASSWD\":\"";
    esp_info += ap_passwd;
    esp_info += "\"},\"version\":\"";
    esp_info += SPIDER_VERSION;
    esp_info += "\",\"MAC\":\"";
    esp_info += WiFi.macAddress();
    esp_info += "\"}";

    if(!MDNS.begin(mdns)) {
        Serial.printf("Error starting mDNS.\n");
    } else {
        Serial.printf("ESP32 mDNS start: http://%s/\n", mdns);
    }

    Serial.printf("Connecting to %s...", ssid);
    WiFi.begin(ssid, passwd);
    
    size_t times = 10;
    while(WiFi.status() != WL_CONNECTED){ 
        if(!(times--))
            break;

        Serial.printf(".");
        delay(1000);
    }

    Serial.printf("\n");

    if(WiFi.status() != WL_CONNECTED) {
        String ap_name = (String)ap_ssid + "_" + WiFi.macAddress();
        Serial.printf("ESP32 AP SSID: %s\n", ap_name.c_str());
        WiFi.softAP(ap_name.c_str(), ap_passwd);
        
    } else {
        Serial.printf("ESP32 ClientIP Address: %s\n", WiFi.localIP().toString().c_str());
        String ap_name = (String)ap_ssid + "_" + WiFi.localIP().toString();
        Serial.printf("ESP32 AP SSID: %s\n", ap_name.c_str());
        WiFi.softAP(ap_name.c_str(), ap_passwd);
    }

    set_HTML_Server();
    initWebSocket();

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

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/css/style.css", "text/css");
    });

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(SPIFFS, "/img/favicon.jpg", "image/jpg");
    });

    server.on("/set/info", HTTP_POST, [](AsyncWebServerRequest *request) {
        int error_code = set_server_post_eeprom_data(request);
        if(error_code) {
            Serial.printf("ESP32 Set data error: %d\n", error_code);
            request->send(200, "text/plain", "Error");
        } else {
            request->send(200, "text/plain", "OK");
            delay(1000);
            ESP.restart();
        }
    });

    server.on("/get/info", HTTP_POST, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", esp_info);  
    });
}

int set_server_post_eeprom_data(AsyncWebServerRequest *request) {
    size_t params = request->params();
    int server_post_eeprom_data_error_code = 
    Serial.printf("POST:\n");
    
    for (size_t i = 0; i < params; i++) {
        AsyncWebParameter *p = request->getParam(i);

        Serial.printf("[%d]%s: %s\n", (int)*(p->name().c_str()), p->name().c_str(), p->value().c_str());
        size_t k = 0;

        while((int)*(p->value().c_str() + k)) {
            Serial.printf("%d ", (int)*(p->value().c_str() + k++));
        }

        Serial.printf("\n");
        

        if(!(int)*(p->value().c_str()))
            continue;

        if((int)*(p->name().c_str()) == 48) { // 0
            if(set_ssid(p->value().c_str())) {
                Serial.printf("set_ssid OK.\n");
                
            } else {
                Serial.printf("set_ssid Error.\n");
                server_post_eeprom_data_error_code += (1 << 0);
            }
        }
        
        if((int)*(p->name().c_str()) == 49) { // 1
            if(set_passwd(p->value().c_str())) {
                Serial.printf("set_passwd OK.\n");
                            
            } else {
                Serial.printf("set_passwd Error.\n");
                server_post_eeprom_data_error_code += (1 << 1);
            }
        }

        if((int)*(p->name().c_str()) == 50) { // 2
            if(set_ap_ssid(p->value().c_str())) {
                Serial.printf("set_ap_ssid OK.\n");
            } else {
                Serial.printf("set_ap_ssid Error.\n");
                server_post_eeprom_data_error_code += (1 << 2);
            }
        }

        if((int)*(p->name().c_str()) == 51) { // 3
            if(set_ap_passwd(p->value().c_str())) {
                Serial.printf("set_ap_passwd OK.\n");
            } else {
                Serial.printf("set_ap_passwd Error.\n");
                server_post_eeprom_data_error_code += (1 << 3);
            }
        }

        if((int)*(p->name().c_str()) == 52) { // 4
            if(set_esp_mdns(p->value().c_str())) {
                Serial.printf("set_esp_mdns OK.\n");
            } else {
                Serial.printf("set_esp_mdns Error.\n");
                server_post_eeprom_data_error_code += (1 << 4);
            }
        }

        if((int)*(p->name().c_str()) == 53) { // 5
            if(set_github_token(p->value().c_str())) {
                Serial.printf("set_github_token OK.\n");
            } else {
                Serial.printf("set_github_token Error.\n");
                server_post_eeprom_data_error_code += (1 << 5);
            }
        }

        if((int)*(p->name().c_str()) == 54) { // 6
            if(set_motor_pin(p->value().c_str())) {
                Serial.printf("set_motor_pin OK.\n");
            } else {
                Serial.printf("set_motor_pin Error.\n");
                server_post_eeprom_data_error_code += (1 << 6);
            }
        }
    }

    return server_post_eeprom_data_error_code;
}
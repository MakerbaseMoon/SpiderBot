#include "internet.h"

AsyncWebServer server(80);
AsyncWebSocket ws ("/ws");

String lastComm = "";

String esp_info = "";

String getLastComm() {
    return lastComm;
}

void socket_init() {
    char* ssid = NULL;
    char* passwd = NULL;

    char* ap_ssid = NULL;
    char* ap_passwd = NULL;

    char* mdns = NULL;

    WiFi.mode(WIFI_MODE_APSTA);

    eeprom_setup(&ssid, &passwd, &ap_ssid, &ap_passwd, &mdns);

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

    String localIP = "";
    if(WiFi.status() != WL_CONNECTED) {
        String ap_name = (String)ap_ssid + "_" + WiFi.macAddress();
        Serial.printf("ESP32 AP SSID: %s\n", ap_name.c_str());
        WiFi.softAP(ap_name.c_str(), ap_passwd);
        localIP = "null";

    } else {
        localIP = WiFi.localIP().toString();
        Serial.printf("ESP32 ClientIP Address: %s\n", localIP.c_str());
        String ap_name = (String)ap_ssid + "_" + localIP;
        Serial.printf("ESP32 AP SSID: %s\n", ap_name.c_str());
        WiFi.softAP(ap_name.c_str(), ap_passwd);
    }

    esp_info = "{\"STA\":{\"SSID\":\"";
    esp_info += (String)ssid;
    esp_info += "\",\"PASSWD\":\"";
    esp_info += (String)passwd;
    esp_info += "\",\"IP\":\"";
    esp_info += localIP;
    esp_info += "\"},\"AP\":{\"SSID\":\"";
    esp_info += (String)ap_ssid;
    esp_info += "\",\"PASSWD\":\"";
    esp_info += (String)ap_passwd;
    esp_info += "\",\"IP\":\"";
    esp_info += WiFi.softAPIP().toString();
    esp_info += "\"},\"version\":\"";
    esp_info += (String)SPIDER_VERSION;
    esp_info += "\",\"mdns\":\"";
    esp_info += (String)mdns;
    esp_info += "\",\"MAC\":\"";
    esp_info += WiFi.macAddress();
    esp_info += "\"}";

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
    // https://tomeko.net/online_tools/file_to_hex.php?lang=en

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/html", html_index_html, HTML_INDEX_HTML_LEN);
        request->send(response);
    });

    /* javascript */

    server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_main_js, HTML_MAIN_JS_LEN);
        request->send(response);
    });

    server.on("/value.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_value_js, HTML_VALUE_JS_LEN);
        request->send(response);
    });
    
    server.on("/websocket.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_websocket_js, HTML_WEBSOCKET_JS_LEN);
        request->send(response);
    });

    server.on("/wifi.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_wifi_js, HTML_WIFI_JS_LEN);
        request->send(response);
    });

    server.on("/github.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_github_js, HTML_GITHUB_JS_LEN);
        request->send(response);
    });

    /* css */

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", html_style_css, HTML_STYLE_CSS_LEN);
        request->send(response);
    });

    /* bootstrap */
    server.on("/bootstrap.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/javascript", html_bootstrap_js, HTML_BOOTSTRAP_JS_LEN);
        request->send(response);
    });

    server.on("/bootstrap.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "text/css", html_bootstrap_css, HTML_BOOTSTRAP_CSS_LEN);
        request->send(response);
    });

    /* Image */

    server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "image/jpg", favicon_jpg, FAVICON_JPG_LEN);
        request->send(response);
    });

    server.on("/img/favicon.jpg", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "image/jpg", favicon_jpg, FAVICON_JPG_LEN);
        request->send(response);
    });

    server.on("/img/spider.jpg", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebServerResponse *response = request->beginResponse_P(200, "image/jpg", spider_jpg, SPIDER_JPG_LEN);
        request->send(response);
    });

    /* Data */

    server.on("/set/info", HTTP_POST, [](AsyncWebServerRequest *request) {
        int error_code = set_server_post_eeprom_data(request);
        if(error_code) {
            Serial.printf("ESP32 Set data error: %d\n", error_code);
            request->send(200, "text/plain", "Error");
        } else {
            request->send(200, "text/plain", "OK");
            delay(1000);
            // ESP.restart();
        }
    });

    server.on("/ota/update", HTTP_POST, [](AsyncWebServerRequest *request) {
        AsyncWebParameter *param = request->getParam(0);
        String url = "";
        if(param->name().indexOf("url") >= 0) {
            url = param->value();
        }
        Serial.printf("ESP32 Github Url: %s\n", url.c_str());
        request->send(200, "text/plain", "susses");  
    });

    server.on("/get/info", HTTP_POST, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", esp_info);  
    });

    server.on("/system/reboot", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "susses");
        ESP.restart();
    });

    /* 404 */
    server.onNotFound([](AsyncWebServerRequest *request){
        request->send(404, "text/plain", "Spider BOT 404 NOT Found!");
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
    }

    return server_post_eeprom_data_error_code;
}
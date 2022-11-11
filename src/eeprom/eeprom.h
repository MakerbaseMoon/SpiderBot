/**
 *  0  ~  24 -> SSID
 *  25 ~  49 -> Password
 *  50 ~  74 -> AP SSID
 *  75 ~  99 -> AP Password
 * 100 ~ 124 -> mdns
 * 125       -> 11 OK
 */

#include <Arduino.h>
#include <EEPROM.h>

#include "default.h"

#define EEPROM_SSID_START        0
#define EEPROM_SSID_END         24

#define EEPROM_PASSWD_START     25
#define EEPROM_PASSWD_END       49

#define EEPROM_AP_SSID_START    50
#define EEPROM_AP_SSID_END      74

#define EEPROM_AP_PASSWD_START  75
#define EEPROM_AP_PASSWD_END    99

#define EEPROM_MDNS_START      100
#define EEPROM_MDNS_END        124

#define EEPROM_TOKEN_START     125
#define EEPROM_TOKEN_END       149

#define EEPROM_MOTOR_PIN_START 150
#define EEPROM_MOTOR_PIN_END   174

#define EEPROM_SPIFFS_UPDATE   250

/**
 * eeprom.cpp
 * 
 */
bool eeprom_setup(char** ssid, char** passwd, char** ap_ssid, char** ap_passwd, char** mdns);

bool set_esp_mdns    (const char*  mdns);
bool set_github_token(const char*  token);
bool get_esp_mdns    (char** mdns);
bool get_github_token(char** token);

bool set_eeprom_default();

/**
 * eeprom_sta.cpp
 * 
 */
bool set_ssid  (const char*  ssid);
bool set_passwd(const char*  passwd);
bool get_ssid  (char** ssid);
bool get_passwd(char** passwd);

/**
 * eeprom_ap.cpp
 * 
 */
bool set_ap_ssid  (const char*  ssid);
bool set_ap_passwd(const char*  passwd);
bool get_ap_ssid  (char** ssid);
bool get_ap_passwd(char** passwd);

/**
 * eeprom_data.cpp
 * 
 */
bool set_eeprom_data(int start, int end, uint8_t*  data);
bool get_eeprom_data(int start,          uint8_t** data);

bool is_eeprom_data(int start);

void show_eeprom_data(bool toChar);
void clean_eeprom_data();

/**
 * eeprom_update.cpp
 * 
 */
void    set_SPIFFS_update(uint8_t data); // 0 NO, 1 Yes
uint8_t get_SPIFFS_update();

/**
 * eeprom_motor_pin.cpp
 * 
 */
bool set_motor_pin(const char*  motor_pin);
bool get_motor_pin(char** motor_pin);

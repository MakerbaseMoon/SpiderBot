#include "eeprom/eeprom.h"

bool eeprom_setup(char** ssid, char** passwd, char** ap_ssid, char** ap_passwd, char** mdns) {
    if(!EEPROM.begin(128)) {
        Serial.printf("Error to start EEPROM\n");
        return false;
    }

    if(EEPROM.read(SPIDER_DEFAULT_OK_ADDRESS) != SPIDER_DEFAULT_OK_NUM) {
        set_eeprom_default();
    }

    if(!get_ssid(ssid)) {
        free(*ssid);
        *ssid = NULL;
    }

    if(!get_passwd(passwd)) {
        free(*passwd);
        *passwd = NULL;
    }

    if(!get_ap_ssid(ap_ssid)) {
        free(*ap_ssid);
        *ap_ssid = NULL;
    }

    if(!get_ap_passwd(ap_passwd)) {
        free(*ap_passwd);
        *ap_passwd = NULL;
    }

    if(!get_esp_mdns(mdns)) {
        free(*mdns);
        *mdns = NULL;
    }

    return true;
}

bool set_esp_mdns  (const char* mdns) {
    return set_eeprom_data(EEPROM_MDNS_START, EEPROM_MDNS_END, (uint8_t *)mdns);
}

bool set_github_token(const char* token) {
    return set_eeprom_data(EEPROM_TOKEN_START, EEPROM_TOKEN_END, (uint8_t *)token);
}

bool get_esp_mdns  (char**  mdns) {
    if(!is_eeprom_data(EEPROM_MDNS_START))
        return false;

    return get_eeprom_data(EEPROM_MDNS_START, (uint8_t **)mdns);
}

bool get_github_token(char** token) {
    if(!is_eeprom_data(EEPROM_TOKEN_START))
        return false;

    return get_eeprom_data(EEPROM_TOKEN_START, (uint8_t **)token);
}
bool set_eeprom_default() {
    clean_eeprom_data();

    EEPROM.write(SPIDER_DEFAULT_OK_ADDRESS, SPIDER_DEFAULT_OK_NUM);
    EEPROM.commit();

    #ifdef SPIDER_STA_SSID

    set_ssid(SPIDER_STA_SSID);

    set_passwd(SPIDER_STA_PASSWD);

    #else

    set_ssid(SPIDER_DEFAULT_STA_SSID);

    set_passwd(SPIDER_DEFAULT_STA_PASSWD);

    #endif

    set_ap_ssid(SPIDER_DEFAULT_AP_SSID);

    set_ap_passwd(SPIDER_DEFAULT_AP_PASSWD);

    set_esp_mdns(SPIDER_DEFAULT_MDNS);

    return true;
}
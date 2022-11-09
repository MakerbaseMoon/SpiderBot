#include "eeprom/eeprom.h"

bool set_ap_ssid  (const char* ssid) {
    return set_eeprom_data(EEPROM_AP_SSID_START, EEPROM_AP_SSID_END, (uint8_t *)ssid);
}

bool set_ap_passwd(const char* passwd) {
    return set_eeprom_data(EEPROM_AP_PASSWD_START, EEPROM_AP_PASSWD_END, (uint8_t *)passwd);
}

bool get_ap_ssid  (char**  ssid) {
    if(!is_eeprom_data(EEPROM_AP_SSID_START))
        return false;

    return get_eeprom_data(EEPROM_AP_SSID_START, (uint8_t **)ssid);
}

bool get_ap_passwd(char** passwd) {
    if(!is_eeprom_data(EEPROM_AP_PASSWD_START))
        return false;

    return get_eeprom_data(EEPROM_AP_PASSWD_START, (uint8_t **)passwd);
}

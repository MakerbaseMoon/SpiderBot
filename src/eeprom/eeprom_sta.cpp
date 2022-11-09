#include "eeprom/eeprom.h"

bool set_ssid  (const char* ssid) {
    return set_eeprom_data(EEPROM_SSID_START, EEPROM_SSID_END, (uint8_t *)ssid);
}

bool set_passwd(const char* passwd) {
    return set_eeprom_data(EEPROM_PASSWD_START, EEPROM_PASSWD_END, (uint8_t *)passwd);
}

bool get_ssid  (char**  ssid) {
    if(!is_eeprom_data(EEPROM_SSID_START))
        return false;

    return get_eeprom_data(EEPROM_SSID_START, (uint8_t **)ssid);
}

bool get_passwd(char** passwd) {
    if(!is_eeprom_data(EEPROM_PASSWD_START))
        return false;

    return get_eeprom_data(EEPROM_PASSWD_START, (uint8_t **)passwd);
}

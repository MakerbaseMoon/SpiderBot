#include "eeprom/eeprom.h"

bool set_eeprom_data(int start, int end, uint8_t* data) {
    int len = end - start + 1;
    
    if(len <= 0 || end > 255) 
        return false;

    size_t data_len = 0;
    while(*(data + data_len++));

    if(data_len > len) 
       return false;

    size_t i = 0;

    while(i < len) {
        uint8_t _data = *(data + i);

        if(_data == 0) {
            EEPROM.write(start + i++, 0);
            break;
        }

#ifdef ESP32_KEY
        _data ^= ESP32_KEY;
#endif

#ifdef ESP32_KEY_2
        _data ^= ESP32_KEY_2;
#endif

#ifdef ESP32_KEY_3
        _data ^= ESP32_KEY_3;
#endif

        EEPROM.write(start + i++, _data);
    }

    while(i < len)
        EEPROM.write(start + i++, 255);

    EEPROM.commit();
    return true;
}

bool get_eeprom_data(int start, uint8_t** data) {
    size_t i = start;

    while(!EEPROM.read(i) || EEPROM.read(i) != 255)
        i++;

    size_t data_len = i - start - 1;

    *data = (uint8_t *)malloc(i * sizeof(uint8_t));

    if(data == NULL)
        return false;

    *(*data + data_len) = 0;

    for(i = 0; i < data_len; i++) {
        uint8_t _data = EEPROM.read(i + start);

#ifdef ESP32_KEY
        _data ^= ESP32_KEY;
#endif

#ifdef ESP32_KEY_2
        _data ^= ESP32_KEY_2;
#endif

#ifdef ESP32_KEY_3
        _data ^= ESP32_KEY_3;
#endif

        *(*data + i) = _data;
    }

    return true;
}

bool is_eeprom_data(int start) {
    if(!EEPROM.read(start) || EEPROM.read(start) == 255)
        return false;
    
    return true;
}

void show_eeprom_data(bool toChar = false) {
#ifdef ESP32_CLEANER_SHOW_DEBUG
    for(size_t i = 0; i < 255; i++) {
        uint8_t _data = EEPROM.read(i);

#ifdef ESP32_KEY
        _data ^= ESP32_KEY;
#endif

#ifdef ESP32_KEY_2
        _data ^= ESP32_KEY_2;
#endif

#ifdef ESP32_KEY_3
        _data ^= ESP32_KEY_3;
#endif

        if(!(i % 10))
            Serial.printf("\n");
        if(toChar)
            Serial.printf("%c, ", (char)_data);
        else
            Serial.printf("%d, ", (int)_data);
    }
    Serial.printf("\n");
#endif
}

void clean_eeprom_data() {
    for(size_t i = 0; i < 255; i++)
        EEPROM.write(i, 255);

    EEPROM.commit();
}

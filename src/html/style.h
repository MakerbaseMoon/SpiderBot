#include <Arduino.h>

#define HTML_STYLE_CSS_LEN 225
 
const uint8_t html_style_css[] PROGMEM = {
    0x68, 0x74, 0x6D, 0x6C, 0x2C, 0x62, 0x6F, 0x64, 0x79, 0x7B, 0x70, 0x61, 0x64, 0x64, 0x69, 0x6E, 
    0x67, 0x3A, 0x30, 0x70, 0x78, 0x3B, 0x6D, 0x61, 0x72, 0x67, 0x69, 0x6E, 0x3A, 0x30, 0x70, 0x78, 
    0x3B, 0x7D, 0x6D, 0x61, 0x69, 0x6E, 0x7B, 0x62, 0x61, 0x63, 0x6B, 0x67, 0x72, 0x6F, 0x75, 0x6E, 
    0x64, 0x2D, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x72, 0x67, 0x62, 0x28, 0x31, 0x38, 0x39, 0x2C, 
    0x31, 0x35, 0x31, 0x2C, 0x32, 0x30, 0x36, 0x29, 0x3B, 0x7D, 0x70, 0x7B, 0x6C, 0x69, 0x6E, 0x65, 
    0x2D, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x3A, 0x31, 0x30, 0x70, 0x78, 0x3B, 0x7D, 0x66, 0x6F, 
    0x6F, 0x74, 0x65, 0x72, 0x7B, 0x62, 0x61, 0x63, 0x6B, 0x67, 0x72, 0x6F, 0x75, 0x6E, 0x64, 0x2D, 
    0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x72, 0x67, 0x62, 0x28, 0x31, 0x35, 0x35, 0x2C, 0x32, 0x30, 
    0x32, 0x2C, 0x32, 0x31, 0x36, 0x29, 0x3B, 0x7D, 0x2E, 0x69, 0x6D, 0x67, 0x5F, 0x73, 0x70, 0x69, 
    0x64, 0x65, 0x72, 0x7B, 0x77, 0x69, 0x64, 0x74, 0x68, 0x3A, 0x34, 0x30, 0x76, 0x77, 0x3B, 0x7D, 
    0x2E, 0x69, 0x6D, 0x67, 0x5F, 0x63, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x7B, 0x68, 0x65, 0x69, 
    0x67, 0x68, 0x74, 0x3A, 0x61, 0x75, 0x74, 0x6F, 0x3B, 0x7D, 0x23, 0x73, 0x65, 0x74, 0x74, 0x69, 
    0x6E, 0x67, 0x2C, 0x23, 0x75, 0x70, 0x67, 0x72, 0x61, 0x64, 0x65, 0x7B, 0x63, 0x6F, 0x6C, 0x6F, 
    0x72, 0x3A, 0x72, 0x67, 0x62, 0x28, 0x34, 0x37, 0x2C, 0x35, 0x38, 0x2C, 0x35, 0x38, 0x29, 0x3B, 
    0x7D
};
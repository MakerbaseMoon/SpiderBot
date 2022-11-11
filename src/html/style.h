#include <Arduino.h>

#define HTML_STYLE_CSS_LEN 339
 
const uint8_t html_style_css[] PROGMEM = {
    0x68, 0x74, 0x6D, 0x6C, 0x2C, 0x62, 0x6F, 0x64, 0x79, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 
    0x20, 0x70, 0x61, 0x64, 0x64, 0x69, 0x6E, 0x67, 0x3A, 0x20, 0x30, 0x70, 0x78, 0x3B, 0x0D, 0x0A, 
    0x20, 0x20, 0x20, 0x20, 0x6D, 0x61, 0x72, 0x67, 0x69, 0x6E, 0x3A, 0x20, 0x30, 0x70, 0x78, 0x3B, 
    0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x6D, 0x61, 0x69, 0x6E, 0x20, 0x7B, 0x20, 0x0D, 0x0A, 
    0x20, 0x20, 0x20, 0x20, 0x62, 0x61, 0x63, 0x6B, 0x67, 0x72, 0x6F, 0x75, 0x6E, 0x64, 0x2D, 0x63, 
    0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x20, 0x72, 0x67, 0x62, 0x28, 0x31, 0x35, 0x30, 0x2C, 0x20, 0x32, 
    0x32, 0x36, 0x2C, 0x20, 0x31, 0x38, 0x34, 0x29, 0x3B, 0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 
    0x70, 0x20, 0x7B, 0x20, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x6C, 0x69, 0x6E, 0x65, 0x2D, 0x68, 
    0x65, 0x69, 0x67, 0x68, 0x74, 0x3A, 0x20, 0x31, 0x30, 0x70, 0x78, 0x3B, 0x0D, 0x0A, 0x7D, 0x0D, 
    0x0A, 0x0D, 0x0A, 0x66, 0x6F, 0x6F, 0x74, 0x65, 0x72, 0x20, 0x7B, 0x20, 0x0D, 0x0A, 0x20, 0x20, 
    0x20, 0x20, 0x62, 0x61, 0x63, 0x6B, 0x67, 0x72, 0x6F, 0x75, 0x6E, 0x64, 0x2D, 0x63, 0x6F, 0x6C, 
    0x6F, 0x72, 0x3A, 0x20, 0x72, 0x67, 0x62, 0x28, 0x31, 0x35, 0x35, 0x2C, 0x20, 0x32, 0x30, 0x32, 
    0x2C, 0x20, 0x32, 0x31, 0x36, 0x29, 0x3B, 0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x2E, 0x69, 
    0x6D, 0x67, 0x5F, 0x73, 0x70, 0x69, 0x64, 0x65, 0x72, 0x20, 0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 
    0x20, 0x77, 0x69, 0x64, 0x74, 0x68, 0x3A, 0x20, 0x34, 0x30, 0x76, 0x77, 0x3B, 0x0D, 0x0A, 0x0D, 
    0x0A, 0x7D, 0x0D, 0x0A, 0x2E, 0x69, 0x6D, 0x67, 0x5F, 0x63, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 
    0x20, 0x7B, 0x20, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x68, 0x65, 0x69, 0x67, 0x68, 0x74, 0x3A, 
    0x20, 0x61, 0x75, 0x74, 0x6F, 0x3B, 0x0D, 0x0A, 0x7D, 0x0D, 0x0A, 0x0D, 0x0A, 0x23, 0x73, 0x65, 
    0x74, 0x74, 0x69, 0x6E, 0x67, 0x2C, 0x20, 0x23, 0x75, 0x70, 0x67, 0x72, 0x61, 0x64, 0x65, 0x20, 
    0x7B, 0x0D, 0x0A, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6F, 0x6C, 0x6F, 0x72, 0x3A, 0x20, 0x72, 0x67, 
    0x62, 0x28, 0x34, 0x37, 0x2C, 0x20, 0x35, 0x38, 0x2C, 0x20, 0x35, 0x38, 0x29, 0x3B, 0x0D, 0x0A, 
    0x7D, 0x0D, 0x0A
};

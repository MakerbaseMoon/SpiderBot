let websocket;

const forward      = document.getElementById("forward");
const left         = document.getElementById("left");
const car_Stop     = document.getElementById("stop");
const right        = document.getElementById("right");
const back         = document.getElementById("back");

const setting      = document.getElementById("setting");
const upgrade      = document.getElementById("upgrade");

const setting_form = document.getElementById("setting_form");
const upgrade_form = document.getElementById("upgrade_form");

const esp_version_tag   = document.getElementById("esp_version_tag");
const version_tag       = document.getElementById("version_tag");
const version_body      = document.getElementById("version_body");
const ota_update_btn    = document.getElementById("ota_update_btn");

const version_input         = document.getElementById("version_input");
const mac_input             = document.getElementById("mac_input");
const wifi_sta_ssid_input   = document.getElementById("wifi_sta_ssid_input");
const wifi_sta_passwd_input = document.getElementById("wifi_sta_passwd_input");
const wifi_sta_ip_input     = document.getElementById("wifi_sta_ip_input");
const wifi_ap_ssid_input    = document.getElementById("wifi_ap_ssid_input");
const wifi_ap_passwd_input  = document.getElementById("wifi_ap_passwd_input");
const wifi_ap_ip_input      = document.getElementById("wifi_ap_ip_input");
const mdns_input            = document.getElementById("mdns_input");

const eeprom_btn            = document.getElementById("eeprom_btn");
const restart_btn           = document.getElementById("restart_btn");

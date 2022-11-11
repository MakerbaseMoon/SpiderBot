function get_esp_info_data() {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/get/info`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            console.log(data);
            my_esp_data = data;

            version_input.value = data.version;
            mac_input.    value = data.MAC;

            wifi_sta_ssid_input.  placeholder = data.STA.SSID;
            wifi_sta_passwd_input.placeholder = data.STA.PASSWD;
            wifi_sta_ip_input    .value       = data.STA.IP;

            wifi_ap_ssid_input.   placeholder = data.AP. SSID;
            wifi_ap_passwd_input. placeholder = data.AP. PASSWD;
            wifi_ap_ip_input.     value       = data.AP. IP;

            mdns_input.           placeholder = data.mdns;

            esp_version_tag.innerText = "ESP32 NOW Version: " + data.version;
        });
    } catch(e) {

    }
}

function set_esp_eeprom_data(ssid, passwd, ap_ssid, ap_passwd, mdns) {
    try {
        eeprom_restart_btn.disabled = true;
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/set/info`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        let data = `0=${ssid}&1=${passwd}&2=${ap_ssid}&3=${ap_passwd}&4=${mdns}`;
        request.send(data);
        request.addEventListener("load", () => {
            eeprom_restart_btn.disabled = false;
            eeprom_restart_span.innerText = "資料上傳完畢 是否要重啟？";
            console.log(request.responseText);
        });
    } catch(e) {

    }
}

eeprom_btn.addEventListener('click', update_data_click);

restart_btn.addEventListener('click', esp_restart);

eeprom_restart_btn.addEventListener('click', esp_restart);

function esp_restart() {
    let request = new XMLHttpRequest();
    request.open("GET", `${window.location.origin}/system/reboot`, true);
    request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    request.send();
    request.addEventListener("load", () => {
        console.log(request.responseText);
    });
}

function update_data_click() {
    let ssid        = (wifi_sta_ssid_input.  value == "")? wifi_sta_ssid_input.  placeholder :wifi_sta_ssid_input.  value;
    let passwd      = (wifi_sta_passwd_input.value == "")? wifi_sta_passwd_input.placeholder :wifi_sta_passwd_input.value;
    let ap_ssid     = (wifi_ap_ssid_input.   value == "")? wifi_ap_ssid_input.   placeholder :wifi_ap_ssid_input.   value;
    let ap_passwd   = (wifi_ap_passwd_input. value == "")? wifi_ap_passwd_input. placeholder :wifi_ap_passwd_input. value;
    let mdns        = (mdns_input.           value == "")? mdns_input.           placeholder :mdns_input.           value;
    set_esp_eeprom_data(ssid, passwd, ap_ssid, ap_passwd, mdns);
}
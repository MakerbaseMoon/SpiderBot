function get_esp_info_data() {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/get/info`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            my_esp_data = data;

        });
    } catch(e) {

    }
}

function set_esp_eeprom_data(ssid, passwd, ap_ssid, ap_passwd, mdns) {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/set/info`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        let data = `0=${ssid}&1=${passwd}&2=${ap_ssid}&3=${ap_passwd}&4=${mdns}`;
        request.send(data);
        request.addEventListener("load", () => {
            console.log(request.responseText);
        });
    } catch(e) {

    }
}

function update_data_click() {
    let ssid = null;
    let passwd = null;
    let ap_ssid = null;
    let ap_passwd = null;
    let mdns = null;
    set_esp_eeprom_data(ssid, passwd, ap_ssid, ap_passwd, mdns) 
}
function get_esp_info_data() {
    try {
        let request = new XMLHttpRequest();
        request.open("POST", `${window.location.origin}/get/info`, true);
        request.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        request.send();
        request.addEventListener("load", () => {
            let data = JSON.parse(request.responseText);
            console.log(data);
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

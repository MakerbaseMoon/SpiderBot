# Spider Bot (蜘蛛機器人)
![](https://img.shields.io/badge/version-v0.2.0-blue) ![](https://img.shields.io/badge/platformIO%20core-6.1.5-orange) ![](https://img.shields.io/badge/Espressif%2032-5.1.1-green)<br>
ESP32 蜘蛛機器人 - 第一代 <br>
This is the Spider Bot project for maker. <br>
<img src="https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.0.1/spider.jpg"></img>

* Group: 望月智聯網研究團隊
* Member: [jlhsu666](https://github.com/jlhsu666), [Hsun1031](https://github.com/Hsun1031), [Reaxoh](https://github.com/Reaxoh)

## git command (git 指令)

```
git clone https://github.com/MakerbaseMoon/SpiderBot.git
git submodule update --init --recursive
``` 

## project files (專案檔案)

```
┌───.vscode
│       c_cpp_properties.json
│       extensions.json
│       launch.json
│       settings.json
│
├───data
│       bootstrap.bundle.js
│       bootstrap.css
│       bootstrap.js
│
├───html
│   │   index.html
│   │
│   ├───css
│   │       style.css
│   │
│   ├───img
│   │       favicon.jpg
│   │       spider.jpg
│   │
│   └───js
│           github.js
│           main.js
│           value.js
│           websocket.js
│           wifi.js
│
├───include
├───lib
│   ├───Adafruit-PWM-Servo-Driver-Library
│   ├───AsyncTCP
│   ├───ESP32GithubOTA
│   └───ESPAsyncWebServer
│
├───src
│   │   main.cpp
│   │
│   ├───eeprom
│   │       default.h
│   │       eeprom.cpp
│   │       eeprom.h
│   │       eeprom_ap.cpp
│   │       eeprom_data.cpp
│   │       eeprom_sta.cpp
│   │
│   ├───html
│   │       image.h
│   │       index.h
│   │       javascript.h
│   │       style.h
│   │
│   ├───internet
│   │       internet.cpp
│   │       internet.h
│   │
│   └───module
│           servos.cpp
│           servos.h
│
├───test
│       README
│
│   .gitignore
│   .gitmodules
│   platformio.ini
└─  README.md
```

## ESP32 Development Environments (ESP32 開發工具及環境)

* Install CP210x USB to UART Bridge VCP
  * <https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers>
* Install Visual Studio Code
  * <https://code.visualstudio.com/download>
* Connect to ESP32 website
  * <https://github.com/espressif/arduino-esp32>

## project libraries (專案 libraries)
* ESP32GithubOTA
  * <https://github.com/Hsun1031/ESP32GithubOTA>
* AsyncTCP-master
  * <https://github.com/me-no-dev/AsyncTCP>
* ESPAsyncWebServer-master
  * <https://github.com/me-no-dev/ESPAsyncWebServer>
* Adafruit-PWM-Servo-Driver-Library
  * <https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library>

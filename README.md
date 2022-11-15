# Spider Bot (蜘蛛機器人)
![](https://img.shields.io/badge/version-v0.2.5-blue) ![](https://img.shields.io/badge/platformIO%20core-6.1.5-orange) ![](https://img.shields.io/badge/Espressif%2032-5.1.1-green)<br>
ESP32 蜘蛛機器人 - 第一代 <br>
This is the Spider Bot project for maker. <br>
<img src="https://github.com/MakerbaseMoon/SpiderBot/releases/download/v0.2.5/spider.jpg"></img>

<h2>Group:&nbsp;<svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-moon-stars" viewBox="0 0 16 16"><path d="M6 .278a.768.768 0 0 1 .08.858 7.208 7.208 0 0 0-.878 3.46c0 4.021 3.278 7.277 7.318 7.277.527 0 1.04-.055 1.533-.16a.787.787 0 0 1 .81.316.733.733 0 0 1-.031.893A8.349 8.349 0 0 1 8.344 16C3.734 16 0 12.286 0 7.71 0 4.266 2.114 1.312 5.124.06A.752.752 0 0 1 6 .278zM4.858 1.311A7.269 7.269 0 0 0 1.025 7.71c0 4.02 3.279 7.276 7.319 7.276a7.316 7.316 0 0 0 5.205-2.162c-.337.042-.68.063-1.029.063-4.61 0-8.343-3.714-8.343-8.29 0-1.167.242-2.278.681-3.286z"/><path d="M10.794 3.148a.217.217 0 0 1 .412 0l.387 1.162c.173.518.579.924 1.097 1.097l1.162.387a.217.217 0 0 1 0 .412l-1.162.387a1.734 1.734 0 0 0-1.097 1.097l-.387 1.162a.217.217 0 0 1-.412 0l-.387-1.162A1.734 1.734 0 0 0 9.31 6.593l-1.162-.387a.217.217 0 0 1 0-.412l1.162-.387a1.734 1.734 0 0 0 1.097-1.097l.387-1.162zM13.863.099a.145.145 0 0 1 .274 0l.258.774c.115.346.386.617.732.732l.774.258a.145.145 0 0 1 0 .274l-.774.258a1.156 1.156 0 0 0-.732.732l-.258.774a.145.145 0 0 1-.274 0l-.258-.774a1.156 1.156 0 0 0-.732-.732l-.774-.258a.145.145 0 0 1 0-.274l.774-.258c.346-.115.617-.386.732-.732L13.863.1z"/></svg>&nbsp;望月智聯網研究團隊</h2>

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
│       bootstrap.bundle.min.js.gz
│       bootstrap.css.gx
│
├───html
│   │
│   ├───css
│   │       style.css
│   │
│   ├───img
│   │       favicon.jpg
│   │       spider.jpg
│   │
│   ├───js
│   │       github.js
│   │       main.js
│   │       value.js
│   │       websocket.js
│   │       wifi.js
│   │
│   └   index.html
│
├───include
│       README
│       
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

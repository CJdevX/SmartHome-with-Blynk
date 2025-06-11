# 🔌 Blynk IoT Project

This project uses the Blynk platform to control or monitor an IoT device via a mobile application. The Arduino sketch provided is configured to connect to Wi-Fi and communicate with Blynk's cloud to perform specific tasks, such as controlling actuators or reading sensor data.

![Blynk](https://cdn.prod.website-files.com/6273cea8a22e45db8b446533/66bf995de590a7bd260f5f8f_6698e2dc950e9e62fb4d63e6_1-02.png)
---

## 📱 What is Blynk?

[Blynk](https://blynk.io/) is a platform that allows you to build IoT apps for smartphones to control microcontrollers like Arduino, ESP8266, ESP32, etc., over the internet. It provides a simple and user-friendly interface to interact with hardware in real-time using virtual pins and widgets.

---

## 🧰 Requirements

### Hardware
- ESP8266 / ESP32 board (NodeMCU, Wemos D1 Mini, etc.)
- Micro-USB cable
- Wi-Fi connection
- Any sensors/actuators used in the sketch

### Software
- Arduino IDE (v1.8+ or Arduino 2.0)
- Blynk IoT App (iOS / Android)
- Blynk Libraries

---

## 🛠️ Environment Setup

### 1. Install Arduino IDE
Download and install the Arduino IDE from: https://www.arduino.cc/en/software

### 2. Install Board Manager for ESP8266
Go to: File > Preferences > Additional Board URLs <br>
Add the following URL:

**Nodemcu**
```bash
http://arduino.esp8266.com/stable/package_esp8266com_index.json
```

**ESP32**
```bash
https://espressif.github.io/arduino-esp32/package_esp32_index.json
```

**ESP32 MH-ET Live**
```bash
https://dl.espressif.com/dl/package_esp32_index.json
```

### 3. Add the Board
Go to: Tools > Board > Boards Manager <br>
Search for **ESP8266/ESP32** and install the latest version.

### 4. Install Blynk Library
Go to: Sketch > Include Library > Manage Libraries <br>
Search for **Blynk** and install it.

---

## 🔧 How to Use

### 1. Create a Blynk Account
- Download the Blynk app from the Play Store or App Store
- Register and create a new project
- Choose the device type (e.g., ESP8266) and connection type (WiFi)
- An **Auth Token** will be sent to your email

### 2. Configure the Sketch

Replace the placeholders in the sketch:

```bash
define BLYNK_TEMPLATE_ID "YourTemplateID"          // Replace with your Template ID
define BLYNK_TEMPLATE_NAME "YourDeviceName"        // Replace with your Device Name
define BLYNK_AUTH_TOKEN "YourAuthToken"            // Replace with your Blynk Auth Token

const char* ssid = "YourWiFiSSID";                 // Replace with your WiFi name
const char* password = "YourWiFiPassword";         // Replace with your WiFi password
```

### 3. Connect the Board
Select the correct board and port: <br>
Tools > Board > NodeMCU 1.0 (or your board)
Tools > Port > COMx (your device port)
Upload the sketch

### 4. Open Serial Monitor
Check the Serial Monitor for debug messages and connection status.

---

## 📲 Using the Blynk App
- Add widgets in the Blynk app (e.g., Button, Slider, Terminal, etc.)
- Bind them to Virtual Pins (V0, V1, ...) used in your code
- Run the project and control your device from anywhere

## 🧪 Example Use Cases
- Home automation (switch lights, fans, etc.)
- Monitor temperature, humidity, or motion
- Send notifications or alerts

## ⚠️ Notes
- Make sure your board is connected to a 2.4GHz WiFi network.
- Double-check the Auth Token and WiFi credentials before uploading.
- Avoid using long delays inside loop or Blynk callbacks, as it affects cloud sync.

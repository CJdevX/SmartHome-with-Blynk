#define BLYNK_TEMPLATE_ID "Your TemplateID"                    // Blynk Template ID
#define BLYNK_TEMPLATE_NAME "Your Template Name"                     // Blynk Device Name
#define BLYNK_AUTH_TOKEN "Your Auth Token"  // Blynk Auth Token

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <BluetoothSerial.h>

BluetoothSerial BT;

const char* ssid = "Your SSID";
const char* password = "Your Password";

#define WIFI_LED 2

#define LED_PIN1 12
#define LED_PIN2 13
#define LED_PIN3 14

#define RELAY_PIN1 16
#define RELAY_PIN2 17
#define RELAY_PIN3 18
#define RELAY_PIN4 19

void setup() {
  Serial.begin(115200);

  // WiFi LED
  pinMode(WIFI_LED, OUTPUT);

  // RGB LED Pin
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);

  // Relay Pin
  pinMode(RELAY_PIN1, OUTPUT);
  pinMode(RELAY_PIN2, OUTPUT);
  pinMode(RELAY_PIN3, OUTPUT);
  pinMode(RELAY_PIN4, OUTPUT);

  //  digitalWrite(LED_PIN1, LOW);
  //  digitalWrite(LED_PIN2, LOW);
  //  digitalWrite(LED_PIN3, LOW);
  //
  //  digitalWrite(RELAY_PIN1, LOW);
  //  digitalWrite(RELAY_PIN2, LOW);
  //  digitalWrite(RELAY_PIN3, LOW);
  digitalWrite(RELAY_PIN4, LOW);

  // Connect to WiFi or Bluetooth
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    if (WiFi.status() = WL_CONNECTED) {
      delay(100);
      digitalWrite(WIFI_LED, HIGH);
      Serial.print(".");
      delay(100);
      digitalWrite(WIFI_LED, LOW);
      Serial.print(".");
    } else {
      BT.begin('Smart Home');
      Serial.println("Bluetooth is ready. You can pair your device!");
    }
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  Serial.println("\nWiFi Connected");
}

void loop() {
  Blynk.run();
}

// Relay Actions
BLYNK_WRITE(V0) {
  int state = param.asInt();
  digitalWrite(RELAY_PIN1, state);
}

BLYNK_WRITE(V1) {
  int state = param.asInt();
  digitalWrite(RELAY_PIN2, state);
}

BLYNK_WRITE(V2) {
  int state = param.asInt();
  digitalWrite(RELAY_PIN3, state);
}

BLYNK_WRITE(V3) {
  int state = param.asInt();
  digitalWrite(RELAY_PIN4, state);
}
// =============================== //

// RGB LED Actions
BLYNK_WRITE(V4) {
  int state = param.asInt();
  analogWrite(LED_PIN1, state);
}

BLYNK_WRITE(V5) {
  int state = param.asInt();
  analogWrite(LED_PIN2, state);
}

BLYNK_WRITE(V6) {
  int state = param.asInt();
  analogWrite(LED_PIN3, state);
}
// =============================== //

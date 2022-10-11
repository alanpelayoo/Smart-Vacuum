#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include "config.h"
#include "ESP8266_Utils.hpp"
#include "API.hpp"

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.println(" ");
    delay(10);
    ConnectWiFi_STA();
}

void loop() {
  // put your main code here, to run repeatedly:
  get_all();
  delay(1000);
  get_id("1/");
   delay(1000);
}

#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
//#include <led.h>

const char* ssid = "b4871e";
const char* pass = "277123586";

HTTPClient http;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(200);
  }
}

void loop () {
  if (WiFi.status() == WL_CONNECTED) {
    http.begin("https://api.kawalcorona.com/indonesia/");
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(2000);
}

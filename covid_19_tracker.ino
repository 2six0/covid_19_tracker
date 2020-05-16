#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
//#include <led.h>

const char* ssid = "b4871e";
const char* pass = "277123586";

HTTPClient http;

const size_t capacity = JSON_ARRAY_SIZE(2) + JSON_OBJECT_SIZE(3);

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECT BOSSS");
}

void loop () {
  http.begin("https://api.kawalcorona.com/indonesia/provinsi/");
  int httpCode = http.GET();

  if (httpCode > 0)
  {
    char json[500];
    const char* payload = http.getString();
    StaticJsonDocument<256> doc;
    payload.toCharArray(doc, json);
    deserializeJson(doc,json);
    const char* tanggal = doc["update"];
    int umur = doc["sembuh"];

    Serial.println("tanggal",tanggal);
    
  }
  
  http.end();
  delay(2000);

 // test_led(2,200);
}

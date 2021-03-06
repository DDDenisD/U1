#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

WiFiUDP rc_ap;
IPAddress server(192, 168, 1, 10);

const String ssid = "LOX_Point";
const String password = "TryToKnowIt";

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
  myesp.begin(80);
}

void loop() {
  String InputSring = "";

  while (Serial.available() > 0) {
    int inChar =  Serial.read();
    InputString = InputString  + (char)inChar;
    if (inChar == '/n') {
      Serial.print("It was sand: ");
      Serial.println(InputString);
      rc_ap.beginPacket(user, 80);
      rc_ap.print(InputString);
      rc_ap.print("\r");
      rc_ap.endPacket();
      InputString = "";
    }
  }
}

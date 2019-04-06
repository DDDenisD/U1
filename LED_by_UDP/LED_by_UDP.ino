#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

WiFiUDP rc_ap;
IPAddress server(192, 168, 4, 1);
IPAddress SR(192, 168, 4, 3);

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
  rc_ap.begin(80);
}


String InString;
int L;

void loop() {

  while (Serial.available() > 0) {
    int inChar =  Serial.read();
    char V =  (char)inChar;
    InString = InString + V;
    if (Serial.available() == 0) {
      Serial.print("It was send: ");
      Serial.println(InString);
      rc_ap.beginPacket(server, 80);
      rc_ap.print(InString);
      rc_ap.print("\r");
      rc_ap.endPacket();
      rc_ap.beginPacket(SR, 80);
      rc_ap.print(InString);
      rc_ap.print("\r");
      rc_ap.endPacket();
      
      InString = "";

    }
  }




}

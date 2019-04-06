#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>


const char *ssid = "LOX_Point";
const char *password = "TryToKnowIt";

WiFiUDP myesp;

void setup() {
  pinMode(D0, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  myesp.begin(80);
}

char incomingPacket[255];

void loop() {

  String text1 = "ON";
  String text2 = "OFF";
  String AN;
  bool R;

  int packetSize = myesp.parsePacket();
  if (packetSize) {
    int len = myesp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    AN = incomingPacket;
    Serial.printf("incoming packet: %s\n", incomingPacket);
  }
  if (text1 == AN) {
    R = 1;
  }
  if (text2 == AN) {
    R = 0;
  }
  if (R) {
    digitalWrite(D0, HIGH);
  }
  else {
    digitalWrite(D0, LOW);
  }

}


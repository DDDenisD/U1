#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>


const char *ssid = "LOX_Point";
const char *password = "TryToKnowIt";

WiFiUDP myesp;

void setup() {
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
  int packetSize = myesp.parsePacket();
  if (packetSize) {
    int len = myesp.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    String answer = incomingPacket;
    Serial.printf("incoming packet: %s\n", incomingPacket);
  }
}


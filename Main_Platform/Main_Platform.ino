#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>

// main platform

const char *ssid = "CHAT_Point";
const char *password = "DoNotTryToConnect";

WiFiUDP ESP;

int M;
String IP;
int Num;

void Lunch(int L) {
  for (int i = L; i > 0; i--) {
    String D = "S" + (char)i;
    IPAddress &D(192, 168, 4, i);
  }
}

int Hug(String J) {
  int S = 0;
  String L;
  int F = 0;
  while (S == 0) {
    if (F < 256) {
      F++;
    }
    else {
      F = 1;
    }
    L = "192, 168, 4, " + (char)F;
    if (L == J) {
      S = F;
    }
  }
  return S;
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("How many people in the chat%?");
  while (Serial.available == 0);
  M = Serial.read();
  Lunch(M);
  delay(1000);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  ESP.begin(80);
  delay(1000);
  IP = WiFi.softAPIP();
  Num = Hug(IP);
  Serial.println("Your number is ");
  Serial.print(Num);
  Serial.println;
}

char incomingPacket[255];

void loop() {

  String AN;

  int packetSize = ESP.parsePacket();
  if (packetSize) {
    int len = ESP.read(incomingPacket, 255);
    if (len > 0) {
      incomingPacket[len] = 0;
    }
    AN = incomingPacket;
    Serial.printf("incoming packet: %s\n", incomingPacket);

  }
}

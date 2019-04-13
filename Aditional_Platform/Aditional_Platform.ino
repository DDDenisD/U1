#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>

// another platrform

const String ssid = "CHAT_Point";
const String password = "DoNotTryToConnect";

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
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
  ESP.begin(80);
  delay(1000);
  IP = WiFi.localIP();
  Num = Hug(IP);
  Serial.println("Your number is ");
  Serial.print(Num);
  Serial.println;
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
      ESP.beginPacket(S1, 80);
      ESP.print(InString);
      ESP.print("\r");
      ESP.endPacket();
      ESP.beginPacket(SR, 80);
      ESP.print(InString);
      ESP.print("\r");
      ESP.endPacket();

      InString = "";

    }
  }




}

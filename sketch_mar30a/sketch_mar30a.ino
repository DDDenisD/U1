#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

WiFiUDP myesp;
IPAddress server(192, 168, 1, 10);

const String ssid = "";
const String password = "";

void setup(){
  Serial.begin(115200);
  delay(100);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
  myesp.begin(80);
}

void loop(){
  Serial.println("Sanding the pack..");
  myesp.beginPacket(server, 80);
  mysep.print("Hello, we first send this string "Team_name" \r");
  myesp.endPacket();
  delay(10000);
}


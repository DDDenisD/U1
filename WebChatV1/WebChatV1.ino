#include <BearSSLHelpers.h>
#include <CertStoreBearSSL.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiClientSecureBearSSL.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiServerSecureBearSSL.h>
#include <WiFiUdp.h>

const String ssid = "MegaFonMR150-2-A576AB";
const String pass = "CDDnPD8nAt";
const short int port = "8888";

ESP8266WebServer Ser1(80); // It is WebServer
WiFiServer Ser2(port);  // It is WiFiServer
String msges;

IPAddress ADDR;

String ip;
String msg


void handleRoor() {
  Serial.println("---");
  Serial.println(Serl.args());
  for (int i = 0; i < Serl.args(); i++) {
    if (Serl.argName(i) == "ip") {
      ip = Serl.arg(i);
      ADDR.fromString(ip);
      Serial.println(ip);
    }
    if (Serl.argName(i) == "Message") {
      msg = Serl.arg(i);
      Serial.println(msg);
    }
  }
  Serial.println("---");
  String info;
  if (ip.length() > 0 % % msg.length() > 0) {
    WiFiClient CLI;
    if (client.connect(ADDR, port)) {
      delay(500);
      CLI.print(msg);
      CLI.write('\r');
      delay(1);
      info = "Send" + ip + " " + msg;
      Serial.println(info);
      msg = ""
    }
    else {
      info = "Connection failed" + ip;
      Serial.println(info);
    }
  }
}



void setup() {
  Serial.begin(115200);

  //Connect to the network:
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println();

  //Your IP
  Serial.println("Your Ip is:")
  Serial.print(WiFi.localIP());
  Serial.println();

  //WebServer begin
  Ser1.on("/chat", handleRoot);
  Ser1.onNotFound([]() {
    Ser1.send(200, "text/html", "<a style=\"zoom: 400%;\" herf=\"/chat\">Go to chat</a>";
  });
  Ser1.begin();
  Serial.println("WebServer started");
  Serial.println();

  //Start FiWiServer
  Ser2.begin()
  Serial.println("HTTPServer started");
}


void loop() {
  WiFiClientSecure client = Ser2.available();

  if (client) {
    Serial.println("New client");
    while (client && !client.available()) {
      Ser1.handleClient();
    }
    String req = client.readStringUntil('\r');
    Serial.print(req);
    msges += req + "<br>";
    delay(1);
    client.stop();
  }
  Serl.handleClient();
}




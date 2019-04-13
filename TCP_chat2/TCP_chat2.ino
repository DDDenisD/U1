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

String SID = "LOX_Point";
String PASS = "TryToKnowIt";

void setup() {
  Serial.begin(115200);
  delay(100);
  WiFi.begin(SID, PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("IP adress: ");
  Serial.println(WiFi.localIP());
}

const int port = 8888;
String msg = "Hello";
IPAddress addr(192, 168, 4, 1);

void loop() {
  WiFiClient KK;
  if (KK.connect(addr, port))
  {
    KK.print(msg);
    KK.write('\r');
    delay(100);
    KK.flush();
    KK.stop();
    Serial.println("send");
  }
  else {
    Serial.println("Connection failed");
  }
}

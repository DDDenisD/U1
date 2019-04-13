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

const char SID[] = "LOX_Point";
const char PASS[] = "TryToKnowIt";
const short int port = 8888;

WiFiServer SER(port);
IPAddress ser(192, 168, 4, 2);

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(SID, PASS);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  String msg = "";

  WiFiClient CLI;
  if (CLI.connect(ser, port)) {
    CLI.print(msg);
    CLI.write('\r');
    delay(5);
    CLI.flush();
    CLI.flush();
    CLI.stop();

    Serial.println("Sent");
  }
  else {
    Serial.println("fail");
  }

SER.begin();
  
}

void loop() {

  
  WiFiClient ZLE = SER.available();
  if (ZLE) {
    Serial.println("There is somebody, who wants to tell you something");
    while (ZLE && !ZLE.available()) {
      delay(2);
    }
    String incom = ZLE.readStringUntil('\r');
    Serial.println(incom);
    delay(5);
    ZLE.flush();
    ZLE.stop();
  }

  
}

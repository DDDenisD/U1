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

// It is ad platform

const String SSID = " " // There must be SSID
const String PASS = " " // There must be password for WiFi
short int II;
String NAME;

WiFiServer P(8888);


void setup(){
  Serial.begin(115200);
  delay(100);

  WiFiClient ZLE = P.available();
  if (ZLE) {
    while (ZLE && !ZLE.available()) {
      delay(2);
    }
    String incom = ZLE.readStringUntil('\r');
    delay(5);
    ZLE.flush();
    ZLE.stop();
  }

  II = (int)incom;

  IPAddress AI[II];
  delay(100);
  int PR = II - 1;
  
  for(PR; PR>-1; PR--){
    String IR = "192, 168, 4, " + (String)PR;
    AI[PR].fromString(IR);
  }

  delay(100);
  Serial.println("Pls, enter your name!);
  String INP;
  while(Serial.available() == 0);){
    INP = INP + Serial.read();
  }
  NAME = INP;
  delay(100);

  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(SID, PASS);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  delay(100);
  P.begin();
}

void loop(){

  String IN;
  String OUT;

  while(Serial.available()>0){
    OUT = OUT + Serial.read();
    if(Serial.available()=0){
      OUT = NAME + ": " + OUT;
      short int IO = II - 1;
      for(IO; IO>0; IO--){
        WiFiClient CLI;
        if (CLI.connect(I[IO], P)) {
          CLI.print(OUT);
          CLI.write('\r');
          delay(5);
          CLI.flush();
          CLI.stop();
        }
      }
      OUT = "";
      Serial.println("System: Looks like everything was sent...");
    }
  }



  WiFiClient ZLE = P.available();
  if (ZLE) {
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






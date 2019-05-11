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

// It is main platform

const String SID = " " // There must be SSID
const String PASS = " " // There must be password for WiFi
short int II;
String MyName;

WiFiServer P(8888);


void setup(){
  Serial.begin(115200);
  delay(100);

  Serial.println("How many people will be in chat%?");
  while(Serial.available() == 0);
  String R = "";
  while(Serial.available() > 0){
    R = R + Serial.read();
  }
  II = (int)R;
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
  while(Serial.available()>0){
    INP = INP + Serial.read();
  }
  MyName = INP;
  delay(100);

  Serial.println();
  Serial.print("System: configuring access point...");
  WiFi.softAP(SID, PASS);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("System: Your IP address: ");
  Serial.println(myIP);
  delay(100);
  
  P.begin();
  delay(100);
  
  
  short int TR[II];
  short int count = 0;
  short int IO = II - 1;
  short int G;
  short int IJ;
  
  do{
    for(IO; IO>0; IO--){
      WiFiClient CLI;
      if(G == 0){
        IJ = IO;
      }
      else{
        IJ = TR[IO];
        Serial.println("System: started trouble shooting");
      }
      
      if (CLI.connect(I[IJ], P)) {
        CLI.print("II");
        CLI.write('\r');
        delay(5);
        CLI.flush();
        CLI.stop();
        Serial.println("System: System info was sent");
      }
      else{
        String Trable = "System: System info wasn't sent to " + (String)IO;
        Serial.println(Trable);
        TR[count] = IO;
        count++;
      }
    }
    delay(100);
    IO = count;
    G = 1;
    count = 0;
    
    
  }
  while(IO>0);
  delay(100);
  
}

void loop(){

  String OUT;

  while(Serial.available()>0){
    OUT = OUT + Serial.read();
    if(Serial.available()=0){
      OUT = MyName + ": " + OUT;
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



#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 
char auth[] = "6a94295b109e4306a2bb396f6454768a";
char ssid[] = "никита";
char pass[] = "12345678";
 
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() {
  Blynk.run(); 
}
 
BLYNK_WRITE(V1) {
  int redValue = param[0].asInt(); 
  int greenValue = param[1].asInt();
  int blueValue = param[2].asInt();
 
  Serial.print("r");
  Serial.println(redValue);
  Serial.print("g");
  Serial.println(greenValue);
  Serial.print("b");
  Serial.println(blueValue);
}

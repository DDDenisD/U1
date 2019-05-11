String R = "";
char* IN[256];

void setup() {
  Serial.begin(115200);

}

void loop() {

  int i = 0;
  int C = 255;
  for(C; C>-1; C--){
    IN[C] = "";
  }
  while(Serial.available() == 0);
  while(Serial.available() > 0) {
    IN[i] = (char*)Serial.read();
    i++;
  }
  i = 0;
  while(IN[i] != ""){
    R += (char*)IN[i];
    i++;
  }
  Serial.println(R);

  //R += (char)Serial.read();
  //if(Serial.available() == 0){
  //  Serial.println(R);
  //  R = "";
  //}
}



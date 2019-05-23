// system function

void sys(int P, int U){
	star();
	switch(P){
		case 0:
		Serial.print("System info was sent to ");
		Serial.print(U);
		break;
		case 1:
		Serial.print("started trouble shooting");
		break;
		case 2:
		Serial.print("System info wasn't sent to ");
		Serial.print(U);
		break;
		
	}
	Serial.println();
	star();
}
// String Name[II];
// short int Dis = 0; 

void anaIN(){
	short int D = 0; //is it right
		String K = F.readStringUntil(':');
		for(int i = 0; i < II; i++){
			if(Name[i] == K){
				D = 1;
			}
		}
		if(D == 0){
			Name[Dis] = K;
			Dis++;
		}
}
// analyzing of text
// String Name[II];
// short int Dis = 0;



short int ana(String F){
	char* G[] = F;      //maybe there will be some problams
	if(G[0] == '//'){
		if(G[1] == 'h' && G[2] == 'e' && G[3] == 'l' && G[4] == 'p' && sizeof(G) == 5){
			return 1;
		}
		if(G[1] == 's' && G[2] == 'l' && G[3] == 'e' && G[4] == 'e' G[5] == 'p' && sizeof(G) == 6){
			return 2;
		}
	}
	else{
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
		return 0;
	}
			
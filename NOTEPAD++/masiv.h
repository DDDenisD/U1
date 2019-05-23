// masiv

short int TR(char* G1[], char* G2[]){
	short int T = 1;
	if(G1.sizeof() != G2.sizeof()){
		T = 0;
	}
	else{
		for(int h = 0; h < J; h++){
			if(G1[h] != G2[h]){
				T = 0;
			}
		}
	}
	return T;
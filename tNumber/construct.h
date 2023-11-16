#include "tNumber.hpp"

tNumber::tNumber(string v){ t=v; }
tNumber::tNumber(const char* v){ t=string(v); }
tNumber::tNumber(string v,int n){
	 t=v; 
	 sz=n;
	 check();
}
tNumber::tNumber(const char* v, int n){ 					t=string(v); 
	sz=n;
	check();
}
tNumber::tNumber(int n){ t=zeros(n); }

tNumber::tNumber(int a, int n){ 
	int step; stringstream s;
	for(step=0; a>=pow(2,step+1); step++);
	for(int j=step; j>=0; j--){
		if(a>=pow(2,j)){ 
			a-=pow(2,j);
			s<<1;
		}
		else s<<0;
	}
	t=s.str(); 
	sz=n;
	check();
}
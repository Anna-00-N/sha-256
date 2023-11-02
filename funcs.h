#include <math.h>

int light_number(int n){
	int k=0, m, i=2, j;
	for(;k<n;i++){
		m=0;
		for(j=1; j<=i;j++) if(i%j==0) m++;
		if(m==2) k++;
	}
	return i-1;
}

tNumber h_n(int n){
	tNumber t;
	t.set_all(exp(log(light_number(n+1))/2),FROM_DROB, 32);
	return t;
}

tNumber k_n(int n){
	tNumber t;
	t.set_all(exp(log(light_number(n+1))/3),FROM_DROB, 32);
	return t;
}

#include "tNumber.hpp"
#include <math.h>

char C16[6]={'a','b','c','d','e','f'};


void tNumber::set_t_from16(string t0){
	stringstream s; char c; int num=0;
	for(int i=0;i<t0.size();i++,num=0){
		c=t0[i];
		for(int j=0; j<6; j++)
			if(C16[j]==c) num=10+j;
		if(num==0) num=(int)c-(int)'0';
		for(int j=3; j>=0; j--)
			if(num>=pow(2,j)){
				s<<1; 
				num-=pow(2,j);
			}
			else s<<0;
	}
	t=s.str();
}

void tNumber::set_t_from16(const char* t0){
	set_t_from16(string(t0));
}

void tNumber::set_t_from_numRdrob(double a, int n){ //n - число бит, должно делиться на 4 например, n=32
	stringstream s; int r;
	for(int i=0;i<n/4;i++){
		 a-=trunc(a);
		 a*=16;
		 r=(trunc(a));
		 if(r>=10) s<<(C16[r-10]); else s<<r;
	 }
	 set_t_from16(s.str());
}

void tNumber::set_t_fromtext(string t0){
	stringstream s; int num;
	for(int i=0; i<t0.size(); i++){
		num=(int)t0[i];
		for(int j=7;j>=0;j--)
			if(num>=pow(2,j)){
				num-=pow(2,j);
				s<<1;
			}
			else s<<0;
	}
	t=s.str();
}

void tNumber::set_t_fromtext(const char* t0){
	set_t_fromtext(string(t0));
}

string tNumber::get_t_in16(){
	string t0 = (l()%4!=0)?(rsize(l()+(4-l()%4))):(t);
	stringstream s; int sum=0;
		for(int i=0;i<t0.size(); i+=4, sum=0){
			for(int j=0;j<4;j++) sum+=(t0[i+j]=='1')?(pow(2,3-j)):(0);
			if(sum>=10) s<<C16[sum-10]; else s<<sum;
		}
		return s.str();
}

void tNumber::set_all(string t0, int F, int n=0){
	sz=n;
	switch(F){
		case 0: set_t_fromtext(t0); break;
		case 2: set_t_from16(t0); break;
		default: t=t0; break;
	}
	check();
}

void tNumber::set_all(const char* t0, int F, int n=0){
	set_all(string(t0),F,n);
}

void tNumber::set_all(double t0, int F=1, int n=0){
	sz=n;
	if(sz>0) set_t_from_numRdrob(t0,sz); 
	else set_t_from_numRdrob(t0,32); 
	check();
}
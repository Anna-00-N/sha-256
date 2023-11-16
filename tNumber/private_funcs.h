#include "tNumber.hpp"

string tNumber::scat(string s1, string s2){
	stringstream s;
	s<<s1<<s2;
	return s.str();
}

string tNumber::zeros(int n){
	stringstream s;
	for(int i=0; i<n; i++) s<<"0";
	return s.str();
}

string tNumber::ones(int n){
	stringstream s;
	for(int i=0; i<n; i++) s<<"1";
	return s.str();
}

void tNumber::check(){
	if(sz>0) t=rsize(sz);
}
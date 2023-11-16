#include "tNumber.hpp"

string tNumber::rsize(int n){
	return (l()>n)?(t.substr(l()-n,n)):((l()<n)?(scat(zeros(n-l()),t)):(t));
}

string tNumber::addR_zeros(int n){
	stringstream s;
	s<<t<<zeros(n);
	t=s.str();
	if(sz>0) sz+=n;
	return t;
}

string tNumber::addR_ones(int n){
	stringstream s;
	s<<t<<ones(n);
	t=s.str();
	if(sz>0) sz+=n;
	return t;
}

int tNumber::l(){ return t.size(); }

void tNumber::append(string t2){
	stringstream s;
	s<<t<<t2;
	t=s.str();
	if(sz>0) sz+=t2.size();
}
void tNumber::append(const char* t2){
	append(string(t2));
}
void tNumber::append(tNumber t2){
	append(t2.t);
}
#include "tNumber.hpp"

void tNumber::set_t_sz(string s, int n){
	t=s; 
	sz = n;
	check();
}

void tNumber::set_t_sz(const char* s, int n){
	t=string(s);
	sz = n;
	check();
}

void tNumber::set_t(string s){
	 t = s; 
	 check();
}

void tNumber::set_t(const char* s){ 
	t=string(s); 
	check();
}

string tNumber::get_t(){ return t;}

void tNumber::set_sz(int n){ 
	sz = n; 
	check();
} 

int tNumber::get_sz(){ return sz; }
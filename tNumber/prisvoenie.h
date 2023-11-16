#include "tNumber.hpp"

tNumber tNumber::operator =(tNumber right)
    {
        t= right.t; 
        check();
		return *this;
    }
tNumber tNumber::operator =(string s){
	t= s; 
	check();
	return *this;
}
tNumber tNumber::operator =(const char*  s){
	t= string(s); 
	check();
	return *this;
}
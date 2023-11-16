#include "tNumber.hpp"


tNumber tNumber::operator not() {
	tNumber result;
	string t1=t; 
	stringstream s;
	for(int i=0; i<t1.size(); i++){
		if(t1[i]=='0')
		s<<1;
		else s<<0;
	}
	result.set_t_sz(s.str(), sz);
	return result;
}

tNumber tNumber::operator >>(int n){
	tNumber result;
	string t0=t; 
	stringstream s;
	for (int i=0;i<n;i++){
	    s<<0;
	    s<<t0.substr(0,t0.size()-1);
	    t0=s.str();
	    s.clear(); s.str("");
	}
	result.set_t_sz(t0, sz);
	return result;
}


tNumber tNumber::operator >=(int n){
	tNumber result;
	string t0=t; 
	stringstream s;
	for (int i=0;i<n;i++){
	    s<<t0[t0.size()-1];
		s<<t0.substr(0,t0.size()-1);
	    t0=s.str();
	    s.clear(); s.str("");
	}
	result.set_t_sz(t0, sz);
	return result;
}

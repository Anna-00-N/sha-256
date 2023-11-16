#include "tNumber.hpp"


tNumber tNumber::operator +(tNumber right) {
   tNumber result;
    string t1=t; string t2=right.t;
    int len=t1.size(); 
     if(t2.size()>len) len=t2.size(); 
	//сложение двоичных чисел с ограничением по длине
	int max=t2.size(); if(t1.size()>max) max=t1.size();
	int temp = 0, i1,i2, res;
	char c1,c2, *p;
    stringstream s;
    p = new char[len+5]; //сюда будут записаны числа в обратном порядке
	for(int i=0; i<len||temp>0; i++){
		if(i>=len&&temp>0) len++;
		c1=(t1.size()>=(i+1))?(t1[t1.size()-i-1]):'0';
	    c2=(t2.size()>=(i+1))?(t2[t2.size()-i-1]):'0';
		i1=(c1=='1')?(1):(0);
		i2=(c2=='1')?(1):(0);
		res = i1+i2+temp;
		temp = round(res/2);
		p[i]=(res%2==1)?('1'):('0');
	}
    for(int i=len-1; i>=0; i--) s<<p[i];
    delete [] p;
    result.set_t_sz(s.str(), sz);
    return result;
}


tNumber tNumber::operator xor(tNumber right) {
	tNumber result;
	string t1=t; string t2=right.t;
	stringstream s;
	for(int i=0; i<t1.size()||i<t2.size(); i++){
		if(t1[i]=='1'&&t2[i]=='0' || t1[i]=='0'&&t2[i]=='1')
		s<<1;
		else s<<0;
	}
	result.set_t_sz(s.str(), sz);
	return result;
}


tNumber tNumber::operator and(tNumber right) {
	tNumber result;
	string t1=t; string t2=right.t;
	stringstream s;
	for(int i=0; i<t1.size()||i<t2.size(); i++){
		if(t1[i]=='1'&&t2[i]=='1')
		s<<1;
		else s<<0;
	}
	result.set_t_sz(s.str(), sz);
	return result;
}

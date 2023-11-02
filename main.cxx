#include <iostream>
#include "tNumber/main.h"
#include "funcs.h"

using namespace std;

int main()
{
string mytext = "hello world"; //текст, который нужно зашифровать
string t_512; 
tNumber *w; 
w=new tNumber[64];
tNumber t; t.set_all(mytext, FROM_TEXT); //в t строка переведётся в последовательность битов (по 8 на символ)
int m=t.l(), n=0; //m - длина текста t в двоичном виде
stringstream s;//поток для записи 16-ных чисел


while( (m+1+n)%512 != 448 ) n++; //сколько нулей надо добавить, чтоб при делении на 512 остаток был 448 
t.addR_ones(1); t.addR_zeros(n);//добавить 1 единицу и n нулей
tNumber num(m,64);//в num запишется длина текста, переведенная в двоичную систему счисления и форматированная под длину 64
t.append(num); //добавим к тексту в двоичном виде значение длины


for(int i=512; t.l()>=i; i+=512){ //делим текст на куски по 512 бит
	t_512=(t.get_t()).substr(i-512, 512);
	
	for(int j=0; j<16; j++) 
		w[j]=t_512.substr(j*32, 32); //делим текст на куски по 32 бита
	
	for(int j=16; j<64; j++){
				w[j].set_sz(32);//отмеряем 32 бита
				tNumber s0 = (w[j-15]>=7) xor (w[j-15]>=18) xor (w[j-15]>>3);
				tNumber s1 = (w[j-2]>=17) xor (w[j-2]>=19) xor (w[j-2]>>10);
				w[j] = w[j-16]+s0+w[j-7]+s1;
	}
	
	tNumber a=h_n(0), b=h_n(1), c=h_n(2), d=h_n(3),e=h_n(4), f=h_n(5), g=h_n(6), h=h_n(7);
	for(int j=0; j<64; j++){
		tNumber s0 = (a>=2) xor (a>=13) xor (a>=22);
		tNumber maj = (a and b) xor (a and c) xor (b and c);
		tNumber s1= (e>=6) xor (e>=11) xor (e>=25);
		tNumber ch = (e and f) xor (not(e) and g);
		tNumber t1=h+s1+ch+k_n(j)+w[j];
		tNumber t2=s0+maj;
		h =g; g=f; f=e; e=d+t1; d=c; c=b; b=a; a=t1+t2;
	}

		s<<(h_n(0)+a).get_t_in16()<<(h_n(1)+b).get_t_in16()<<(h_n(2)+c).get_t_in16()<<(h_n(3)+d).get_t_in16()<<(h_n(4)+e).get_t_in16()<<(h_n(5)+f).get_t_in16()<<(h_n(6)+g).get_t_in16()<<(h_n(7)+h).get_t_in16();
	}

	cout<<"SHA256 hash: "<<s.str();

	delete [] w;
	
	cin.get();
    return 0;
}
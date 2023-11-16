#ifndef TNUMBER
#define TNUMBER

#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class tNumber{
	private:
	
		//ПЕРЕМЕННЫЕ
		string t=""; //основное значение (текстовый вид)
		int sz=0; //длина 
		
		//ПРИВАТНЫЕ ФУНКЦИИ
		string zeros(int); //строка из n нулей
		string ones(int); //строка из n единицы
		string scat(string, string); //concat string
		void check(); //если задано sz, ворматировать длину до sz
		
	public:
	
		//ФУНКЦИИ ПОМОЩНИКИ ДЛЯ SHA 256
		void set_t_from16(string);
		void set_t_from16(const char*); //ввод 16-ного числа с переводом в двоичное
		void set_t_from_numRdrob(double, int); //переводит часть справа от запятой в двоичную систему и дробная часть с n битами берётся как отдельное целое число
		void set_t_fromtext(string);
		void set_t_fromtext(const char*); //переводит текст в двоичную систему - на 1 символ по 8 бит
		string get_t_in16(); //возврат в 16-ную системе счисления
		void set_all(string, int, int); 
		void set_all(const char*, int, int); 
		void set_all(double, int, int); //задаёт t из строки по способу F= 0 - из 16-ного текста, 1 - из правой части десятичной дроби, 2 - из текств, и sz (для первых 2 случаев должно делиться на 4 или 8)
	
	
		//КОНСТРУКТОРЫ
		tNumber(){}
		tNumber(string); //t
		tNumber(const char*); //t
		tNumber(string, int); //t, sz
		tNumber(const char*, int); //t, sz
		tNumber(int); //строка з n нулей
		tNumber(int, int); //t - число в десятичное системе, sz
		
		//СЕТТЕРЫ - ГЕТТЕРЫ
		void set_t_sz(string, int);
		void set_t_sz(const char*, int);
		void set_t(string);
		void set_t(const char*);
		string get_t();
		void set_sz(int);
		int get_sz();
		
		//ДРУГИЕ ФУНКЦИИ
		int l(); //длина t
		string rsize(int); //изменить длину
		string addR_zeros(int); //добавляет справа n нулей
		string addR_ones(int); //добавляет справа n единиц
		void append(string); //соединение с другой строкой
		void append(const char*);
		void append(tNumber);
		
		//ОПРЕДЕЛЕНИЕ ПРИСВАИВАНИЯ
		tNumber operator =(tNumber); //присвоение другого элемента этого класcа
		tNumber operator =(string); //присвоение string
		tNumber operator =(const char*);  //присвоение char*
		
		//ОПРЕДЕЛЕНИЕ ОПЕРАТОРОВ С 1 tNumber
		tNumber operator not(); //не
		tNumber operator >>(int); //логический сдвиг вправо на n
		tNumber operator >=(int); //циклический сдвиг вправо на n
	
		
		//ОПРЕДЕЛЕНИЕ ОПЕРАТОРОВ С 2 tNmber
		tNumber operator +(tNumber); //сложение
		tNumber operator xor(tNumber); //исключающее или
		tNumber operator and(tNumber); //и
		
	//для возможности вывода формата в cout или stringstream 
		friend ostream &operator<<(ostream &os, const tNumber &v) { return os<<v.t; }
};


#endif


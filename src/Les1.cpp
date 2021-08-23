//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------
/**/
#include <stdio.h>
#include <cmath>
#include <cstdint>
// #include "../sourse/OOP.h"

using namespace std;

//---------------------------------------------------------------
/*	1
Создать класс Power, который содержит два вещественных числа. 
Этот класс должен иметь две переменные-члена для хранения этих вещественных чисел. 
Еще создать два метода: один с именем set, который позволит присваивать значения переменным, 
второй — calculate, который будет выводить результат возведения первого числа в степень второго числа. 
Задать значения этих двух чисел по умолчанию.
*/
//---------------------------------------------------------------

class Power{
private:
	double basis;
	double exp;
		
public:
	Power(double a = 2.0, double b = 2.0): basis(a), exp(b){}
	~Power(){}
	
	void set(double a, double b){
		basis = a;
		exp = b;
	}
	
	double calculate(){
		return pow(basis,exp);
	}
};

void les1_1(){
	
	Power powr;
	
	printf(" %3.3f\n", powr.calculate());
	
	powr.set( powr.calculate(), 2);
	
	printf(" %3.3f\n", powr.calculate());
	
}

//---------------------------------------------------------------
/*	2
Написать класс с именем RGBA, который содержит 4 переменные-члена типа 
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. 
Создать конструктор со списком инициализации членов, который позволит пользователю передавать 
значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.
*/
//---------------------------------------------------------------
class RGBA{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
	
public:
	RGBA(uint8_t red = 0 ,uint8_t green = 0 ,uint8_t blue = 0 ,uint8_t alpha = 255): m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){
		
	}
	~RGBA(){}
	
	print(){
		printf(" color is #%02x%02x%02x%02x\n", m_red, m_green, m_blue, m_alpha);
	}
	
};

void les1_2(){
	RGBA color;
	
	color.print();
	
}

//---------------------------------------------------------------
/*	3
Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
	-private-массив целых чисел длиной 10;
	- private целочисленное значение для отслеживания длины стека;
	- public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;
	- public-метод с именем push(), который будет добавлять значение в стек. 
		push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;
	- public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;
	- public-метод с именем print(), который будет выводить все значения стека.
*/
//---------------------------------------------------------------

#define SZ 10

class Stack{
private:
	int arr[SZ];
	int len;
	
public:
	Stack(): len(-1){}
	~Stack(){}
	
	void reset(){
		for(int i = 0; i < SZ; i++){
			arr[i] = 0;
		}
		len = -1;
	}
	
	bool push(int dat){
		if (len == SZ-1)
			return false;
		else{
			len++;
			arr[len] = dat;
			return true;
		}
	}
	
	int pop(){
		if (len >= 0 ){
			int tmp = arr[len];
			len--;
			return tmp;
		} else{
			printf(" Stack is empty\n");
		}
	}
	
	void print(){
		if(len > 0){
			for (int i = 0; i <= len; i++)
				printf(" %d", arr[i]);
			printf("\n");
		} else{
			printf(" Stack is empty\n");
		}
	}
};

void les1_3(){
	
	Stack st;
	
	st.reset();
	st.push(5);
	st.push(2);
	st.print();
	
	st.push(6);
	st.push(5);
	st.push(3);
	st.push(1);
	st.push(9);
	st.print();
	
	printf(" %d\n", st.pop());
	st.print();
	
	
}

//---------------------------------------------------------------
int main(int args, const char** argv){
	
	les1_1();
	
	les1_2();
	
	les1_3();
	
	return 0;
} 
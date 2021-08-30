//---------------------------------------------------------------
//	code in UTF-8
//	Autor - Alexey Farnakeev (GU_C++_1438 11.05.2021).
//---------------------------------------------------------------
/**/
#include <iostream>
#include <string>
// #include "../sourse/OOP.h"

using namespace std;

//---------------------------------------------------------------
/*	1
Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. 

Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения. 

Создать счетчик количества созданных студентов. 
В функции main() создать несколько студентов. 
По запросу вывести определенного человека.
*/
//---------------------------------------------------------------

class Person	
{
private:
	string name;
	int age;
	bool gender;
	int weight;	
	
public:
	Person(): name("N"), age(-1), gender(true), weight(-1){
		
	}
	Person(string nm, int a, bool gndr, int wgt): name(nm), age(a), gender(gndr), weight(wgt) {}
	~Person(){}
	
	void set(string nm, int a, bool gndr, int wgt){
		name = nm;
		age = a;
		gender = gndr;
		weight = wgt;
	}
	void setName(string nm){
		name = nm;
	}
	void setAge(int a){
		age = a;
	}
	void setGender(bool gndr){
		gender = gndr;
	}
	void setWeight(int wgt){
		weight = wgt;
	}
	
	string getName() const {
		return name;
	}
	int getAge() const {
		return age;
	}
	bool getGender() const {
		return gender;
	}
	int getWeight() const {
		return weight;
	}
	
	void printPerson(){
		printf(" Name = %s, Age = %d, Gender = %s, Weight = %d\n", name, age, (gender)? "Man": "Woman", weight);
	}
	
};

class Student: public Person	
{
private:
	int yearofstudy;
	
protected:
	static int countstudents;
	
public:
	Student(): yearofstudy(0)
	{
	}
	
	Student(string name, int age, bool gndr, int wgt, int yos = 0): Person(name, age, gndr, wgt), yearofstudy(yos)
	{
		countstudents++;
	}
	
	Student & operator = (const Student &other)
	{
		this->setName(other.getName());
		this->setAge(other.getAge());
		this->setGender(other.getGender());
		this->setWeight(other.getWeight());
	}
	
	~Student()
	{
		countstudents--;
	}
	
	
	
	void setYearOfStudy(int &year)
	{
		yearofstudy = year;	
	}
	
	int getYearOfStudy() const
	{
		return yearofstudy;
	}
	
	int getcountstud() const 
	{
		return countstudents;
	}
	
};
int Student::countstudents = 0;

class Students: public Student	
{
private:
	Student * st_s;
	int size;
	
	int searchStudent(string sname)
	{
		for (int i = 1; i < size; i++){
			if (sname == this->st_s[i].getName()){
				return i;
			}
		}
		return -1;
	}
	
public:
	Students(){}										// конструктор по умолчанию
		
	Students(const Students &other) 					// Конструктор копирования
	{			
		this->st_s = new Student[countstudents];
		
		for (int i = 0; i < countstudents; i++)
		{
			this->st_s[i] = other.st_s[i];
		}
		cout << "CC "<< this << endl;
	}
	
	Students & operator = (const Students &other)		//	Конструктор присваивания
	{
		if (this->st_s != nullptr)
			delete[] this->st_s;
		
		this->st_s = new Student[countstudents];
		
		for (int i = 0; i < countstudents; i++)
		{
			this->st_s[i] = other.st_s[i];
		}
		cout << "CC "<< this << endl;
		
		return *this;
	}
	
	~Students(){										// Деструктор
		delete[] this->st_s;
	}
	
	void addSudent(string nname, int nage, bool ngender, int nwgt, int nyos){
		
		if (this->st_s != nullptr){
			Students temp;
			
			temp.st_s = this->st_s;
					
			this->st_s = new Student[countstudents+1];
			
			for(int i = 0; i < countstudents; i++)
			{
				this->st_s[i] = temp.st_s[i];
			}
			
			Student nst_t(nname, nage, ngender, nwgt, nyos);
			
			this->st_s[countstudents-1] = nst_t;
		} else{
			
			Student nst_t(nname, nage, ngender, nwgt, nyos);
			this->st_s = new Student[countstudents];
			this->st_s[countstudents-1] = nst_t;
		}
		
	}
	
	void showStudent(string sname){
		int i = searchStudent(sname);
		if ( i >= -1)
			cout << "	" << st_s[i].getName() << " " << ((st_s[i].getGender())? "Man" : "woman") << " " << st_s[i].getAge() << " " << st_s[i].getWeight() << " " << st_s[i].getYearOfStudy() << endl;
		else 
			cout << "	Unknown person" << endl;
	}
};


void les2_1(){
	
	Students ST;
	ST.addSudent("Ivan", 		23, true, 	68, 0);
	ST.addSudent("Valera", 		25, true, 	49, 2);
	ST.addSudent("Yourii", 		16, true, 	50, 4);
	ST.addSudent("Linel", 		44, true, 	74, 1);
	ST.addSudent("Kate", 		18, false, 	48, 3);
	ST.addSudent("Valentine", 	22, false, 	55, 6);
	
	
	ST.showStudent("Yourii");
}

//---------------------------------------------------------------
/*	2
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). 
У Fruit есть две переменные-члена: name (имя) и color (цвет). 
Добавить новый класс GrannySmith, который наследует класс Apple.

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}


Код, приведенный выше, должен давать следующий результат:

		My apple is red.
		My banana is yellow.
		My Granny Smith apple is green.

*/
//---------------------------------------------------------------

class Fruit{
private:
	string Name;
	string Color;
protected:

public:
	Fruit(string name, string col): Name(name), Color(col){}
	~Fruit(){}
	
	string getName(){
		return Name;
	}
	string getColor(){
		return Color;
	}
};

class Apple: public Fruit{
	
private:

public:
	Apple(): Fruit("Apple", "yellow"){}
	Apple( string col): Fruit("Apple", col){}
	Apple( string name, string col): Fruit( name, col){}
	~Apple(){}
	
};

class Banana: public Fruit{
	
private:

public:
	Banana(): Fruit("Banana", "yellow"){}
	~Banana(){}
	
};

class GrannySmith: public Apple{
	
private:

public:
	GrannySmith(): Apple("Granny Smith apple" ,"green"){}
	~GrannySmith(){}
	
};

void les2_2(){
	
	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

}

//---------------------------------------------------------------
/*	3
Изучить правила игры в Blackjack. 
Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. 
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? 
Продумать реализацию игры с помощью классов и записать результаты.
*/
//---------------------------------------------------------------

/*
Blackjack
Необходимо набрать 21 очко или близкое снизу число очков.
Если очков набралось больше 21 - проигрыш.
Если очков одинаково то ничья.
Партия продолжается до пасования всех игроков
После каждого раунда колода "перемешивается"
В данной игре масть не имеет значения

в игре может быть 1-8 колод(52 карты без джокеров). Допустим, что играем одной колодой

Ценность карт:
	- Цена номерных карт - сообветствует номеру
	- Цена картинок (валета, дамы и короля) - 10 ед
	- Цена туза - 11, если его появление делает сумму очков больше 21 то цена меняется на 1

Основые действия:
	- Shuffling - Игровой процесс(раунд)
	- ShowGame - Отображение текущего состояния игры
	- Stand - пас(передача хода следующей руке)
	- Hit - взять карту в руку игрока(можно делать множество раз за ход раз)
	- CheckState - проверка состояния игры
	
Основные объекты:
	- Карта{
		Поля:
		- Значение (0 - карты нет)   {1(Туз),2,3,4,5,6,7,8,9,10,11(Валет),12(Дама),13(Король)}
		- достоинство соответственно {1(11) ,2,3,4,5,6,7,8,9,10,10       ,10      ,10        }
		
		Методы:
		- возврат достоинства по значению
	}
	- Колода (родитель карта){
		поля:
		- линейный массив хранящий значение карты в конкретной позиции (в 1 колоде 52 карты)
		- индекс "верхней карты колоды"
		
		методы:
		- инициализация колоды{
			случайно определять положения значений в колоде(перемешивание)
		}
		возврат указателя на текущую верхнюю карту
		
	}
	- Рука (родитель колода){
		поля:
		- последняя команда
		- общее число очков
		- какие именно карты в руке (массив указателей на ячейку массива колоды, длинна масива статическая - 11(для игры с одной колодой))
		
		Методы:
		- взять карту
		- спасовать
		
	}
	- Игра(родитель колода и рука){
		Поля:
		- число игроков(рук, по умолчанию 2)
		- колода
		- массив игроков
		
		Методы:
		- чтение действий игрока
		- отображение хода игры
		- игра{
			в бесконечном цикле
			- инициализация колоды
			- раздача всем игрокам по 2 карты 
			- ход игры{
				- предоставить ход игроку пока не будет пас(1 игрок - компьютер)
				- проверка состояния(если все игроки в состоянии "паса" то вывод результатов и конец игры)
				- переключение игроков
			}
		}
	}
*/

void les2_3(){
	
}

//---------------------------------------------------------------
int main(int args, const char** argv){
	
	// les2_1();
	
	les2_2();
	
	return 0;
} 
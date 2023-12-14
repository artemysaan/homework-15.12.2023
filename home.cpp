#include <iostream>
#include <string>
using namespace std; 
#define STOP_CMD system("pause>>void"); 
#define COLOR_CMD system("color 0A"); 

class Person
{
public:
	Person() {}
	Person(string n, string s, string  m);
	Person(const Person &ob);
	void Print() {
		cout << "NAME = " << this->name << endl; 
		cout << "SURNAME = " << this->surname << endl;
		cout << "MIDDLE NAME = " << this->Middle_Name << endl;
	}
private:
	string name; 
	string surname; 
	string Middle_Name; 
};
Person::Person(string n, string s, string  m) {
	this->name = n;
	this->surname = s;
	this->Middle_Name = m;
}
Person::Person(const Person &ob) {
	this->name = ob.name;
	this->surname = ob.surname;
	this->Middle_Name = ob.Middle_Name;
}
class Apartment
{
public:
	Apartment() :ob(nullptr), SIZE(0) {};
	Apartment(Person & o, int SIZE); 
	Apartment(const Apartment &obj);
	~Apartment() {
		cout << "DESTRUCTOR class[Apartment] adress = " << this << endl; 
		delete[] ob; 
		ob = nullptr; 
	}
	void print() {
		for (int i = 0; i < SIZE; i++)
			this->ob[i].Print(); 
	}

private:
	Person * ob;
	int SIZE; 
};
Apartment::Apartment(Person & o, int SIZE) {
	ob = new Person;
	this->ob = & o;
	this->SIZE = SIZE;
}
Apartment::Apartment(const Apartment &obj) {
	this->ob = obj.ob;
	this->ob = new Person;
	this->SIZE = obj.SIZE;
}
class House
{
public:
	House() :ob(nullptr) {};
	House(Apartment & o);
	House(const House &obj);
	~House() {
		cout << "DESTRUCTOR class[House] adress = " << this << endl;
		ob = nullptr;
	}
	void print() {
		this->ob->print();
	}

private:
	Apartment * ob;
};
House::House(Apartment & o) {
	this->ob = & o;
}
House::House(const House &obj) {
	this->ob = obj.ob;
}
int main() {
	COLOR_CMD
	Person * arr = new Person[5];
	arr[0] = { "Igor", "Dombrovsky", "Vladimirovich" };
	arr[1] = { "Vladimir", "Dombrovsky", "Vladimirovich" };
	arr[2] = { "Petro", "Ivanovich", "STEP" };
	arr[3] = { "Hello", "World", "Academy" };
	arr[4] = { "C++", "PHP", "JS" };
	Apartment ob_Apartment(*arr, 5);
	House ob_House(ob_Apartment);
	ob_House.print();
	arr = nullptr; 
	STOP_CMD
	return 0; 
}	

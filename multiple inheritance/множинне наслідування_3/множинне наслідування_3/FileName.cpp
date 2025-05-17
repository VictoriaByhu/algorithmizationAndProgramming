#include <iostream>
#include <string>
using namespace std;

class Fruit
{
private:
	string name;
	string color;
public:
	Fruit(string n, string c): name(n), color(c){}
	

	string getName() { return name; }
	string getColor() { return color; }
};

class Apple : public Fruit
{
protected:
	Apple(string name, string color) : Fruit(name, color){}
public:
	Apple(string color = "green"): Fruit("apple", color){}	
};

class Banana : public Fruit
{
public:
	Banana(string color = "yellow", string name = "banana") : Fruit(name, color){}
};

class GrannySmith : public Apple
{
public:
	GrannySmith(string n = "Granny Smith apple", string c = "green"): Apple(n,c){}
};


int main()
{
	Apple a("red");
	Banana b;
	GrannySmith c;

	cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

	return 0;
}
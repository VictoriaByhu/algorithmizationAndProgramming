#include <iostream>
using namespace std;

class Shape
{
public:
	virtual void area() = 0;

	virtual ~Shape(){}
};

class Square : public Shape
{
public:
	int side;

	Square(int s) : side(s) {}

	void area() override
	{
		int area = side * side;
		cout << "Square area: " << area << endl;
	}
};

class Rectangle : public Shape
{
public:
	int sideA;
	int sideB;

	Rectangle(int a, int b) : sideA(a), sideB(b) {}

	void area() override
	{
		int area = sideA * sideB;
		cout << "Rectangle area: " << area << endl;
	}
};

void calculateArea(Shape *a)
{
	a->area();
}

int main()
{
	Square square(5);

	Rectangle rectangle(4, 2);

	calculateArea(&square);
	calculateArea(&rectangle);

	return 0;
}
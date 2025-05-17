#include <iostream>
#include <string>
using namespace std;

class Engine
{
private:
	int power;
	int serialNumber;
public: 
	Engine()
	{
		power = 0;
		serialNumber = 0;
	}

	void inputData()
	{
		cout << "Enter power: ";
		cin >> power;
		cout << "Enter serial number: ";
		cin >> serialNumber;
	}

	void outputData()
	{
		cout << "Power: " << power << endl;
		cout << "Serial number: " << serialNumber << endl;
	}

	~Engine(){}

};

class Auto : public Engine
{
private:
	string brand;
	int price;
public:
	Auto()
	{
		brand = "Mersedes";
		price = 15000;
	}

	void inputData()
	{
		cout << "Enter brand: ";
		getline(cin, brand);
		cout << "Enter price: ";
		cin >> price;
	}

	void outputData()
	{
		cout << "Brand: " << brand << endl;
		cout << "Price: " << price << endl;
	}

	~Auto() {}

};

class Truck : protected Auto
{
private:
	int loadCapacity;
public:
	Truck()
	{
		loadCapacity = 1000;
	}

	void inputData()
	{
		cout << "Enter brand: ";
		getline(cin, brand);
		cout << "Enter price: ";
		cin >> price;
	}

	void outputData()
	{
		cout << "Brand: " << brand << endl;
		cout << "Price: " << price << endl;
	}

	~Auto() {}

};

int main()
{



	return 0;
}
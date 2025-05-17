#include <iostream>
using namespace std;

class student 
{
private:
	string PIP;
	int birthYear;
	string sex;
public:

	student()
	{
		PIP = "Unknown";
		birthYear = 2000;
		sex = "male";
	}

	int calculateAge()
	{
		return 2025 - birthYear;
	}

};

class employee : public student
{
private:
	double salary;
	string placeOfWork;
public:
	employee(double s = 2000, string p = "Chernivtsi") : salary(s), placeOfWork(p) {}

	

};

int main()
{
	employee first;
	
	cout << first.calculateAge();

	return 0;
}
#include <iostream>
using namespace std;

class People {
	string surname;
	string country;
	string sex;
	string education;
	int yearOfBirth;
	int age;

public:
	People() {
		surname = "Unknown";
		country = "Ukraine";
		sex = "Unknown";
		education = "Unknown";
		yearOfBirth = 2006;
		age = 19;
	}

	void Input() {
		cout << "Enter a surname: ";
		cin >> surname;
		cout << "Enter a country: ";
		cin >> country;
		cout << "Enter a sex:";
		cin >> sex;
		cout << "Enter an education: ";
		cin >> education;
		cout << "Enter a year of birth: ";
		cin >> yearOfBirth;
		cout << "Enter an age: ";
		cin >> age;
	}

	void Output() {
		cout << "Surname: " << surname << endl;
		cout << "Country: " << country << endl;
		cout << "Sex: " << sex << endl;
		cout << "Education: " << education << endl;
		cout << "Year of birth: " << yearOfBirth << endl;
		cout << "Age: " << age << endl;
	}


};


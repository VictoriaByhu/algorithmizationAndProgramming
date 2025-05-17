#include <iostream>
using namespace std;

class Flat {
	string address;
	int floor;
	int rooms;
	float area;

public:
	Flat() {
		address = "Unknown";
		floor = 1;
		rooms = 2;
		area = 55;
	}

	Flat(string addr, int fl, int rm, float ar) {
		address = addr;
		floor = fl;
		rooms = rm;
		area = ar;
	}

	int Floor() {
		return floor;
	}

	int Rooms() {
		return rooms;
	}

	float Area() {
		return area;
	}

	void Input() {
		cout << "Enter an address: ";
		cin >> address;
		cout << "Enter a floor: ";
		cin >> floor;
		cout << "Enter number of rooms: ";
		cin >> rooms;
		cout << "Enter area: ";
		cin >> area;
	}

	void Output() {
		cout << "Address: " << address << endl;
		cout << "Floor: " << floor << endl;
		cout << "Rooms: " << rooms << endl;
		cout << "Area: " << area << endl;

	}

	~Flat() {
		cout << "Deleting" << address << " flat" << endl;
	}
};

void SortByRooms(Flat flats[], int n) {
	int number;
	cout << "Enter number of rooms: ";
	cin >> number;
	for (int i = 0; i < n; i++) {
		if (flats[i].Rooms() == number) {
			flats[i].Output();
		}
	}
}

void SortByFloors(Flat flats[], int n) {
	int a, b;
	cout << "Enter the range of floors: ";
	cin >> a >> b;
	for (int i = 0; i < n; i++) {
		if (flats[i].Floor() >= a && flats[i].Floor() <= b && flats[i].Area() < 40) {
			flats[i].Output();
		}
	}
}

int main() {
	Flat flats[4];
	int n = 4;
	for (int i = 0; i < n; i++) {
		cout << "Flat " << i + 1 << endl;
		flats[i].Input();
	}

	for (int i = 0; i < n; i++) {
	
		flats[i].Output();
	}

	SortByRooms(flats, n);
	SortByFloors(flats, n);


	return 0;
}
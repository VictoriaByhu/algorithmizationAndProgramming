#include <iostream>
using namespace std;

class Robot
{
private:
	string manufacturer;
protected:
	int yearOfIssue;
public:
	double weight;

	Robot(string m = "Unknown", int y = 2015, double w = 15) : manufacturer(m), yearOfIssue(y), weight(w) {}

	void inputRobotsData()
	{
		cout << "Enter manufacturer: ";
		cin >> manufacturer;
		cout << "Enter year of issue: ";
		cin >> yearOfIssue;
		cout << "Enter weight: ";
		cin >> weight;
	}

	void outputRobotsData()
	{
		cout << "Manufacturer: " << manufacturer << endl;
		cout << "Year of issue: " << yearOfIssue << endl;
		cout << "Weight: " << weight << endl;
	}

	int CalculateRobotsAge() {
		return 2025 - yearOfIssue;
	}
};

class Loader
{
private:
	int maxLoad;
protected:
	int movementSpeedPH;
public:
	Loader()
	{
		maxLoad = 1000;
		movementSpeedPH = 15;
	}

	int deliveryTime(int distance)
	{
		int time = distance / movementSpeedPH;
		return time;
	}
};

class RobotTransporter : public Robot, public Loader
{
private:
	string typeOfCargo;
public:
	bool operator==(RobotTransporter& other) const
	{
		return typeOfCargo == other.typeOfCargo;
	}
};

class InventoryRobot : public RobotTransporter
{
private:
	int numberOfProcessedGoods;
public:
	int calculateInventoryTime() 
	{
		int time = numberOfProcessedGoods * 30;
		return time;
	}
};

class RobotCleaner : public RobotTransporter
{
protected: 
	double cleaningArea;
public:

	void inputArea()
	{
		cout << "Enter cleaning area: ";
		cin >> cleaningArea;
	}

	double calculateCleaningTime()
	{
		double time = cleaningArea / movementSpeedPH;
		return time;
	}
};

int main()
{
	RobotCleaner one;

	one.inputArea();

	cout << one.calculateCleaningTime();


	return 0;
}
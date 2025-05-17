#include <iostream>
using namespace std;

class Creature
{
protected:
	string name;
	char symbol;
	int hp;
	int damage;
	int gold;
public:
	string getName() { return name; }
	char getSymbol() { return symbol; }
	int getHP() { return hp; }
	int getDamage() { return damage; }
	int getGold() { return gold; }

	void reduceHealth(int damage)
	{
		hp - damage;
	}

	bool isDead()
	{
		return hp <= 0;
	}

	void addGold(int g)
	{
		gold + g;
	}
};

class Player : public
{

};

class Monster
{

};

int main()
{



	return 0;
}
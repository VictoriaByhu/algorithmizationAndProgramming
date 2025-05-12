#include <iostream>
#include <vector>
using namespace std;

class Instrument
{
public:
	virtual void play() = 0;

	virtual ~Instrument(){}
};

class Guitar : public Instrument
{
public:
	void play() override
	{
		cout << "brr brr\n";
	}
};

class Piano : public Instrument
{
public:
	void play() override
	{
		cout << "la la la\n";
	}
};

class Drum : public Instrument
{
public:
	void play() override
	{
		cout << "bum bum bum\n";
	}
};

void playAllInstruments(const vector<Instrument*>& instruments) {
	for (Instrument* instr : instruments) {
		instr->play();
	}
}

int main()
{
	vector<Instrument*> orchestra;

	orchestra.push_back(new Guitar());
	orchestra.push_back(new Piano());
	orchestra.push_back(new Drum());


	playAllInstruments(orchestra);


	return 0;
}
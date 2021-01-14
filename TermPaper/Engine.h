#ifndef TERM_PAPER_ENGINE_H
#define TERM_PAPER_ENGINE_H

#include <iostream>
#include <string>
using namespace std;

enum material { ALUMINIUM, CAST_IRON, TITANIUM, COMPOSITE };
istream& operator>> (istream& is, material& type);

class Engine
{
protected:
	string marking;
	string fuel;
	material metal;

	unsigned int power;
	unsigned int efficiency;
	unsigned int mass;

public:

	Engine();
	Engine(string marking, string fuel,
		material metal, unsigned int power,
		unsigned int efficiency, unsigned int mass);

	virtual ~Engine();

	const string getMarking() const;
	const string getFuel() const;
	const material getMetal() const;
	unsigned int getPower() const;
	unsigned int getEfficiency() const;
	unsigned int getMass() const;

	void setMarking(const string marking);
	void setFuel(const string fuel);
	void setMetal(const material metal);
	void setPower(unsigned int power);
	void setEfficiency(unsigned int efficiency);
	void setMass(unsigned int mass);

	virtual ostream& output_f(ostream& os, Engine* obj) const;
	virtual istream& input_f(istream& is, Engine* obj);

	friend ostream& operator<<(ostream& os, Engine* obj);
	friend istream& operator>>(istream& is, Engine* obj);

	string PrintMaterial() const;
	virtual void Print() = 0;
};

#endif
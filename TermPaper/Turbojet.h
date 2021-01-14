#ifndef TERM_PAPER_TURBOJET_H
#define TERM_PAPER_TURBOJET_H

#include "Engine.h"

enum bypass { HIGH, LOW, ZERO };
istream& operator>> (istream& is, bypass& type);

class Turbojet : public Engine
{
private:
	unsigned int traction; //т€га
	bypass outline; //контури двигуна

public:
	Turbojet();
	Turbojet(string marking, string fuel, material metal, unsigned int power,
		unsigned int efficiency, unsigned int mass, unsigned int traction, bypass outline);

	virtual ~Turbojet();

	unsigned int getTraction() const;
	bypass getOutline() const;

	void setTraction(unsigned int traction);
	void setOutline(bypass outline);

	ostream& output_f(ostream& os, Turbojet* obj) const;
	istream& input_f(istream& is, Turbojet* obj);

	friend ostream& operator<<(ostream& os, Turbojet* obj);
	friend istream& operator>>(istream& is, Turbojet* obj);

	string PrintOutline() const;
	void Print();
};

#endif

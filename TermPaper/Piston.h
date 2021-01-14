#ifndef TERM_PAPER_PISTON_H
#define TERM_PAPER_PISTON_H
#include "Engine.h"

enum engine_type { V_TYPE, VR_TYPE, W_TYPE, FLAT, STRAIGHT, WANKEL };
istream& operator>> (istream& is, engine_type& type);

class Piston : public Engine
{
private:
	unsigned int torque; //крутящий момент
	unsigned int cylinder; //к-сть циліндрів
	engine_type type; //тип двигуна

public:
	Piston();

	Piston(string marking, string fuel, material metal, unsigned int power,
		unsigned int efficiency, unsigned int mass, unsigned int torque, unsigned int cylinder, engine_type type);

	~Piston();

	unsigned int getTorque() const;
	unsigned int getCylinder() const;
	const engine_type getType() const;

	void setTorque(unsigned int torque);
	void setCylinder(unsigned int cylinder);
	void setType(const engine_type type);

	virtual ostream& output_f(ostream& os, Piston* obj) const;
	virtual istream& input_f(istream& is, Piston* obj);

	friend ostream& operator<<(ostream& os, Piston* obj);
	friend istream& operator>>(istream& is, Piston* obj);

	string PrintType() const;
	void Print();
};

#endif

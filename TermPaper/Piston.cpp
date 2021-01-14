#include "Piston.h"

Piston::Piston() : Engine(), torque(0), cylinder(0), type(V_TYPE) { }

Piston::Piston(string marking, string fuel, material metal, unsigned int power,
	unsigned int efficiency, unsigned int mass, unsigned int torque, unsigned int cylinder, engine_type type) :
	Engine(marking, fuel, metal, power, efficiency, mass),
	torque(torque), cylinder(cylinder), type(type) { }

Piston::~Piston() { }

unsigned int Piston::getTorque() const { return torque; }
unsigned int Piston::getCylinder() const { return cylinder; }
const engine_type Piston::getType() const { return type; }

void Piston::setTorque(unsigned int torque) { this->torque = torque; }
void Piston::setCylinder(unsigned int cylinder) { this->cylinder = cylinder; }
void Piston::setType(const engine_type type) { this->type = type; }

string Piston::PrintType() const
{
	string q = "";
	switch (getType())
	{
	case 0: { q = "V-type engine"; break; }
	case 1: { q = "VR-type engine"; break; }
	case 2: { q = "W-type engine"; break; }
	case 3: { q = "Flat engine"; break; }
	case 4: { q = "Straight engine"; break; }
	case 5: { q = "Wankel engine"; break; }
	}
	return q;
}

void Piston::Print()
{
	cout << endl;
	cout << "_____ Piston _____" << endl;
	Engine::Print();
	cout << "Torque: " << getTorque() << " N*m" << endl;
	cout << "Cylinder: " << getCylinder() << endl;
	cout << "Type: " << PrintType() << endl;
}

ostream& Piston::output_f(ostream& os, Piston* obj) const
{
	os << "__Piston__" << endl;
	Engine::output_f(os, obj);
	os << obj;
	return os;
}

istream& Piston::input_f(istream& is, Piston* obj)
{
	Engine::input_f(is, obj);
	is >> obj;
	return is;
}

istream& operator>>(istream& is, Piston* obj)
{
	string temp;
	int numb;
	is >> numb;
	obj->setTorque(numb);
	is >> numb;
	obj->setCylinder(numb);
	is >> temp;
	obj->setType(engine_type(stoi(temp)));
	//obj->setType(engine_type(1));
	return is;
}

ostream& operator<<(ostream& os, Piston* obj)
{
	os <<
		"Torque: " << obj->getTorque() << endl <<
		"Cylinder: " << obj->getCylinder() << endl <<
		"Type of engine: " << obj->getType() << endl << endl;
	return os;
}

istream& operator>>(istream& is, engine_type& type) {
	int val;
	string error;
	bool exit = true;
	do
	{
		exit = false;
		try
		{
			is >> val;
			if (cin.fail())
				throw error = "Engine type has to be a number,enter again.";
			if ((val != 0) && (val != 1) && (val != 2) && (val != 3) && (val != 4) && (val != 5))
				throw error = "Engine type is incorrect,enter again (numbers from 0 to 5)";
		}
		catch (string error)
		{
			cout << error << endl;
			is.clear(); 
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			exit = true;
		}
	} while (exit);
	type = engine_type(val);
	return is;
}

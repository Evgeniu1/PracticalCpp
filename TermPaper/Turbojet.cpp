#include "Turbojet.h"

Turbojet::Turbojet() : Engine(), traction(0), outline(HIGH) { }

Turbojet::Turbojet(string marking, string fuel, material metal, unsigned int power,
	unsigned int efficiency, unsigned int mass, unsigned int traction, bypass outline) :
	Engine(marking, fuel, metal, power, efficiency, mass), traction(traction), outline(outline) { }

Turbojet ::~Turbojet() { }

unsigned int Turbojet::getTraction() const { return traction; }
bypass Turbojet::getOutline() const { return outline; }

void Turbojet::setTraction(unsigned int traction) { this->traction = traction; }
void Turbojet::setOutline(bypass outline) { this->outline = outline; }

string Turbojet::PrintOutline() const
{
	string q = "";
	switch (getOutline())
	{
	case 0: { q = "High bypass"; break; }
	case 1: { q = "Low bypass"; break; }
	case 2: { q = "Zero bypass"; break; }
	}
	return q;
}

void Turbojet::Print()
{
	cout << endl;
	cout << "_______ Turbojet ________" << endl;
	Engine::Print();
	cout << "Traction: " << getTraction() << " N" << endl;
	cout << "Outline: " << PrintOutline() << endl;
}

ostream& Turbojet::output_f(ostream& os, Turbojet* obj) const
{
	os << "__Turbojet__" << endl;
	Engine::output_f(os, obj);
	os << obj;
	return os;
}

istream& Turbojet::input_f(istream& is, Turbojet* obj)
{
	Engine::input_f(is, obj);
	is >> obj;
	return is;
}

istream& operator>>(istream& is, Turbojet* obj)
{

	int numb;
	string temp;
	is >> numb;
	obj->setTraction(numb);
	is >> temp;
	obj->setOutline(bypass(stoi(temp)));
	return is;
}

ostream& operator<<(ostream& os, Turbojet* obj)
{
	os <<
		"Traction: " << obj->getTraction() << endl <<
		"Outline: " << obj->getOutline() << endl << endl;
	return os;
}

istream& operator>>(istream& is, bypass& type)
{

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
				throw error = "Bypass has to be a number,enter again.";
			if ((val != 0) && (val != 1) && (val != 2))
				throw error = "Bypass is incorrect,enter again (numbers from 0 to 5)";
		}
		catch (string error)
		{
			cout << error << endl;
			is.clear(); 
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			exit = true;
		}
	} while (exit);
	type = bypass(val);
	return is;
}

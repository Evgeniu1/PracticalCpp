#include "Engine.h"

Engine::Engine() : marking(""), fuel(""),
metal(), power(0),
efficiency(0), mass(0)
{ }
Engine::Engine(
	string marking, string fuel,
	material metal, unsigned int power,
	unsigned int efficiency, unsigned int mass)
	:
	marking(marking), fuel(fuel),
	metal(metal), power(power),
	efficiency(efficiency), mass(mass)
{ }

Engine::~Engine() { }

const string Engine::getMarking() const { return marking; }
const string Engine::getFuel() const { return fuel; }
const material Engine::getMetal() const { return metal; }

unsigned int Engine::getPower() const { return power; }
unsigned int Engine::getEfficiency() const { return efficiency; }
unsigned int Engine::getMass() const { return mass; }

void Engine::setMarking(const string marking) { this->marking = marking; }
void Engine::setFuel(const string fuel) { this->fuel = fuel; }
void Engine::setMetal(const material metal) { this->metal = metal; }
void Engine::setPower(unsigned int power) { this->power = power; }
void Engine::setEfficiency(unsigned int efficiency) { this->efficiency = efficiency; }
void Engine::setMass(unsigned int mass) { this->mass = mass; }

string Engine::PrintMaterial() const
{
	string q = "";
	switch (getMetal())
	{
	case 0: { q = "Aluminium"; break; }
	case 1: { q = "Cast iron"; break; }
	case 2: { q = "Titanium"; break; }
	case 3: { q = "Composite"; break; }
	}
	return q;
}

void Engine::Print()
{
	cout << "Marking: " << getMarking() << endl
		<< "Fuel: " << getFuel() << endl
		<< "Material: " << PrintMaterial() << endl
		<< "Power: " << getPower() << " HP" << endl
		<< "Efficiency: " << getEfficiency() << " %" << endl
		<< "Mass: " << getMass() << " kg" << endl;
}

ostream& Engine::output_f(ostream& os, Engine* obj) const
{
	os << obj;
	return os;
}

istream& Engine::input_f(istream& is, Engine* obj)
{
	is >> obj;
	return is;
}

ostream& operator<<(ostream& os, Engine* obj)
{
	os <<
		"Marking: " << obj->getMarking() << endl <<
		"Fuel: " << obj->getFuel() << endl <<
		"Material: " << obj->getMetal() << endl <<
		"Power: " << obj->getPower() << endl <<
		"Efficiency: " << obj->getEfficiency() << endl <<
		"Mass: " << obj->getMass() << endl;
	return os;
}

istream& operator>>(istream& is, Engine* obj)
{
	string temp;
	int numb;
	getline(is, temp);
	obj->setMarking(temp);
	getline(is, temp);
	obj->setFuel(temp);
	getline(is, temp);
	obj->setMetal(material(stoi(temp)));
	getline(is, temp);
	//cin >> numb;
	numb = stoi(temp);
	obj->setPower(numb);
	getline(is, temp);
	numb = stoi(temp);
	//cin >> numb;
	obj->setEfficiency(numb);
	getline(is, temp);
	numb = stoi(temp);
	//cin >> numb;
	obj->setMass(numb);
	return is;
}

istream& operator>>(istream& is, material& type)
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
			{
				throw error = "Material has to be a number,enter again.";          
			}
			
			if ((val != 0) && (val != 1) && (val != 2) && (val != 3))
			{
				throw error = "Material is incorrect,enter again (numbers from 0 to 3)";
			}
		}
		catch (string error)
		{
			cout << error << endl;
			is.clear();
			is.ignore(numeric_limits<streamsize>::max(), '\n');
			exit = true;
		}
	} while (exit);
	type = material(val);
	return is;
}


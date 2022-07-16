#include "Menu.h"

Menu::Menu() {}
Menu::~Menu() {}

void Menu::run()
{
	int choice = 0;
	char choice_char[2];

	while (true)
	{
		cout << "\n=========== Menu ============" << '\n'
			<< "| [1] Create turbojet engine |" << '\n'
			<< "| [2] Create piston engine   |" << '\n'
			<< "| [3] Show all engines       |" << '\n'
			<< "| [4] Remove all engines     |" << '\n'
			<< "| [5] Load from the file     |" << '\n'
			<< "| [6] Save to the file       |" << '\n'
			<< "| [7] Search object          |" << '\n'
			<< "| [8] Total power            |" << '\n'
			<< "| [9] Exit                   |" << '\n'
			<< "=============================\n";

		do
		{
			cout << "Input your choice: ";
			cin >> choice_char;

		} while (!isdigit(choice_char[0]) || (choice_char[1] != '\0'));

		choice = atoi(choice_char);

		switch (choice)
		{
		case 1: { create_turbojet(); break; }
		case 2: { create_piston(); break; }
		case 3: { show_all(); break; }
		case 4: { remove_all(); break; }
		case 5: { read_file(); break; }
		case 6: { write_file(); break; }
		case 7: { search_obj(); break; }
		case 8: { total_power(); break; }
		case 9: { exit(0); break; }
		}
	}
}

void Menu::create_turbojet()
{
	string temp;
	unsigned int numb;
	int mat = 0;
	material metal;
	bypass outline;
	Turbojet* obj = new Turbojet;
	cout << "Marking:";
	cin >> temp;
	obj->setMarking(temp);
	cout << "Fuel:";
	cin >> temp;
	obj->setFuel(temp);
	cout << "=========== Material ============" << '\n'
		<< "| ALUMINIUM - 0 | CAST IRON - 1 |" << '\n'
		<< "---------------------------------" << '\n'
		<< "| TITANIUM  - 2 | COMPOSITE - 3 |" << '\n'
		<< "=================================\n";
	char g_char[3];
	do
	{
		cout << "Material: ";
		cin >> g_char;

	} while (g_char[0] < '0' || g_char[0] > '3');
	mat = g_char[0] - '0';
	metal = (material)mat;
	obj->setMetal(metal);
	cout << "Power: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail()) {
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nPower: ";
		cin >> numb;
	}
	obj->setPower(numb);
	cout << "Efficiency: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail() || numb <= 0 || numb >= 100)
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nEfficiency: ";
		cin >> numb;
	}
	obj->setEfficiency(numb);
	cout << "Mass: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nMass: ";
		cin >> numb;
	}
	obj->setMass(numb);
	cout << "Traction: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nTraction: ";
		cin >> numb;
	}
	obj->setTraction(numb);
	cout << "============ Outline ============" << '\n'
		<< "| HIGH - 0 | LOW - 1 | ZERO - 2 |" << '\n'
		<< "=================================\n";
	char d_char[2];
	do
	{
		cout << "Outline: ";
		cin >> d_char;

	} while (d_char[0] < '0' || d_char[0] > '2');
	mat = d_char[0] - '0';
	outline = (bypass)mat;
	obj->setOutline(outline);
	container.insert(obj);
}

void Menu::create_piston()
{
	string temp;
	unsigned int numb;
	int mat = 0;
	material metal;
	engine_type engine;
	Piston* obj = new Piston;
	cout << "Marking:";
	cin >> temp;
	obj->setMarking(temp);
	cout << "Fuel:";
	cin >> temp;
	obj->setFuel(temp);
	cout << "=========== Material ============" << '\n'
		<< "| ALUMINIUM - 0 | CAST IRON - 1 |" << '\n'
		<< "---------------------------------" << '\n'
		<< "| TITANIUM  - 2 | COMPOSITE - 3 |" << '\n'
		<< "=================================\n";
	char g_char[3];
	do
	{
		cout << "Material: ";
		cin >> g_char;

	} while (g_char[0] < '0' || g_char[0] > '3');
	mat = g_char[0] - '0';
	metal = (material)mat;
	obj->setMetal(metal);
	cout << "Power: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nPower: ";
		cin >> numb;
	}
	obj->setPower(numb);
	cout << "Efficiency: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail() || numb <= 0 || numb >= 100)
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nEfficiency: ";
		cin >> numb;
	}
	obj->setEfficiency(numb);
	cout << "Mass: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nMass: ";
		cin >> numb;
	}
	obj->setMass(numb);
	cout << "Torque: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nTorque: ";
		cin >> numb;
	}
	obj->setTorque(numb);
	cout << "Cylinder: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> numb;
	while (cin.fail())
	{
		cout << "\nBad input! Try again..." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nCylinder: ";
		cin >> numb;
	}
	obj->setCylinder(numb);
	cout << "============= Type of engine =============" << '\n'
		<< "| V_TYPE - 0 |  VR_TYPE - 1 | W_TYPE - 2 |" << '\n'
		<< "------------------------------------------" << '\n'
		<< "|  FLAT  - 3 | STRAIGHT - 4 | WANKEL - 5 |" << '\n'
		<< "==========================================\n";
	char w_char[3];
	do
	{
		cout << "Engine type: ";
		cin >> w_char;

	} while (w_char[0] < '0' || w_char[0] > '5');
	mat = w_char[0] - '0';
	engine = (engine_type)mat;
	obj->setType(engine);
	container.insert(obj);
}

void Menu::show_all()
{
	container.display();
}

void Menu::remove_all()
{
	container.del_all();
	cout << "\nThe list has been deleted!" << endl;
}

void Menu::read_file()
{
	string file;
	cout << "Enter the file: ";
	cin >> file;
	ifstream fi;
	fi.open(file);
	if (!fi.good()) 
	{
		cout << "File not found" << endl;
		return;
	}
	container.del_all(); 
	string type; 
	while (!fi.eof())
	{
		getline(fi, type); 
		if (type == "Turbojet") 
		{
			Turbojet* object = new Turbojet;
			object->input_f(fi, object); 
			container.insert(object); 
		}
		if (type == "Piston")
		{
			Piston* object = new Piston;
			object->input_f(fi, object);
			container.insert(object);
		}
	}
	cout << "File was successfully read." << endl;
	fi.close();
}

void Menu::write_file()
{
	string file;
	cout << "Enter the file: ";
	cin >> file;
	ofstream fi;
	fi.open(file);
	
	for (int i = 0; i < container.get_size(); i++)
	{
		Engine* obj = this->container[i];
		
		if (Turbojet* temp = dynamic_cast<Turbojet*>(obj))
		{
			temp->output_f(fi, temp); 
		}
		if (Piston* temp1 = dynamic_cast<Piston*>(obj))
		{
			temp1->output_f(fi, temp1);
		}
	}
	cout << "File was successfully written." << endl;
	fi.close();
}
void Menu::search_obj()
{
	container.search();
}
void Menu::total_power()
{
	string type_fuel;
	int total_power = 0;
	cout << "Enter the type of fuel -> ";
	cin >> type_fuel;
	for (int i = 0; i < container.get_size(); i++)
		if (container[i]->getFuel() == type_fuel)
			total_power += container[i]->getPower();
	cout << "Total power of this fuel -> " << total_power << endl;
}

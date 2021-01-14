#include <iostream>
#include <iomanip>
using namespace std;

struct Shop
{
	char fullname[256]{};
	char address[256]{};
	float sale = 0;
};

void ShowTable(Shop* obj, int n)
{
	cout << ("==================================================================\n");
	cout << ("|              FULL NAME             |        Address     | Sale |\n");
	cout << ("==================================================================\n");
	for (int i = 0; i < n; i++)
	{
		cout << "|" << setw(36) << obj[i].fullname << "|" << setw(20) << obj[i].address << "|"
			<< setw(4) << obj[i].sale * 100 << " %" << "|" << endl;
		cout << ("——————————————————————————————————————————————————————————————————\n");
	}
}

void store(Shop* obj, int& n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (strcmp(obj[i].fullname, obj[j].fullname) == 0 && strcmp(obj[i].address, obj[j].address) == 0)
			{
				for (int k = j + 1; k < n; k++)
					obj[k - 1] = obj[k];
				j--;
				n--;
			}
}
/* ----------------------------------------------------------------------------------------*/
int main()
{
	Shop clients[] =
	{
		{ "Bondarchuk Evgeniu Igorovych",       "Metallistov, 4",   0.10 },
		{ "Bondarchuk Evgeniu Igorovych",       "Metallistov, 4",   0.10 },
		{ "Gavrilyuk Roman Volodymyrovych",     "Peremogy, 27A",    0.15 },
		{ "Demchenko Oleksandr Edyardovych",    "Jangela, 5",       0.20 },
		{ "Bizhnyuk Vitaliy Vitalievych",       "Pravdy, 3/14",     0.09 },
		{ "Demchenko Oleksandr Edyardovych",    "Jangela, 5",       0.20 },
	};
	int n = sizeof(clients)
		/
		sizeof(*clients);
	ShowTable(clients, n);
	store(clients, n);
	cout << endl;
	ShowTable(clients, n);
}
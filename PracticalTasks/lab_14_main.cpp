#include <iostream>
#include <cstdio>
#include <iomanip>
#pragma warning(disable : 4996)
using namespace std;
/*___________________________________________________*/

void create(char* filename);
void read(char* filename);
void write(const char* file_name);

/*___________________________________________________*/

int main()
{
	char filename[] = "/Users/evgeniu/Desktop/F.txt";
	create(filename);
	read(filename);
	write(filename);
	cout << endl;
	read(filename);

	return 0;
}


void create(char* filename)
{
	FILE* f = fopen(filename, "wb");
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int number = rand() % 100;
		fwrite(&number, sizeof(int), 1, f);
	}
	fclose(f);
}

void read(char* filename)
{
	FILE* file = fopen(filename, "rb");

	for (int number = 0; fread(&number, sizeof(int), 1, file); )
		cout << number << " ";
	fclose(file);
}

void write(const char* file_name)
{
	FILE* f = fopen(file_name, "r+b");
	fseek(f, 0, SEEK_END);
	int amount = ftell(f) / sizeof(int);
	fseek(f, 0, SEEK_SET);

	int* array = new int[amount];

	fread(array, sizeof(int), amount, f);

	for (int i = 0; i < amount; i++)
		if (array[i] % 2 == 0)
			fwrite(&array[i], sizeof(int), 1, f);
	fclose(f);
	delete[] array;
}
/*__________________________________________________*/

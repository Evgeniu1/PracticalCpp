#include <iostream>
#include <iomanip>
using namespace std;
/*-----------------------------------------*/
void selectionSort(int array[], int n);
void print(int array[], int n);
void rand_array(int array[], int n);
/*-----------------------------------------*/
int main()
{
	int n = 50;
	int* array = new int[50];
	rand_array(array, n);
	print(array, n);
	selectionSort(array, n);
	print(array, n);
	delete[] array;
}

void selectionSort(int array[], int n)
{
	for (int i = 1; i < n - 1; i += 2)
	{
		int min = i;
		for (int j = i + 2; j < n; j += 2)
			if (array[j] < array[min])
				min = j;

		int tmp = array[i];
		array[i] = array[min];
		array[min] = tmp;
	}
}

void print(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << "  ";
	cout << endl;
}

void rand_array(int array[], int n)
{
	srand(static_cast<unsigned int>(time(NULL))); //every time new random numbers
	for (int i = 0; i < n; i++)
		array[i] = rand() % 101;
}

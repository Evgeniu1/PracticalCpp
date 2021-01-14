#include <iostream>

using namespace std;

void rand_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		array[i] = rand() % 31 - 15;
}

void output_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << "\n";
}

void calc_array(int array[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
		if (array[max] < array[i])
			max = i;

	for (int i = 0; i < max; i++)
		if (array[i] < 0)
			array[i] = 0;
}

int main()
{
	int n = 0;
	cout << "Number of elements: ";
	cin >> n;
	int* arr = new int[n];
	rand_array(arr, n);
	output_array(arr, n);
	calc_array(arr, n);
	cout << endl;
	output_array(arr, n);
	delete[] arr;
}
#include <iostream>
#include <iomanip>

using namespace std;

void rand_array(int* array[], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			array[i][j] = rand() % 31 - 15;
}

void output_array(int* array[], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(5) << array[i][j] << " ";
		cout << endl;
	}
}

void  calc_array(int* array[], int n, int m)
{
	int min_j = 0;
	int min = array[0][0];
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			if (min > array[i][j])
			{
				min = array[i][j];
				min_j = j;
			}

	for (int i = 0; i < n; i++)
	{
		int temp = array[i][m - 1];
		array[i][m - 1] = array[i][min_j];
		array[i][min_j] = temp;
	}
	cout << endl;
}

int main()
{
	int n = 0;
	int m = 0;
	cout << "Enter n: ";
	cin >> n;
	cout << "Enter m: ";
	cin >> m;
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
		arr[i] = new int[n];

	rand_array(arr, n, m);
	output_array(arr, n, m);
	calc_array(arr, n, m);
	output_array(arr, n, m);

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;
}
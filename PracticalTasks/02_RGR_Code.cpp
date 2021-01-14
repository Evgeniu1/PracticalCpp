#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <stdio.h>
using namespace std;
/*----------------------------------------------------------------------------------------*/
//Функція для зчитування даних з файлу
void file_read(double& x_start, double& x_end, double& eps, double& steps)
{
	FILE* ptrFile;
	fopen_s(&ptrFile, "inp.txt", "r"); // відкриття файлу на зчитування
	if (ptrFile != NULL)
	{
		float x_s, x_e, e, s;

		fscanf_s(ptrFile, "%f%f%f%f", &x_s, &x_e, &e, &s); // зчитування данних з файлу
		x_start = x_s;
		x_end = x_e;
		eps = e;
		steps = s;

		fclose(ptrFile); // закриття файлу
	}
	else
		cout << "Can't open file.\n";
}
/*---------------------------------------------------------------------------------------*/
//Функція для запису даних в файл
void file_write(double& x_start, double& x_end, double& eps, int& steps)
{
	FILE* ptrFile;
	fopen_s(&ptrFile, "otp.txt", "w");// відкриття файлу
	if (ptrFile != NULL)
	{
		fprintf_s(ptrFile, "%f%f%f%i", x_start, x_end, eps, steps); // записати в файл
		fclose(ptrFile);// закриття файлу
	}
	else
		cout << "Can't open file." << endl;
}
/*------------------------------------------------------------------------------------------*/
//Функція вводу даних з клавіатури та перевірка на введеність даних 
void input(double& x_start, double& x_end, double& eps, double& step)
{

	while (true) //перевірка для початкового значення
	{
		cout << "Input x_start: ";
		cin >> x_start;
		if (!cin)//перевірка на введеня числа
		{
			cout << "Not right, there must be a number\n\n";
			cin.clear();//очищення поля cin
			while (cin.get() != '\n');//повернення до повторного вводу
		}
		else
			if (x_start < 0 || x_start > 2)
			{
				cout << "x_start out of the range\n\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
	}
	while (true) //перевірка для кінцевого значення
	{
		cout << "Input x_end: ";
		cin >> x_end;
		if (!cin)//перевірка на введеня числа
		{
			cout << "Not right, there must be a number\n\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			if (x_end <= x_start || x_end > 2)
			{
				cout << "x_end out the range\n\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
	}
	while (true) //перевірка для точності
	{
		cout << "Input accuracy: ";
		cin >> eps;
		if (!cin) //перевірка на введеня числа
		{
			cout << "Not right, there must be a number\n\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			if (fabs(eps) > 0.1)
			{
				cout << "Accuracy data is not correct \n\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
	}
	while (true) //перевірка для кроку
	{
		cout << "Input step: ";
		cin >> step;
		if (!cin)//перевірка на введеня числа
		{
			cout << "Not right, there must be a number\n\n";
			cin.clear();
			while (cin.get() != '\n');
		}
		else
			if (step <= 0 || step > 2)
			{
				cout << "Step data is not correct \n\n";
				cin.clear();
				while (cin.get() != '\n');
			}
			else break;
	}
}
/*------------------------------------------------------------------------------------------*/
//Функція обчислення значення ln(х) за рекурсивним множником
double log_n(double x, double eps, double a0, int& n, double sum = 0)
{
	sum += a0;
	double q = -((n - 1) * (x - 1)) / n; //рекурсивний множник
	double a = a0 * q;
	n++;
	if (fabs(a) > eps)
	{
		return log_n(x, eps, a, n, sum); //рекурсивний виклик ф-ції обчислення
	}
	return sum;
}
/*----------------------------------------------------------------------------------------*/
//Функція виводу даних в таблицю
void output(double x_start, double step, double y, double series, double error, int n)
{
	cout << "|" << setw(4) << x_start << "|" << setw(12) << y << "|" << setw(15) << series << "|" << setw(15) << error << "|"
		<< setw(7) << n << "|" << endl;
	cout << ("-----------------------------------------------------------\n");
}
/*-----------------------------------------------------------------------------------------*/
//Функція main
int main()
{
	double  y = 0,
		y_e = 0,
		x_start = 0,
		x_end = 0,
		eps = 0,
		step = 0,
		error = 0;

	int	n = 2;
	char letter = '\0';
	/*-------------------------------------*/
	cout << "Do you want to write data from the keyboard? y/n:   ";
	cin >> letter;
	if (letter == 'y')
		input(x_start, x_end, eps, step);
	else
		file_read(x_start, x_end, eps, step);
	cout << ("===========================================================\n");
	cout << ("|  x  |    y(x)   |    series(x)  |     error     | steps |\n");
	cout << ("===========================================================\n");
	for (x_start = x_start + step; x_start < x_end + step; x_start += step)
	{
		y = log_n(x_start, eps, x_start - 1, n);
		y_e = log(x_start);
		error = (fabs(y - y_e));
		output(x_start, step, y, y_e, error, n);
		file_write(x_end, x_end, eps, n);
		n = 2;
	}
}

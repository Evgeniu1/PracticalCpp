#include <iostream>

using namespace std;

double recursion(double a0, double d, int n)
{
	if (n == 1)
		return a0;
	return recursion(a0 + d, d, n - 1);
}

int main()
{
	double a0 = 0;
	double d = 0;
	int n = 0;

	cout << "a0 = ";
	cin >> a0;
	cout << "d = ";
	cin >> d;
	cout << "n = ";
	cin >> n;
	cout << "An = " << recursion(a0, d, n) << endl;

	return 0;
}

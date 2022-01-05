#include <iostream>
#include <iomanip>
using namespace std;


void showMatrix(double* m, int ord)
{
	for (int j = 0; j < ord; j++)
	{
		for (int k = 0; k < ord; k++)
		{
			cout << setiosflags(ios::fixed | ios::showpoint) <<
				setprecision(2) << setw(7) << m[j * ord + k];

		}
		cout << endl;
	}
}

double determinant(double* m, int ord)
{
	double deter = 0;
	int newArraySize = (ord - 1) * (ord - 1);
	double* arr = new double[newArraySize];

	if (ord == 2)
	{
		deter = deter + (m[0] * m[3]) - (m[1] * m[2]);
		return deter;
	}
	else
	{
		for (int n = 0; n < ord; n++)
		{
			int count = 0;
			for (int i = 0; i < ord; i++)
			{
				for (int j = 0; j < ord; j++)
				{
					if (((i * ord + j) > ord - 1))
					{
						if (((i * ord + j) % ord != n))
						{
							arr[count] = m[(i * ord) + j];
							count++;
						}
					}
				}
			}

			if (n % 2 == 0)
				deter = m[n] * (determinant(arr, ord - 1)) + deter;
			else
				deter = -m[n] * (determinant(arr, ord - 1)) + deter;

		}
	}
	return deter;
}

int main()
{

	double dm2[] = { 3, 4, 2, 7 };
	cout << "determinant of following 2 X 2 matrix " << endl;
	showMatrix(dm2, 2); // order is 2 X 2
	cout << "is " << determinant(dm2, 2) << endl << endl;

	double dm3[] = { 3, 4, 2, 7, 5, -3, 7, 0, 2 };
	cout << "determinant of following 3 X 3 matrix " << endl;
	showMatrix(dm3, 3); // order is 2 X 2
	cout << "is " << determinant(dm3, 3) << endl << endl;

	double dm4[] = { 3, 4, 2, 7, 3, 4, 2, 0, 3, 9, 2, 7, 6, 4, 11, 7, 3, -5, 2, 3 };
	cout << "determinant of following 4 X 4 matrix " << endl;
	showMatrix(dm4, 4); // order is 4 X 4
	cout << "is " << determinant(dm4, 4) << endl << endl;

	double dm7[49]; // use the garbage stored in array as data
	cout << "determinant of following 7 X 7 matrix " << endl;
	showMatrix(dm7, 7); // order is 7 X 7
	cout << "is " << determinant(dm7, 7) << endl << endl;

	return 0;
}
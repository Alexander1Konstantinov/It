#include <iostream>
#include <ctime>
using namespace std;

void create_array(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
	}
}

void random_array(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mas[i][j] = rand() % 11;
}

void print_array(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << mas[i][j] << ' ';
		cout << endl;
	}
}

void delete_array(int** mas, int n)
{
	for (int i = 0; i < n; i++)
		delete[] mas[i];
}

void proizv_array(int** mas_1, int n1, int m1, int** mas_2, int n2, int m2)
{
	int ki = 0, kj = 0;
	int si = 0, sj = 0;
	int** mas_3 = new int* [n1];
	create_array(mas_3, n1, m2);
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < m2; j++)
			mas_3[i][j] = 0;

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			for(int k=0;k<m1;k++)
				mas_3[i][j] += mas_1[i][k] * mas_2[k][j];
		}
	}

	print_array(mas_3, n1, m2);
	delete_array(mas_3, n1);
	delete[] mas_3;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int n1, m1, n2, m2;
	cin >> n1 >> m1;
	cin >> n2 >> m2;
	cout << endl;
	if (m1 != n2)
	{
		cout << "Такие матрицы нельзя перемножить";
		return 0;
	}
	int** mas_1 = new int* [n1];
	int** mas_2 = new int* [n2];
	create_array(mas_1, n1, m1);
	random_array(mas_1, n1, m1);
	print_array(mas_1, n1, m1);
	cout << endl;
	create_array(mas_2, n2, m2);
	random_array(mas_2, n2, m2);
	print_array(mas_2, n2, m2);
	cout << endl;
	proizv_array(mas_1, n1, m1, mas_2, n2, m2);
	delete_array(mas_1, n1);
	delete_array(mas_2, n2);
	delete[] mas_1;
	delete[] mas_2;
}
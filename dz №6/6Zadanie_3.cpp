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

void change_array(int** mas, int n, int m)
{
	int k = 0;
	int ki = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (k == m - ki)
			{
				ki++;
				break;
			}
			int temp = mas[i][j];
			mas[i][j] = mas[n - j - 1][m - i - 1];
			mas[n - j - 1][m - i - 1] = temp;
			k++;
		}
		k = 0;
	}
}

void delete_array(int** mas, int n)
{
	for (int i = 0; i < n; i++)
		delete[] mas[i];
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int n, m;
	cin >> n;
	cout << endl;
	int** mas = new int* [n];
	create_array(mas, n, n);
	random_array(mas, n, n);
	print_array(mas, n, n);
	cout << endl;
	change_array(mas, n, n);
	print_array(mas, n, n);
	delete_array(mas, n);
	delete[] mas;
}
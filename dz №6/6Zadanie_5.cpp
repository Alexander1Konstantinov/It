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
			mas[i][j] = rand() % 101;
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

void delete_array(int** mas, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
}

void change_array(int** mas, int n, int m)
{
	int i_min = 0;
	int j_min = 0;
	int i_max = 0;
	int j_max = 0;
	int max = 0;
	int min = 12345;
	for (int i = 1; i < n; i++)
	{
		i--;
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] > max)
			{
				i_max = i;
				j_max = j;
				max = mas[i][j];
			}
		}
		i++;
		for (int j = 0; j < m; j++)
		{
			if (mas[i][j] < min)
			{
				i_min = i;
				j_min = j;
				min = mas[i][j];
			}
		}
		mas[i_min][j_min] = max;
		max = 0;
		min = 12345;
	}
	print_array(mas, n, m);
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int n, m;
	cin >> n >> m;
	int** mas = new int* [n];
	create_array(mas, n, m);
	random_array(mas, n, m);
	print_array(mas, n, m);
	cout << endl;
	change_array(mas, n, m);
	delete_array(mas, n, m);
	delete[] mas;
}
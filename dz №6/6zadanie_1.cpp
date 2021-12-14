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

int min_i(int** mas, int n, int m)
{
	int i_min = 0, j_min = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mas[i_min][j_min] > mas[i][j])
			{
				i_min = i;
				j_min = j;
			}
	return i_min;
}

int min_j(int** mas, int n, int m)
{
	int i_min = 0, j_min = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mas[i_min][j_min] > mas[i][j])
			{
				i_min = i;
				j_min = j;
			}
	return j_min;
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

void delete_array(int** mas, int  n, int  m)
{
	for (int i = 0; i < n; i++)
	{
		delete[] mas[i];
	}
}

void del_array(int** mas, int n, int m, int min_ii, int min_jj)
{
	int flag = 0;
	int ki = 0;
	int kj = 0;
	int kki = 0;
	int** mas_new = new int* [n - 1];
	create_array(mas_new, n - 1, m - 1);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (i == min_ii && j == min_jj && flag !=1)
			{
				flag = 1;
				kki++;
				ki++;
				kj++;
			}
			else if (i == min_ii)
				ki=1;
			else if (j == min_jj)
				kj=1;
			if(i+ki<=n && j+kj <= m)
				mas_new[i][j] = mas[i+ki][j+kj];
			ki = 0 + kki;
		}
		kj = 0;
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			mas[i][j] = mas_new[i][j];
	mas = mas_new;
	delete_array(mas_new, n - 1, m - 1);
	delete[] mas_new;
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
	int min_ii = min_i(mas, n, m);
	int min_jj = min_j(mas, n, m);
	del_array(mas, n, m, min_ii, min_jj);
	print_array(mas, n - 1, m - 1);
	cout << endl << min_ii << ' ' << min_jj;
	delete_array(mas, n, m);
	delete[] mas;
}
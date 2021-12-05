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
	int min = 12345;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (min > mas[i][j] && mas[i][j] > 0)
			{
				i_min = i;
				j_min = j;
				min = mas[i][j];
			}
	return i_min;
}

int min_j(int** mas, int n, int m)
{
	int i_min = 0, j_min = 0;
	int min = 12345;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (min > mas[i][j] && mas[i][j] > 0)
			{
				i_min = i;
				j_min = j;
				min = mas[i][j];
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

void change_array(int** mas, int n)
{
	int ki = 0;
	int j = 0;
	int min_ii = min_i(mas, n, n);
	int min_jj = min_j(mas, n, n);
	for (int i = 0; i < n; i++)
	{
		if (j == min_ii)
			j++;
		if (j >= n)
			break;
		if (i == min_jj)
			i++;
		if (i >= n)
			break;
		int temp = mas[min_ii][i];
		mas[min_ii][i] = mas[j][min_jj];
		mas[j][min_jj] = temp;
		j++;
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
	int n;
	cin >> n;
	int** mas = new int* [n];
	create_array(mas, n, n);
	random_array(mas, n, n);
	print_array(mas, n, n);
	//cout << endl << min_i(mas, n, n) << ' ' << min_j(mas, n, n);
	cout << endl;
	change_array(mas, n);
	print_array(mas, n, n);
	delete_array(mas, n);
	delete[] mas;
}
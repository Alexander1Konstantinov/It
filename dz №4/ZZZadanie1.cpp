#include <iostream>
#include <ctime>
using namespace std;

void print_array(int mas[], const int n)
{
	for (int i=0; i < n; i++)
		cout << mas[i]<<' ';
	cout << endl;
}

void enarray(int first, int dif, const int n, int mas[])
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = first;
		first += dif;
	}
}

void rand_array1(int mas[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % n + 1;
		for(int j=0;j<i;j++)
			if (mas[j] == mas[i])
			{
				i--;
				break;
			}
	}
}

void rand_array2(int mas[], int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		mas[i] = rand() % 1001 + 1000;
}

void count(int mas[], int n)
{
	int k = 0;
	for (int i = 0; i < n; i++)
		if (((mas[i] % 100) / 10) % 2 == 0)
			k++;
	cout<< k<<endl;
}

int main()
{
	int first, dif;
	int n;
	cin >> first >> dif >> n;
	int* mas = new int[n];
	enarray(first, dif, n, mas);
	print_array(mas, n);
	rand_array1(mas, n);
	print_array(mas, n);
	rand_array2(mas, n);
	count(mas, n);
	print_array(mas, n);
	delete[] mas;
}
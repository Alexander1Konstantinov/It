#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

//template <typename t>
//t test(t a, t b)
//{
//	return a + b;
//}

template <typename t>
void random_array(t* a, int n)
{
	srand(time(0));
	for (int i = 0; i < n; i++)
		a[i] = t((rand() % 1001)/5.0);
}

template <typename t>
int length(t x)
{
	int count = 0;
	x *= 1000000;
	while (int(x) > 0)
	{
		x = x / 10;
		count++;
	}
	return count;
}

template <typename t>
bool T_check(t a, t b)
{
	int len_a = length(a);
	int len_b = length(b);
	if (len_a > len_b)
		b = int(b * pow(10, len_a - len_b));

	if (len_a < len_b)
		a = int(a * pow(10, len_b - len_a));

	return ((a - b) > 0);
}

template <typename t>
void sort_bubble(t* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (T_check(a[j],a[j+1]))
			{
				t temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

template <typename t>
void print_array(t* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i]<<' ';
	cout << endl;
}

int main()
{
	int* a = new int[10];
	float* b = new float[10];
	random_array(a, 10);
	print_array(a, 10);
	sort_bubble(a, 10);
	print_array(a, 10);
	cout << endl;
	this_thread::sleep_for(1000ms);	random_array(b, 10);
	print_array(b, 10);
	sort_bubble(b, 10);
	print_array(b, 10);
	delete[] a;
	delete[] b;
}
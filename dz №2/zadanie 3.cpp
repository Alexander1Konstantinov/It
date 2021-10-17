#include <iostream>

using namespace std;
int f(int n)
{
	int s = 0;
	int i;
	for (i = 1; i < n; i++)
		if (n % i == 0)
			s += i;
	return s;
}

int main()
{
	int i, j, k = 0, c = 0;
	int sum = 0;
	for (i = 1; i < 10000; i++)
		for (j = 1; j < 10000; j++)
			if (f(i) == j and f(j) == i and i != j and i != k and j != k and i != c and j != c)
			{
				k = i;
				c = j;
				cout << i << ' ' << j << endl;
			}
}


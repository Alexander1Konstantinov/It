#include <iostream>

using namespace std;

int f(int a, int b)
{
	if (a == 1)
		return 1;
	while (1)
	{
		if (a % b == 0)
		{
			cout << b << endl;
			f(a / b, b);
			return 2;
		}
		b++;
	}
}
int main()
{
	int a;
	cin >> a;
	f(a, 2);
}
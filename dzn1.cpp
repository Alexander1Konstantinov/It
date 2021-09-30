#include <iostream>

using namespace std;
int main()
{
	int a,i;
	cin >> a;
	if (a / 10 == 0)
		cout << "NO";
	else if (((a / 10) / 10) == 0)
		cout << "NO";
	else
	{
		for (i = 0; i < 3; i++)
			a = a / 10;
		if (a == 0)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
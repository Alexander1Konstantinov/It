#include <iostream>

using namespace std;

int sum(char* str)
{
	char* a = new char[100];
	int j = 0, sum = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '+')
		{
			a[j] = 0;
			char* s = a;
			sum += atoi(s);
			i++;
			j = 0;
			char* a = nullptr;

		}
		a[j] = str[i];
		j++;
	}
	a[j] = 0;
	char* s = a;
	sum += atoi(s);
	delete[] a;
	delete[] str;
	return sum;
}
int main()
{
	char* str = new char[100];
	cin >> str;
	cout << sum(str);
}
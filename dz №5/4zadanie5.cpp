#include <iostream>
#include <Windows.h>

using namespace std;

int funct(char* s, char* s1)
{
	int j = 0, sum = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == s1[0])
		{
			j = i;
			int flag = 1;
			for (int k = 0; k < strlen(s1); k++)
			{
				if (s[j] != s1[k])
				{
					flag = 0;
					break;
				}
				j++;
			}
			if (flag == 1)
				sum += 1;
		}
	}
	delete[] s;
	delete[] s1;
	return sum;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* s = new char[100];
	char* s1 = new char[100];
	cin >> s >> s1;
	cout<<funct(s, s1);
}
#include <iostream>

using namespace std;
void funct(char* str, char* ext)
{
	int flag = 0;
	char* str1 = new char[100];
	strcpy_s(str1, strlen(str) + 1, str);
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (str1[i] == '.')
		{
			flag = 1;
			str1[i] = ' ';
			str1[i] = 0;
			strcat_s(str1,strlen(str1)+strlen(str)+2,ext);
			break;
		}
		str1[i] = ' ';
	}
	if (flag == 0)
		strcat_s(str, strlen(str) + strlen(ext) +2, ext);
	else
		strcpy_s(str, strlen(str1) + 1, str1);
	delete[] str1;
}

int main()
{
	char* str = new char[100];
	char* ext = new char[100];
	cin >> str >> ext;
	funct(str, ext);
	cout << str;
	delete[] str;
	delete[] ext;
}
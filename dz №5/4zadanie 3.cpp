#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* a = new char[100];
	char* b = new char[100];
	char* c = new char[100];
	cin >> a >> b >> c;
	cout << b[0]<<'.'<<c[0]<<'.'<<a;
	delete[] a;
	delete[] b;
	delete[] c;
}
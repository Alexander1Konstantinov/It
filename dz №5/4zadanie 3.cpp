#include <iostream>
#include <Windows.h>

using namespace std;

void vivod(char* a, char* b, char* c)
{
	cout << b[0] << '.' << c[0] << '.' <<' '<< a<<endl;
}
void delete_char(char* a)
{
	delete[] a;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char* a = new char[100];
	char* b = new char[100];
	char* c = new char[100];
	cin >> a >> b >> c;
	vivod(a, b, c);
	delete_char(a);
	delete_char(b);
	delete_char(c);
}
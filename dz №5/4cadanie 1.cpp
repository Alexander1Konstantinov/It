#include <iostream>
#include <Windows.h>
using namespace std;

bool palindrome(char word[])
{
    char* b = new char[strlen(word) + 1];
    char* c = new char[strlen(word) + 1];
    for (int i = 0; i < strlen(word); i++)
        b[i] = word[i];
    b[strlen(word)] = 0;
    int j = 0;
    for (int i = strlen(word) - 1; i >= 0; i--)
    {
        c[j] = word[i];
        j++;
    }
    c[strlen(word)] = 0;
    for(int i=0;i<strlen(word);i++)
        if (c[i] != b[i])
        {
            delete[] word;
            delete[] b;
            delete[] c;
            return 0;
        }
    delete[] word;
    delete[] b;
    delete[] c;
    return 1;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char* a = new char[100];
    cin >> a;
    if (palindrome(a))
        cout << "YES";
    else
        cout << "NO";
    
}
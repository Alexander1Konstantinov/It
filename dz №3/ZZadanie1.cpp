#include <iostream>

using namespace std;
int f(int n)
{
    if (n / 10 > 0)
        f(n / 10);
    cout << n%10 << endl;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    f(n);
}

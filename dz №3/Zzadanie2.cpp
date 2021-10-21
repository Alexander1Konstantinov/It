#include <iostream>
#include <cmath>
using namespace std;
int s = 0,sum=0;
void f(int n)
{
    if (n > 0)
    {
        sum += n % 10 * pow(2, s);
        s += 1;
        f(n / 10);
    }
    else
        cout << sum;
}
int main()
{
    int n;
    cin >> n;
    f(n);
}
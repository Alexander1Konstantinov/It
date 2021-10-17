#include <iostream>
#include <ctime>
using namespace std;
void f()
{
    srand(time(0));
    cout << rand()%6+ 1 << ' ' << rand()%6 + 1;
}
int main()
{
    f();
}
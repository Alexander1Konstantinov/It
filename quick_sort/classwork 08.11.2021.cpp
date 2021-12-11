#include <iostream>
#include <ctime>
using namespace std;

void print_array(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}

void move_to_left(int* a, int begin, int end)
{
    int tmp = a[begin];
    for (int i = begin; i < end; i++)
        a[i] = a[i + 1];
    a[end] = tmp;
}

void move_to_right(int* a, int begin, int end)
{
    int tmp = a[end];
    for (int i = end; i > begin; i--)
        a[i] = a[i - 1];
    a[begin] = tmp;
}

void quickSortR(int *a, int begin, int end) {
    int mid = (end + begin) / 2;
    for (int i = begin; i <= end; i++)
    {
        if (a[i] > a[mid] && i < mid)
        {
            move_to_left(a, i, mid);
            //print_array(a, 10);
            i--;
            //cout << mid << endl << i << endl;
        }

        if (a[i] < a[mid] && i > mid)
        {
            move_to_right(a, mid, i);
            //print_array(a, 10);
            mid++;
            //cout << mid << endl << i << endl;
        }
     
    }
    if (begin < mid)
        quickSortR(a, begin, mid);
    if (mid < end)
        quickSortR(a, mid + 1, end);
    return;
}

/*void qsort_Hoar(int* a,int n)
{
    int begin = 0, end = n;
    int mid = (begin + end) / 2;
    if (begin == end)
        return;
    quickSortR(a, begin, end);
    quickSortR(a, mid, end);
}
*/

void rand_array(int* a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = rand() % 11;
}

int main()
{
    srand(time(0));
    int *a = new int[10];
    rand_array(a, 10);
    //print_array(a, 10);
    //cout << endl;
    quickSortR(a, 0, 9);
    print_array(a, 10);
    delete[] a;
}
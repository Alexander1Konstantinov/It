#include <iostream>
#include <string>
using namespace std;

struct elem {
    char value;
    int index;
    elem* next = nullptr;
};
void push(elem*& stack, char value, int index)
{
    elem* newel = new elem;
    newel->value = value;
    newel->index = index;
    if (!stack)
    {
        stack = newel;
    }
    else
    {
        newel->next = stack;
        stack = newel;
    }

}
bool pop(elem*& stack, char& value, int& index)
{
    if (!stack) return false;
    elem* rem = stack;
    value = stack->value;
    index = stack->index;
    stack = stack->next;
    delete rem;
    return true;
}
void clear(elem*& stack)
{
    while (stack)
    {
        auto* rem = stack;
        stack = stack->next;
        delete rem;
    }
}

void check(elem* stack, string s)
{
    char a1 = '(';
    char b1 = '[';
    char c1 = '{';
    char d1 = '<';
    char a2 = ')';
    char b2 = ']';
    char c2 = '}';
    char d2 = '>';
    int i;
    char cmp;
    int index;
    bool fl = 1;
    for (i = 0; i < s.size(); i++) {

        if (s[i] == a1 or s[i] == b1 or s[i] == c1 or s[i] == d1) {
            push(stack, s[i], i);
        }
        else
            if (stack != nullptr)
            {
                if (s[i] == a2) {
                    pop(stack, cmp, index);
                    if (cmp != a1) {
                        cout << index << ' ';
                        fl = 0;
                    }
                }
                if (s[i] == b2) {
                    pop(stack, cmp, index);
                    if (cmp != b1) {
                        cout << index << ' ';
                        fl = 0;
                    }
                }
                if (s[i] == c2) {
                    pop(stack, cmp, index);
                    if (cmp != c1) {
                        cout << index << ' ';
                        fl = 0;
                    }
                }
                if (s[i] == d2) {
                    pop(stack, cmp, index);
                    if (cmp != d1) {
                        cout << index << ' ';
                        fl = 0;
                    }
                }
            }
            else
                if (stack == nullptr) {
                    cout << i << " ";
                    fl = 0;
                    break;
                }

    }
    if (stack != nullptr) {
        while (stack) {
            pop(stack, cmp, index);
            cout << index << " ";
        }
        fl = 0;
    }
    if (fl) {
        cout << "Введенное выражение верно";
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    elem* stack = nullptr;
    string s;
    getline(cin,s);
    check(stack, s);
    clear(stack);
    return 0;
}
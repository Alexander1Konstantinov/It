#include <iostream>
#include "stack.h"
#include <fstream>

using namespace std;

void operateExpression(char* value);
void show_content();


int main() {
    cout << "Content-type: text/html; charset=Windows-1251\n\n";
    ifstream f("stack");
    if (f.is_open())
    {
        auto sz = 65536;
        auto buf = new char[sz];
        while (!f.eof())
        {
            f.getline(buf, sz);
            if (strcmp(buf, "<!--#CONTENT#-->") == 0)
            {
                show_content();
            }
            cout << buf;
        }
        delete[] buf;
        f.close();
    }
    else
    {
        cout << "Не удалось вывести страницу :(";
    }

}

void show_content() {
    setlocale(LC_ALL, "Russian");

#ifndef _DEBUG
    char* data = nullptr;
    get_form_data(data);
#else
    const char* data = "imya=Sergey&";
#endif

    char* value = nullptr;
    get_param_value(value, "imya", data);

    cout << "<form method='post' action='stack.cgi'>";
    cout << "<div class='form-content'>";
    cout << "<h1 class='enteratext'>Введите выражение, используя скобки вида () {} []</h1>";
    cout << "<textarea id='msg' type='text' name='imya'>";

    cout << value;

    cout << "</textarea>";
    cout << "<div class='button-container'>";
    cout << "<input type='submit' value='Отправить'>";
    cout << "</div>";
    cout << "<div class='AnswerPool'>";
    cout << "<div class='half-elment'><p style='font - weight: bold; '>Ошибки на позициях:</p></div>";

    if (data && strlen(data) > 0) {

        cout << "<div class='half-elment'><div class='Answer'><p style='margin: 0 5px; '>";
        operateExpression(value);
        cout << "</p></div></div>";
    }
    else {
        cout << "<div class='half-elment'><div class='Answer'><p style='margin: 0 5px; '>" << "Поле Ответа" << "</p></div></div>";
    }
    cout << "</div>";
    cout << "</div>";
    cout << "</form>";
}

void operateExpression(char* s) {
    setlocale(LC_ALL, "rus");
    elem* stack = nullptr;
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
    for (i = 0; i < strlen(s); i++) {

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
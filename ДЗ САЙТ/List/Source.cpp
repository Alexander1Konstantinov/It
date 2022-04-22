#include <iostream>
#include "list.h"
#include <fstream>
#include <string>
using namespace std;
bool unic(elem*& list, char* val) {
    if (!list)
    {
        return true;
    }
    else
    {
        elem* curr = list;
        while (curr->next)
        {
            if (curr->a == atoi(val))
            {
                return false;
            }
            curr = curr->next;
        }
        if (curr->a != atoi(val)) {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool notempty(ifstream& itext) {
    long file_size;
    itext.seekg(0, ios::end);
    file_size = itext.tellg();
    if (file_size == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool check(char* value)
{
    for (int i = 1; i < strlen(value) - 1; i++)
    {
        if (value[i] == ' ' && value[i - 1] != ' ' && value[i + 1] != ' ') return false;
    }
    return true;
}

void show_content()
{
    setlocale(LC_ALL, "Russian");
//#ifndef _DEBUG
//    char* data = nullptr;
//    get_form_data(data);
//#else
//    const char* data = "imya=Sergey&";
//#endif
//    char* value = nullptr;
 //   get_param_value(value, "imya", data);
    //cout << "<form method='post' action='list.cgi'>";
    //cout << "<div class='form-content'>";
    //cout << "<h1 class='enteratext'>Введите 1 число или 2 числа</h1>";
    //cout << "<textarea id='msg' type='text' name='imya'>";


    //cout << "</textarea>";
    //cout << "<div class='button-container'>";
    //cout << "<input type='submit' value='Отправить'>";
    //cout << "</div>";
    //cout << "<div class='AnswerPool'>";
    //cout << "<div class='half-elment'><p style='font - weight: bold; '>Список:</p></div>";
   // cout << "<form method='post' action='list.cgi'>";
   // cout << "<div class='form-content'>";
   // cout << "<h1 class='enteratext'>Введите числа</h1>";
   // cout << "<textarea id='msg' type='text' name='imya'>";

   ////// cout << value;

   // cout << "</textarea>";
   // cout << "<div class='button-container'>";
   // cout << "<input type='submit' value='Отправить'>";
   // cout << "</div>";
   // cout << "<div class='AnswerPool'>";
   // cout << "<div class='half-elment'><p style='font - weight: bold; '>Список:</p></div>";
    cout << "<form method='get' action='list.cgi'>";
    cout << "<input type='text' class='enter' name='list' placeholder='Введите значение для занесения в список, либо значение и место в списке, в которое его нужно вставить (через пробел)'>";
    cout << "<input type='submit' value='Отправить' class='button'></input>";
    cout << "</form>";
    cout << "<h2 class = 'result'>Список с уникальными значениями: </h2>";
    cout << "<div class = 'output'>";
    char* data = nullptr;
    get_form_data(data);
    
    elem* list = new elem;
    ifstream itext("smth.txt", ios_base::in);
    if ((data && strlen(data)) > 0)
    {
        char* value = nullptr;
        get_param_value(value, "list", data);
       // get_param_value(value, "list", data);
        int temp;
        if (check(value)) {
            ofstream otext("smth.txt", ios_base::app);
            if (notempty(itext)) {
                itext.seekg(0, ios::beg);
                while (!itext.eof()) {
                    itext >> temp;
                    add(list, temp);
                }
                itext.close();
            }
            if (unic(list, value)) {
                add(list, atoi(value));
                otext << " " << atoi(value);
            }
            otext.close();

            if (list) {
                
                //cout << "<div class='half-elment'><div class='Answer'><p style='margin: 0 5px; '>";
                show(list);
                //cout << "</p></div></div>";
            }
        }
        else
        {
            if (notempty(itext)) {
                itext.seekg(0, ios::beg);
                while (!itext.eof()) {
                    itext >> temp;
                    add(list, temp);
                }
                itext.close();
            }
            ofstream otext("smth.txt");
            char* context = nullptr;
            char* number = strtok_s(context, " ", &value);
            if (unic(list, number)) {
                insert(list, atoi(number), atoi(value) + 1);
            }
            elem* curr = list->next;
            while (curr)
            {
                otext << " " << curr->a;
                curr = curr->next;
            }
            otext.close();
            //cout << "<div class='half-elment'><div class='Answer'><p style='margin: 0 5px; '>";
            show(list);
            //cout << "</p></div></div>";
        }
    }
    else {
        cout << "<div class='half-elment'><div class='Answer'><p style='margin: 0 5px; '>" << "Поле Ответа" << "</p></div></div>";
    }
    //cout << "</div>";
    //cout << "</div>";
    //cout << "</form>";
    delete[] data;
}



void main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Content-type: text/html; charset=Windows-1251\n\n";
    ifstream f("list");
    if (f.is_open())
    {
        auto sz = 65536;
        auto buf = new char[sz];
        while (!f.eof())
        {
            f.getline(buf, sz);
            /*if (strcmp(buf, "<!--#TITLE#-->") == 0)
            {
                cout << "<h1 class='title'>Список</h1>";
            }*/
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
        cout << "CGI-файл не загрузился";
    }
}

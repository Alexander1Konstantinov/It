#include "queue.h"
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iostream>

void enqueue(queue& q, const char* name, const char* sex, int age, const char* job, int income, const char* goal)
{
    man* new_man = new man;
    new_man->age = age;
    new_man->income = income;
    strcpy_s(new_man->name, name);
    strcpy_s(new_man->sex, sex);
    strcpy_s(new_man->job, job);
    strcpy_s(new_man->goal, goal);
    enqueue(q, *new_man);
}

void enqueue(queue& q, man m)
{
    elem* newel = new elem;
    newel->value = m;
    if (!q.tail)
    {
        q.head = q.tail = newel;
    }
    else
    {
        q.tail->next = newel;
        q.tail = newel;
    }
    q.lenght++;
}

void delete_elem(queue& q)
{
    elem* rem = q.head;
    q.head = q.head->next;
    delete rem;
    q.lenght--;
}

bool dequeue(queue& q, man& m)
{
    if (!q.head)
        return false;
    m = q.head->value;
    delete_elem(q);
    if (!q.head) q.tail = nullptr;
    q.lenght--;
    return true;
}

void clear(queue& q)
{
    while (q.head) delete_elem(q);
    q.tail = nullptr;
}




/*Определение метода, с помощью которого вызван скрипт
*/

bool is_get()
{
    size_t realsize;
    char* value = new char[5];
    getenv_s(&realsize, value, 5, "REQUEST_METHOD");
    bool res = !_strcmpi(value, "GET");
    delete[] value;
    return res;
}

/*Получение информации о длине сообщения от пользователя, переданного методом POST
*/

size_t get_content_length()
{
    size_t realsize;
    char* value = new char[11];
    getenv_s(&realsize, value, 11, "CONTENT_LENGTH");
    size_t size;
    if (!realsize) size = 0;
    else sscanf_s(value, "%d", &size);
    delete[] value;
    return size;
}

/* Получение данных из формы в необработанном виде
 */

void get_form_data(char*& data)
{
    delete[] data;
    if (is_get())
    {
        size_t realsize;
        char* value = new char[65536];
        getenv_s(&realsize, value, 65536, "QUERY_STRING");
        data = new char[realsize + 1];
        strcpy_s(data, realsize + 1, value);
        delete[] value;
    }
    else
    {
        size_t buf_size = get_content_length();
        data = new char[buf_size + 1];
        fread_s(
            data,
            buf_size + 1,
            sizeof(char),
            buf_size,
            stdin
        );
        data[buf_size] = 0;
    }
}

/*Получение значения конкретного параметра, полученного от пользователя
*/

void get_param_value(char*& value, const char* param_name, const char* data)
{
    delete[] value;
    value = nullptr;
    char* str = _strdup(data);
    char* tmp = str;
    char* cont;
    while (char* part = strtok_s(tmp, "&", &cont))
    {
        tmp = nullptr;
        char* val;
        char* key = strtok_s(part, "=", &val);
        if (!_strcmpi(param_name, key))
        {
            str_decode(value, val);
            //value = _strdup(val);
            delete[] str;
            return;
        }
    }
    delete[] str;
    value = new char[1];
    value[0] = 0;
}

/*Раскодирование переданных данных
*/

void str_decode(char*& dec_str, const char* enc_str)
{
    char* res = new char[strlen(enc_str) + 1];
    int i = 0, j = 0;
    while (enc_str[i])
    {
        if (enc_str[i] == '+')
        {
            res[j] = ' ';
        }
        else
        {
            if (enc_str[i] == '%')
            {
                char ch[3] = { enc_str[i + 1], enc_str[i + 2], 0 };
                int c;
                sscanf_s(ch, "%X", &c);
                res[j] = c;
                i += 2;
            }
            else
            {
                res[j] = enc_str[i];
            }
        }
        i++;
        j++;
    }
    res[j] = 0;
    size_t len = strlen(res) + 1;
    delete[] dec_str;
    dec_str = new char[len];
    strcpy_s(dec_str, len, res);
    delete[] res;
}

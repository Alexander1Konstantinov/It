#include "list.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

void add(elem*& first, int data)
{
	elem* newel = new elem;
	newel->a = data;
	if (first)
	{
		elem* curr = first;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newel;
	}
	else {
		first = newel;
	}
}

void insert(elem*& first, int data, int pos) {
	elem* newel = new elem;
	newel->a = data;
	if (!first || pos <= 1) {
		newel->next = first; //связка нового элемента с пустым началом списка
		first = newel; // объявляем newel началом

	}
	else {
		elem* curr = first;
		int p = 0;
		while (p < pos - 2 && curr->next) {
			curr = curr->next;
			p++;
		}
		newel->next = curr->next;
		curr->next = newel;
	}
}

const int* get(const elem* first, int pos)
{
	if (pos < 0 || !first) {
		return nullptr;
	}
	elem* curr = (elem*)first;
	int p = 1;
	while (p < pos && curr) {
		curr = curr->next;
		p++;
	}
	if (curr) return &curr->a;
	return nullptr;
}

int count(const elem* first)
{
	int temp = 0;
	elem* curr = (elem*)first;
	while (curr) {
		temp++;
		curr = curr->next;
	}
	return temp;
}

bool remove(elem*& first, int pos)
{
	if (!first || pos < 0) return false;
	pos--;
	if (!pos) {
		elem* rem = first;
		first = first->next;
		delete rem;
		return true;
	}
	int p = 0;
	elem* curr = first;
	while (p < pos - 1 && curr->next) {
		curr = curr->next;
		p++;
	}
	if (curr->next) {
		elem* rem = curr->next;
		curr->next = curr->next->next;
		delete rem;
		return true;
	}
	return false;
}

void clear(elem*& first)
{
	while (first) {
		elem* rem = first;
		first = first->next;
		delete rem;
	}
}

void show(elem* list)
{
	bool flag = 0;
	elem* cur = list;
	if (!cur) { cout << "empty list"; }
	else while (cur) {
		if (flag)
			cout << cur->a << "; ";
		flag = 1;
		cur = cur->next;
	}
}
/*bool fill_list(elem*& list, const char* filename)
{
	ifstream f(filename);
	if (f.is_open())
	{
		char* data = new char[31];
		while (!f.eof())
		{
			f.getline(data, 31);
			if (f.fail())
			{
				f.close();
				clear(list);
				return false;
			}
			int cnt, v, p;
			cnt = sscanf_s(data, "%d" "%d", &v, &p);
			switch (cnt)
			{
			case 1:
			{
				add(list, v);
				break;
			}
			case 2:
			{
				insert(list, v, p);
			}
			}
		}
		f.close();
		delete[] data;
		return true;
	}
	return false;
}*/
void show_odd(const elem* list) {
	int cnt = count(list);
	for (int i = 1; i < cnt; i += 2) {
		auto val = get(list, i);
		cout << *val;
	}
}
bool is_get()
{
	size_t realsize;
	char* value = new char[5];
	getenv_s(&realsize, value, 5, "REQUEST_METHOD");
	bool res = !_strcmpi(value, "GET");
	delete[] value;
	return res;
}

/**
 * Получение информации о длине сообщения от пользователя, переданного
 * методом POST
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

/**
 * Получение данных из формы в необработанном виде
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

/**
 * Получение значения конкретного параметра, полученного от пользователя
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

/**
 * Раскодирование переданных данных
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




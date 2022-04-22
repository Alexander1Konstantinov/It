#pragma once
#include <iostream>
struct elem
{
	int a;
	elem* next = nullptr;
};
void add(elem*& list, int data);
void insert(elem*& list, int data, int position);
const int* get(const elem* list, int position);
int count(const elem* list);
bool remove(elem*& list, int position);
void clear(elem*& list);
void show(elem* list);
//bool fill_list(elem*& list, const char* filename);
bool is_get();
size_t get_content_length();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);

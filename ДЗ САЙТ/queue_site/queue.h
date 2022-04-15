#pragma once
struct man
{
	char name[50];
	char sex[50];
	int age;
	char job[50];
	int income;
	char goal[50];

};

struct elem
{
	man value; // информационное поле
	elem* next = nullptr; // адресное поле структуры
};

struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t lenght = 0;
};

void enqueue(queue& q, const char* name, const char* sex, int age, const char* job, int income, const char* goal);
void enqueue(queue& q, man m);
bool dequeue(queue& q, man& m);
void clear(queue& q);
bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);
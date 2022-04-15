#pragma once
struct elem
{
    char value;
    int ord;
    elem* next = nullptr;
};
void push(elem*& stack, char value, int ord);
bool pop(elem*& stack, char& value, int& ord);
void clear(elem*& stack);

bool is_get();
void get_form_data(char*& data);
void get_param_value(char*& value, const char* param_name, const char* data);
void str_decode(char*& dec_str, const char* enc_str);

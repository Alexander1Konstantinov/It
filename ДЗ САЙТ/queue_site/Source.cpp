#include <iostream>
#include "queue.h"
#include <fstream>
#include <string>
using namespace std;

void show_content();

void load_data(const char* filename, queue& dep, queue& cred);

void show_queue(queue& q);

queue deposit;
queue credit;

void main()
{
	setlocale(LC_ALL, "Russian");

	load_data("clients.txt", deposit, credit);

	cout << "Content-type: text/html; charset=Windows-1251\n\n";
	ifstream f("queue");
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
		cout << "Ошибка";
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

	cout << "<form method='post' action='queue.cgi'>";
	cout << "<div class='form-content'>";
	cout << "<textarea id='msg' type='text' name='imya'>";

	if (!(data && strlen(data) > 0)) {
		ifstream text("clients.txt");
		auto sz = 65536;
		auto buf = new char[sz];
		while (!text.eof()) {
			text.getline(buf, sz);
			cout << buf << "\n";
		}
		text.close();
	}
	else {
		cout << "Вкладчики:\n";
		show_queue(deposit);
		cout << "Кредиторы:\n";
		show_queue(credit);
		char* value = nullptr;
		get_param_value(value, "imya", data);
	}

	cout << "</textarea>";
	cout << "<div class='button-container'>";
	cout << "<input type='submit' value='Разбить клиентов на очереди'>";
	cout << "</div>";
	cout << "</div>";
	cout << "</div>";
	cout << "</form>";

	delete[] data;
}

void load_data(const char* filename, queue& dep, queue& cred)
{
	ifstream f(filename);
	if (f.is_open())
	{
		while (!f.eof())
		{
			char* man = new char[200];
			f.getline(man, 200);
			char* name = new char[50];
			char* sex = new char[50];
			int age;
			char* job = new char[50];
			int income;
			char* goal = new char[50];
			sscanf_s(man, "%s %s %d %s %d %s", name, 50, sex, 50, &age, job, 50, &income, goal, 50);
			// printf("name: %s sex: %s age: %d job: %s income: %d goal: %s\n", name, sex, age, job, income, goal);
			if (string(goal) == "Кредит") enqueue(cred, name, sex, age, job, income, goal);
			else enqueue(dep, name, sex, age, job, income, goal);
		}
		f.close();
	}
	else
		cout << "Ошибка";
}

void show_queue(queue& q)
{
	int i = 0;
	while (true)
	{
		man m;
		if (dequeue(q, m))
		{
			cout << ++i << ".\t" << m.name << " " << m.sex << " " << m.age << " " << m.job << " " << m.income << " " << m.goal << "\n";
		}
		else
		{
			break;
		}
	}
}
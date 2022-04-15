#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct man
{
    /// Имя человека
    char name1[50];
    char name2[50];
    char sex[50];
    int age;
    char job[50];
    int salary;
    char purpose[50];
};

struct elem
{
    /// Информационное поле
    man m;
    /// Адресное поле
    elem* next = nullptr;
};

/// Структура для работы с очередью, хранящая указатели на ее начало и конец
struct queue
{
    /// Первый элемент очереди (голова)
    elem* head = nullptr;
    /// Последний элемент очереди (хвост)
    elem* tail = nullptr;
    /// Количество элементов в очереди
    size_t size = 0;
};

inline man create_elem(const char* name1, const char* name2, const char* sex, int age, const char*job, int salary, const char* purpose)
{
    man m;
    strcpy_s(m.name1, name1);
    strcpy_s(m.name2, name2);
    strcpy_s(m.sex, sex);
    m.age = age;
    strcpy_s(m.job, job);
    m.salary = salary;
    strcpy_s(m.purpose, purpose);
    return m;
}

void enqueue(queue& queue, const char* name1, const char* name2, const char* sex, int age, const char* job, int salary, const char* purpose)
{
    // Создаем новый элемент для размещения в очереди
    man newm = create_elem(name1,name2, sex, age, job, salary, purpose);
    elem* newel = new elem;
    newel->m = newm;
    if (!queue.tail)
    {
        // Если очереди еще не было, новый элемент становится единственным в ней
        queue.head = queue.tail = newel;
    }
    else
    {
        // Если очередь уже была, новый элемент помещается в конец:
        queue.tail->next = newel;
        queue.tail = newel;
    }
    queue.size++;
}

bool dequeue(queue& queue, man& m)
{
    if (!queue.head) // Очереди нет
        return false; // Вернуть значение невозможно
   // Сохраняем возвращаемое значение
    m = queue.head->m;
    // Сохраняем указатель на начало очереди
    elem* rem = queue.head;
    // Изменяем адрес головного элемента
    queue.head = queue.head->next;
    // Если бы в структуре была строка в виде динамического массива, здесь нужно было бы
    // предварительно очистить память из-под этой строки!
    // Удаляем элемент с головы очереди
    delete rem;
    // Если элементов в очереди не осталось, обнуляем и указатель на ее конец.
    if (!queue.head) queue.tail = nullptr;
    queue.size--;
    return true;
}

void clear(queue& queue)
{
    // Проходим по всем элементам очереди, пока она не опустеет
    while (queue.head)
    {
        elem* rem = queue.head; // Сохраняем ссылку на удаляемый элемент
        queue.head = queue.head->next;// Переносим "голову" очереди вперед
        delete rem; // Удаляем элемент по сохраненному указателю
    }
    queue.size = 0; // Обнуляем размер очереди
    queue.tail = nullptr; // Обновляем указатель на последний элемент
}

void show_data(queue& q)
{
    int i = 0;
    while (q.size > 0)
    {
        man m;
        if (dequeue(q, m))
        {
            //Элемент получен, выводим данные
            cout << ++i << ".\t" << m.name1<<' '<<m.name2 <<"\n" << "\tПол:" << m.sex <<"\n"<<"\tВозраст:" << m.age << "\n"<<"\tРабота:" << m.job << "\n" << "\tЗарплата:" << m.salary << "\n"<<"\tЦель обращения в банк:" << m.purpose << "\n";
        }
    }
}
void load_data(const char* filename, queue& credit, queue& deposit)
{
    ifstream f(filename);
    if (f.is_open())
    {
        //До конца файла
        while (!f.eof())
        {
            char* man = new char[61];
            //Считываем очередную строку
            f.getline(man, 61);
            char* name = new char[50];
            char* sex = new char[50];
            int age;
            char* job = new char[50];
            int salary;
            char* purpose = new char[50];
            char* name1 = new char[50];
            char* name2 = new char[50];
            //cout << man << endl;
            //Получаем имя и возраст человека в отдельных переменных
            char* context = nullptr;
            char* str = new char[strlen(man) + 1];
            strcpy_s(str, strlen(man) + 1, man);
            char* part = strtok_s(context, " ", &str);
            name1 = part;
            part = strtok_s(context, " ", &str);
            name2 = part;
            part = strtok_s(context, " ", &str);
            sex = part;
            part = strtok_s(context, " ", &str);
            age = atoi(part);
            part = strtok_s(context, " ", &str);
            job = part;
            part = strtok_s(context, " ", &str);
            salary = atoi(part);
            part = strtok_s(context, " ", &str);
            purpose = part;
            //cout << purpose << endl;
           // sscanf_s(man, "%%49[^0-9] %%49[^0-9] %d %%49[^0-9] %d %%49[^0-9]", n1, sex, &age, job, &salary, purpose);
            //cout << n1 << ' ' << sex << ' ' << age << ' ' << job << ' ' << salary << purpose << endl;
            if(!strcmp(purpose,"кредит"))
                enqueue(credit, name1, name2, sex, age, job, salary, purpose);
            else
                enqueue(deposit, name1, name2, sex, age, job, salary, purpose);
            //else //Добавляем с писок трудоспособных
              //  enqueue(deposit, name, sex, age, job, salary, purpose);
        }
        f.close();
    }
}

void file_credit(const char* filename, queue& credit)
{
    ofstream f(filename);
    while(credit.size>0)
    {
        man m;
        if (dequeue(credit, m))
            f << m.name1 << ' ' << m.name2 << ' ' << m.sex <<' '<< m.age <<' '<< m.job <<' '<< m.salary <<' '<< m.purpose << "\n";
    }
}

void file_deposit(const char* filename, queue& deposit)
{
    ofstream f(filename);
    while (deposit.size > 0)
    {
        man m;
        if (dequeue(deposit, m))
            f << m.name1 << ' ' << m.name2 << ' ' << m.sex << ' ' << m.age << ' ' << m.job << ' ' << m.salary << ' ' << m.purpose << "\n";    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Создаем две очереди для работы с двумя категориями лиц:
    queue credit;
    queue deposit;
    // Загружаем данные в очереди
    char* name_of_file = new char[100];
    cin >> name_of_file;
    load_data(name_of_file, credit, deposit);
    //Выводим список лиц трудоспособного возраста:
    //cout << "Кредит:\n";
    //show_data(credit);
    //Выводим список лиц нетрудоспособного возраста:
    //cout << "Вклад:\n";
    // show_data(deposit);
    file_credit("кредит.txt", credit);
    file_deposit("вклад.txt", deposit);
    //system("pause");
}
#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a, des = 0, mil = 1, tis = 0;
	cin >> a;
	if (a > 10000000)
	{
		cout << "Ошибка";
		return 0;
	}
	if (a == 0)
	{
		cout << "Ноль";
		return 0;
	}
	switch (a / 10000000)
	{
	case 1: cout << "Десять миллионов"<<' ';
			mil = 10;
			break;
	default: break;
	}
	switch ((a / 1000000)%10)
	{
	case 1: cout << "Один миллион"<<' ';
		break;
	case 2: cout << "Два миллиона"<<' ';
		break;
	case 3: cout << "Три миллиона"<<' ';
		break;
	case 4: cout << "Четыре миллиона"<<' ';
		break;
	case 5: cout << "Пять миллионов"<<' ';
		break;
	case 6: cout << "Шесть миллионов"<<' ';
		break;
	case 7: cout << "Семь миллионов"<<' ';
		break;
	case 8: cout << "Восемь миллионов"<<' ';
		break;
	case 9: cout << "Девять миллионов"<<' ';
		break;
	default: break;
	}

	switch ((a / (100000/mil))%10)
	{
	case 1: cout << "сто"<<' ';
		tis = 1;
		break;
	case 2: cout << "двести"<<' ';
		tis = 1;
		break;
	case 3: cout << "триста"<<' ';
		tis = 1;
		break;
	case 4: cout << "четыреста"<<' ';
		tis = 1;
		break;
	case 5: cout << "пятьсот"<<' ';
		tis = 1;
		break;
	case 6: cout << "шестьсот"<<' ';
		tis = 1;
		break;
	case 7: cout << "семьсот"<<' ';
		tis = 1;
		break;
	case 8: cout << "восемьсот"<<' ';
		tis = 1;
		break;
	case 9: cout << "девятьсот"<<' ';
		tis = 1;
		break;
	default: break;
	}

	switch ((a / (10000 / mil))%10)
	{
	case 1: des = 1;
		break;
	case 2: cout << "двадцать"<<' ';
		tis = 1;
		break;
	case 3: cout << "тридцать"<<' ';
		tis = 1;
		break;
	case 4: cout << "сорок"<<' ';
		tis = 1;
		break;
	case 5: cout << "пятьдесят"<<' ';
		tis = 1;
		break;
	case 6: cout << "шестьдесят"<<' ';
		tis = 1;
		break;
	case 7: cout << "семьдесят"<<' ';
		tis = 1;
		break;
	case 8: cout << "восемьдесят"<<' ';
		tis = 1;
		break;
	case 9: cout << "девяносто"<<' ';
		tis = 1;
		break;
	default: break;
	}

	if(des == 1)
		switch ((a / (1000 / mil))%10)
		{
		case 0: cout << "Десять тысяч";
			break;
		case 1: cout << "одиннадцать тысяч" << ' ';
			break;
		case 2: cout << "двенадцать тысяч" << ' ';
			break;
		case 3: cout << "тринадцать тысяч" << ' ';
			break;
		case 4: cout << "четырнадцать тысяч" << ' ';
			break;
		case 5: cout << "пятнадцать тысяч" << ' ';
			break;
		case 6: cout << "шестнадцать тысяч" << ' ';
			break;
		case 7: cout << "семнадцать тысяч" << ' ';
			break;
		case 8: cout << "восемнадцать тысяч" << ' ';
			break;
		case 9: cout << "девятнадцать тысяч" << ' ';
			break;
		default: if (tis == 1)
			cout << "тысяч";
			break;
		}
	else
		switch ((a / (1000 / mil))%10)
		{
		case 1: cout << "одна тысяча"<<' ';
			break;
		case 2: cout << "две тысячи"<<' ';
			break;
		case 3: cout << "три тысячи"<<' ';
			break;
		case 4: cout << "четыре тысячи"<<' ';
			break;
		case 5: cout << "пять тысяч"<<' ';
			break;
		case 6: cout << "шесть тысяч"<<' ';
			break;
		case 7: cout << "семь тысяч"<<' ';
			break;
		case 8: cout << "восемь тысяч"<<' ';
			break;
		case 9: cout << "девять тысяч"<<' ';
			break;
		default:  if (tis == 1)
			cout << "тысяч";
			break;
		}
	
	switch ((a / (100 / mil))%10)
	{
	case 1: cout << "сто" << ' ';
		break;
	case 2: cout << "двести" << ' ';
		break;
	case 3: cout << "триста" << ' ';
		break;
	case 4: cout << "четыреста" << ' ';
		break;
	case 5: cout << "пятьсот" << ' ';
		break;
	case 6: cout << "шестьсот" << ' ';
		break;
	case 7: cout << "семьсот" << ' ';
		break;
	case 8: cout << "восемьсот" << ' ';
		break;
	case 9: cout << "девятьсот" << ' ';
		break;
	default: break;
	}

	des = 0;

	switch ((a / (10 / mil)) % 10)
	{
	case 1: des = 1;
		break;
	case 2: cout << "двадцать" << ' ';
		break;
	case 3: cout << "тридцать" << ' ';
		break;
	case 4: cout << "сорок" << ' ';
		break;
	case 5: cout << "пятьдесят" << ' ';
		break;
	case 6: cout << "шестьдесят" << ' ';
		break;
	case 7: cout << "семьдесят" << ' ';
		break;
	case 8: cout << "восемьдесят" << ' ';
		break;
	case 9: cout << "девяносто" << ' ';
		break;
	default: break;
	}

	if (des == 1)
		switch (a % 10)
		{
		case 0: cout << "десять" << ' ';
			break;
		case 1: cout << "одиннадцать" << ' ';
			break;
		case 2: cout << "двенадцать" << ' ';
			break;
		case 3: cout << "тринадцать" << ' ';
			break;
		case 4: cout << "четырнадцать" << ' ';
			break;
		case 5: cout << "пятнадцать" << ' ';
			break;
		case 6: cout << "шестнадцать" << ' ';
			break;
		case 7: cout << "семнадцать" << ' ';
			break;
		case 8: cout << "восемнадцать" << ' ';
			break;
		case 9: cout << "девятнадцать" << ' ';
			break;
		default: break;
		}
	else
		switch (a % 10)
		{
		case 1: cout << "один" << ' ';
			break;
		case 2: cout << "два" << ' ';
			break;
		case 3: cout << "три" << ' ';
			break;
		case 4: cout << "четыре" << ' ';
			break;
		case 5: cout << "пять" << ' ';
			break;
		case 6: cout << "шесть" << ' ';
			break;
		case 7: cout << "семь" << ' ';
			break;
		case 8: cout << "восемь" << ' ';
			break;
		case 9: cout << "девять" << ' ';
			break;
		default: break;
		}
	return 0;
}
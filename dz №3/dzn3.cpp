#include <iostream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int m, d;
	cin >> m >> d;
	if (m < 1 or m>12)
	{
		cout << "Ошибка";
		return 0;
	}
	else
		if (d < 1 or d>31)
		{
			cout << "Ошибка";
			return 0;
		}
		else
			if (m == 2 && d > 29)
			{
				cout << "Ошибка";
				return 0;
			}
			else
				if (m == 4 && d > 30)
				{
					cout << "Ошибка";
					return 0;
				}
				else
					if (m == 6 && d > 30)
					{
						cout << "Ошибка";
						return 0;
					}
					else
						if (m == 9 && d > 30)
						{
							cout << "Ошибка";
							return 0;
						}
						else
							if (m == 11 && d > 30)
							{
								cout << "Ошибка";
								return 0;
							}
	switch (m)
	{
	case 1:
		cout << 365 - d;
		break;
	case 2:
		cout << 365 - 31 - d;
		break;
	case 3:
		cout << 365 - 31 - 28 - d;
		break;
	case 4:
		cout << 365 - 31 - 28 - 31 - d;
		break;
	case 5:
		cout << 365 - 31 - 28 - 31 - 30 - d;
		break;
	case 6:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - d;
		break;
	case 7:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 -  d;
		break;
	case 8:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - d;
		break;
	case 9:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - d;
		break;
	case 10:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - d;
		break;
	case 11:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - d;
		break;
	case 12:
		cout << 365 - 31 - 28 - 31 - 30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 - d;
		break;
	}
}
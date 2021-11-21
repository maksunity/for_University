#include <iostream>
using namespace std;

int arr[15][15];
int n = 5;

void Edit()
{
	bool flag = false;
	while (flag != true)
	{
		system("cls");
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 && j == 0) cout << " | ";
				else cout << arr[i][j] << " | ";
			}
			cout << endl;
		}
		int num;
		cout << endl << "Режим измений:" << endl;
		cout << "1 - изменить размерность" << endl;
		cout << "2 - заполнить множество" << endl;
		cout << "3 - заполнить множество по координатам" << endl;
		cout << "4 - покинуть режим редактирования" << endl;
		cout << "Введите операцию: ";
		cin >> num;
		cout << endl;
		switch (num)
		{
		case 1:
		{
			int check = 0;
			while (check != 1)
			{
				cout << "Введите длину стороны отношения: ";
				cin >> n;
				if (n >= 1 && n <= 10)
				{
					check = 1;
					system("cls");
				}
				else
				{
					cout << "Ошибка, значение ни 0, ни 1. Поворите ввод.." << endl;
				}
			}
		}
		break;

		case 2:
		{
			int check = 0;
			while (check != 1)
			{
				cout << "(отношение заполняется построчно нулями и единицами)" << endl;
				cout << "Введите элементы отношения: " << endl;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						cin >> arr[i][j];
						if (arr[i][j] == 0 || arr[i][j] == 1)
						{
							if (i == n && j == n)
							{
								check = 1;
								system("cls");
							}
						}
						else
						{
							cout << "Ошибка, значение ни 0, ни 1. Поворите ввод.." << endl;
							j--;
						}
					}
				}
			}
		}
			break;

		case 3:
		{
			int i = 0;
			int j = 0;
			cout << "(отношение заполняется нулями и единицами)" << endl;
			int check = 0;
			while (check != 1)
			{
				cout << "Введите номер строки: ";
				cin >> i;
				if (i > 0 && i <= n)
				{
					check = 1;
				}
				else
				{
					cout << "Ошибка, значение ни 0, ни 1. Поворите ввод.." << endl;
				}
			}
			check = 0;
			while (check != 1)
			{
				cout << "Введите номер столбца: ";
				cin >> j;
				if (j > 0 && j <= n)
				{
					check = 1;
				}
				else
				{
					cout << "Ошибка, значение ни 0, ни 1. Поворите ввод.." << endl;
				}
			}
			check = 0;
			while (check != 1)
			{
				cout << "Введите значение (1 или 0): ";
				cin >> arr[i][j];
				if (arr[i][j] == 0 || arr[i][j] == 1)
				{
					check = 1;
					if (i == n && j == n)
					{
						check = 1;
						system("cls");
					}
				}
				else
				{
					cout << "Ошибка, значение ни 0, ни 1. Поворите ввод.." << endl;
				}
			}
		}
			break;
			
		case 4:
		{
			flag = 1;
		}
		break;
	}
		}
}

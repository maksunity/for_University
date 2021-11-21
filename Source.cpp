#include <iostream>

using namespace std;

int mas[11][11];
int n = 5;

void editing()
{
	bool flag = 0;
	while (flag != 1)
	{
		system("cls");
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 && j == 0) cout << "  ";
				else cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		int num;
		cout << endl << "Редактирование отношения:" << endl;
		cout << "1 - изменить размер отношения" << endl;
		cout << "2 - заполнить всё отношение" << endl;
		cout << "3 - заполнить множество по координатам" << endl;
		cout << "4 - покинуть режим редактирования" << endl;
		cout << "Введите операцию: ";
		cin >> num;
		cout << endl;
		if (num == 1)
		{
			int flag2 = 0;
			while (flag2 != 1)
			{
				cout << "Введите длину стороны отношения (максимум 10, минимум 1): ";
				cin >> n;
				if (n >= 1 && n <= 10)
				{
					flag2 = 1;
					system("cls");
				}
				else
				{
					cout << "Ошибка!!! Неверно заданная длина. Повторите попытку."<<endl;
				}
			}
		}
		else if(num == 2)
		{
			int flag2 = 0;
			while (flag2 != 1)
			{
				cout << "(отношение заполняется построчно нулями и единицами)"<<endl;
				cout << "Введите элементы отношения: "<<endl;
				for (int i = 1; i <= n; i++)
				{
					for (int j = 1; j <= n; j++)
					{
						cin >> mas[i][j];
						if (mas[i][j]==0 || mas[i][j]==1)
						{
							if (i == n && j == n)
							{
								flag2 = 1;
								system("cls");
							}
						}
						else
						{
							cout << "Ошибка!!! Неверно значение. Повторите попытку." << endl;
							j--;
						}
					}
				}
			}
		}
		else if (num == 3)
		{
			int i = 0, j = 0;
			cout << "(отношение заполняется нулями и единицами)" << endl;
			int flag2 = 0;
			while (flag2 != 1)
			{
				cout << "Введите номер строки: ";
				cin >> i;
				if (i > 0 && i <= n)
				{
					flag2 = 1;
				}
				else
				{
					cout << "Ошибка!!! Неверно значение. Повторите попытку." << endl;
				}
			}
			flag2 = 0;
			while (flag2 != 1)
			{
				cout << "Введите номер столбца: ";
				cin >> j;
				if (j > 0 && j <= n)
				{
					flag2 = 1;
				}
				else
				{
					cout << "Ошибка!!! Неверно значение. Повторите попытку." << endl;
				}
			}
			flag2 = 0;
			while (flag2 != 1)
			{
				cout << "Введите значение (1 или 0): ";
				cin >> mas[i][j];
				if (mas[i][j] == 0 || mas[i][j] == 1)
				{
					flag2 = 1;
					if (i == n && j == n)
					{
						flag2 = 1;
						system("cls");
					}
				}
				else
				{
					cout << "Ошибка!!! Неверно значение. Повторите попытку." << endl;
				}
			}
		}
		else if (num == 4)
		{
			flag = 1;
		}
		else cout << "ОШИБКА!!! Неизвестная операция. Повторите попытку." << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	bool flag = 0;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			mas[i][j] = 0;
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		mas[i][0] = i;
		mas[0][i] = i;
	}
	while (flag != 1)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
		cout <<endl<< "Свойство отношения:" << endl;
		bool flag2 = 0;
		// Рефлексивность|Антирефлексивность
		if (mas[1][1] == 1)
		{
			flag2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (mas[i][i] != 1)
				{
					flag2 = 1;
					i = n;
				}
			}
			if (flag2 == 0)
			{
				cout << "Рефлексивно" << endl;
			}
		}
		else
		{
			flag2 = 0;
			for (int i = 1; i <= n; i++)
			{
				if (mas[i][i] != 0)
				{
					flag2 = 1;
					i = n;
				}
			}
			if (flag2 == 0)
			{
				cout << "Антирефлексивно" << endl;
			}
		}
		//Симметричность
		flag2 = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (mas[i][j] != mas[j][i])
				{
					flag2 = 1;
					j = n;
					i = n - 1;
				}
			}
		}
		if (flag2 == 0)
		{
			cout << "Симметрично" << endl;
		}
		//Антисимметричность
		flag2 = 0;
		if (flag2 == 0)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (mas[i][j] == 1 && mas[j][i] == 1)
					{
						flag2 = 1;
						j = n;
						i = n - 1;
					}
				}
			}
		}
		if (flag2 == 0)
		{
			cout << "Антисимметрично" << endl;
		}
		//Асимметричность
		flag2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (mas[i][i] != 0)
			{
				flag2 = 1;
				i = n;
			}
		}
		if (flag2 == 0)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (mas[i][j] ==1 && mas[j][i]==1)
					{
						flag2 = 1;
						j = n;
						i = n - 1;
					}
				}
			}
		}
		if (flag2 == 0)
		{
			cout << "Асимметрично" << endl;
		}
		//Транзитивность
		flag2 = 0;
		int s = 0,s2=0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s = s + mas[i][j];
				if (i != j)
				{
					s2 = s2 + mas[i][j];
				}
			}
		}
		if (s == 0 || s2==0) flag2 = 1;
		s = 0;
		if (flag2 == 0)
		{
			int mas2[11][11];
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					mas2[i][j] = 0;
					for (int h = 1; h <= n; h++)
					{
						mas2[i][j] = mas2[i][j] + (mas[i][h] * mas[h][j]);
					}
					s = s + mas2[i][j];
				}
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (mas2[i][j] != 0 && mas[i][j] == 0)
					{
						flag2 = 1;
					}
				}
			}
		}
		if (flag2 == 0 && s!=0)
		{
			cout << "Транзитивно" << endl;
		}
		//Связность
		flag2 = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (mas[i][j] ==0  &&  mas[j][i]==0)
				{
					flag2 = 1;
					j = n;
					i = n - 1;
				}
			}
		}
		if (flag2 == 0)
		{
			cout << "Связно" << endl;
		}
		int num;
		cout << endl << "Операции:" << endl;
		cout << "1 - редактирование отношения " << endl;
		cout << "2 - выход" << endl;
		cout << "Введите операцию: ";
		cin >> num;
		if (num == 1)
		{
			editing(); 
			system("cls");
		}
		else if (num == 2)
		{
			flag = 1;
			system("cls");
		}
		else cout << "ОШИБКА!!! Неизвестная операция. Повторите попытку." << endl;
	}
	return 0;
}
#include "Header.h"";
#include <iostream>;

using namespace std;

int main()
{
	bool flag = false;
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		arr[i][0] = i;
		arr[0][i] = i;
	}
	while (flag != true)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << "Свойство отношения:" << endl;
		bool sec_flag = false;
		// Рефлексивность|Антирефлексивность
		if (arr[1][1] == 1)
		{
			sec_flag = false;
			for (int i = 1; i <= n; i++)
			{
				if (arr[i][i] != 1)
				{
					sec_flag = true;
					i = n;
				}
			}
			if (sec_flag == false)
			{
				cout << "Рефлексивно" << endl;
			}
		}
		else
		{
			sec_flag = false;
			for (int i = 1; i <= n; i++)
			{
				if (arr[i][i] != 0)
				{
					sec_flag = true;
					i = n;
				}
			}
			if (sec_flag == false)
			{
				cout << "Антирефлексивно" << endl;
			}
		}
		//Симметричность
		sec_flag = false;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					sec_flag = true;
					j = n;
					i = n - 1;
				}
			}
		}
		if (sec_flag == false)
		{
			cout << "Симметрично" << endl;
		}
		//Антисимметричность
		sec_flag = false;
		if (sec_flag == false)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (arr[i][j] == 1 && arr[j][i] == 1)
					{
						sec_flag = true;
						j = n;
						i = n - 1;
					}
				}
			}
		}
		if (sec_flag == false)
		{
			cout << "Антисимметрично" << endl;
		}
		//Асимметричность
		sec_flag = false;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i][i] != 0)
			{
				sec_flag = true;
				i = n;
			}
		}
		if (sec_flag == false)
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = i + 1; j <= n; j++)
				{
					if (arr[i][j] == 1 && arr[j][i] == 1)
					{
						sec_flag = true;
						j = n;
						i = n - 1;
					}
				}
			}
		}
		if (sec_flag == false)
		{
			cout << "Асимметрично" << endl;
		}
		//Транзитивность
		sec_flag = false;
		int s = 0, s2 = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				s = s + arr[i][j];
				if (i != j)
				{
					s2 = s2 + arr[i][j];
				}
			}
		}
		if (s == 0 || s2 == 0) sec_flag = true;
		s = 0;
		if (sec_flag == false)
		{
			int sec_arr[15][15];
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					sec_arr[i][j] = 0;
					for (int h = 1; h <= n; h++)
					{
						sec_arr[i][j] = sec_arr[i][j] + (arr[i][h] * arr[h][j]);
					}
					s = s + sec_arr[i][j];
				}
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (sec_arr[i][j] != 0 && arr[i][j] == 0)
					{
						sec_flag = true;
					}
				}
			}
		}
		if (sec_flag == false && s != 0)
		{
			cout << "Транзитивно" << endl;
		}
		//Связность
		sec_flag = false;
		for (int i = 1; i < n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (arr[i][j] == 0 && arr[j][i] == 0)
				{
					sec_flag = true;
					j = n;
					i = n - 1;
				}
			}
		}
		if (sec_flag == false)
		{
			cout << "Связно" << endl;
		}
		int num;
		cout << endl << "Операции:" << endl;
		cout << "1 - Редактирование отношения " << endl;
		cout << "2 - Выход" << endl;
		cout << "Введите операцию: ";
		cin >> num;
		if (num == 1)
		{
			Edit();
		}
		else if (num == 2)
		{
			flag = 1;
			system("cls");
		}
		else cout << "Ошибка, введите кооректное значение" << endl;
	}
	return 0;
}
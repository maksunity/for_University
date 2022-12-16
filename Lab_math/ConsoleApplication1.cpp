#include <iostream>
#include <cmath>

using namespace std;

double fac = 1; 
double fac_new = 1;

int n, m = 0;
int num;
int buf = 0;
int arr[10];

int main()
{
	cout << "Choose operation: " << endl; //Консольное меню

	cout << "1 - Razmeshenie bez povtorenii" << endl;
	cout << "2 - Razmeshenie s povtoreniyami" << endl;
	cout << "3 - Perestanovki bez povtorenii" << endl;
	cout << "4 - Perestanovki s povtoreniyami" << endl;
	cout << "5 - Sochetaniya bez povtorenii" << endl;
	cout << "6 - Sochetaniya s povtoreniyami" << endl;
	cout << "0 - Exit" << endl;
	cin >> num;

	switch (num)
	{
	case 1: //Выводим сокращенные формулы для всех нижепредставленных операций
			//Чтобы переменных хватило для обработки больших чисел
		cout << "First enter N, after M: " << endl;
		cin >> n;
		cout << endl;
		cin >> m;
		cout << endl;

		if (m > n)
			break;
		else
			for (int i = n - m + 1; i <= n; i++)
			{
				fac = fac * i;
			}
		cout << fac;
		break;
	case 2:
		cout << "First enter N, after M: " << endl;
		cin >> n;
		cout << endl;
		cin >> m;
		cout << endl;
		if (m < 1)
			break;
		else
			for (int i = 1; i <= m; i++)
			{
				fac = fac*n;
			}
		cout << fac;
		break;
	case 3:
		cout << "Enter N: " << endl;
		cin >> n;
		cout << endl;
		for (int i = 1; i <= n; i++)
		{
			fac_new = fac_new * i;
		}
		cout << fac_new;
		break;
	case 4:
		cout << "First enter N, after M - kolvo chisel: " << endl;
		cin >> n;
		cout << endl;
		cin >> m;
		cout << "Enter elements array" << endl;
		for (int i = 0; i < m; i++)
		{
			cin >> buf;
			arr[i] = buf;
		}
		cout << endl;
		if (m > n)
			break;
		else
			for (int i = 1; i <= n; i++)
			{
				fac = fac * i;
			}
		for (int i = 0; i < m; i++)
		{
			for (int j = 1; j <= arr[i]; j++)
			{
				fac_new = fac_new * j;
			}
		}
		cout << fac/fac_new;
		break;
	case 5:
		cout << "First enter N, after M: " << endl;
		cin >> n;
		cout << endl;
		cin >> m;
		cout << endl;
		if (m > n)
			break;
		else
			for (int i = n - m + 1; i <= n; i++)
			{
				fac = fac * i;
			}
		for (int j = 1; j <=m; j++)
		{
			fac_new = fac_new * j;
		}
		cout << fac/fac_new;
		break;
	case 6:
		cout << "First enter N, after M: " << endl;
		cin >> n;
		cout << endl;
		cin >> m;
		cout << endl;
		if (m > n)
			break;
		else
			for (int i = m + 1; i <= n+m-1; i++)
			{
				fac = fac * i;
			}
		for (int j = 1; j <= n-1; j++)
		{
			fac_new = fac_new * j;
		}
		cout << fac / fac_new;
	}
		
}

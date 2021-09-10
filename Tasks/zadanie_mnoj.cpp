
#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;



void print(int bruh[], int slave)
{
	for (int i = 0; i < slave; i++)
	{
		cout << bruh[i] << "  ";
	}
	cout << endl << endl;
}


int main()
{
	setlocale(LC_ALL, "ru");
	mt19937 mersenne{ static_cast <std::mt19937::result_type> (time(nullptr)) };
	uniform_int_distribution<> die{ -9, 9 };

	int No, Noo;
	int check = 0;
	int main_arr[20] = { -9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9 };
	int second_arr[20];
	int first_arr[20];
	int third_arr[20];
	int count = 0;

	cout << "Выберите способ задания множества: " << endl << endl;
	cout << "1) Автозаполнение." << endl;
	cout << "2) Ручной ввод." << endl;
	cout << "3) Ввод по условиям." << endl;
	cout << "_";
	cin >> No;
	cout << endl;
	
	switch (No)
	{
		case(1):
			cout << "Введите кол-во элементов для множества 1: " << endl;;
			int k;
			cin >> k;
			for (int i = 0; i <= k; i++)
			{
				second_arr[i] = die(mersenne);
			}

			print(second_arr, k);

			break;

		case(2):
			
			int kol;
			for (int num = 0; num < 3; num++)
			{
				cout << "Введите кол-во символов для вашего множества: " << endl;
				cin >> kol;
				cout << "Введите цифры для " << num << " множества. Для окончания ввода введите '22'." << endl;
				for (int i = 0; i <= kol+1; i++)
				{
					while (check != 0)
					{
						cin >> first_arr[i];
						check = first_arr[i];
					}

				}

			}
			break;

		case(3):
			cout << "Выберите условие для заполнения: " << endl << endl;
			cout << "Введите 1 для ввода по *entersort*." << endl;
			cout << "Введите 2 для ввода по *entersort*." << endl;
			cout << "Введите 3 для ввода по *entersort*." << endl;
			cout << "Введите 0 для выхода из режима." << endl;
			cout << "_";
			cin >> Noo;

			switch (Noo)
			{
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(0):
				break;
			}


			break;

	}


}

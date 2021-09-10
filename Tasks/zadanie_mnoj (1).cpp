#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;



void print(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << "  ";
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
	int first_arr[20]; int second_arr[19]; int third_arr[20];
	int count = 0;

	for (int num = 1; num<=3; num++)
	{
	cout << "Выберите способ задание" << num << "множества: " << endl << endl;
	cout << "1) Автозаполнение." << endl;
	cout << "2) Ручной ввод." << endl;
	cout << "3) Ввод по условиям." << endl;
	cout << "_";
	cin >> No;
	cout << endl;
	
	switch (No)
	{
		case(1):
			cout << "Введите кол-во элементов для" << num << "множества: " << endl;;
			int kol1;
			cin >> kol1;
			for (int i = 0; i <= kol1; i++)
			{
				first_arr[i] = die(mersenne);
			}

			print(first_arr, kol1);
			break;

		case(2):
				int kol2 = 0;
				int check;
				cout << "Введите цифры для " << num << " множества. Для окончания ввода введите '22'." << endl;
				for (int i = 0; i <= 19; i++)
				{
					
					cin >> check;
					kol2++;
					if ((check == 22) || (check <= -10) || (check >= 10))
					{
						kol2--;
						print(second_arr, kol2);
						break;
					}
					else
					{
						second_arr[i] = check;
					}

					for (int fi = 0; fi <= kol2-1 ; fi++)
					{
						for (int se = fi+1 ; se <=kol2; se++)
						{
							if (second_arr[fi] == second_arr[se])
							{
								cout << "Error! Числа не могут повторяться, повторите ввод заново или выберите другой вариант ввода!";
								num--;
								i=20;
							}
						}
					}

				}
			break;

		case(3):
			cout << "Выберите условие для заполнения: " << endl << endl;
			cout << "Введите 1 для ввода по четности." << endl;
			cout << "Введите 2 для ввода по знаку." << endl;
			cout << "Введите 3 для ввода по кратности." << endl;
			cout << "Введите 0 для выхода из режима." << endl;
			cout << "_";
			cin >> Noo;

			switch (Noo)
			{
			case(1):
				int flag;
				cout << "Введите 1, чтобы внести в множество только нечетные элементы";
				cout << "Введите 2, чтобы внести в множество только четные элементы";
				cin >> flag;
				


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
}

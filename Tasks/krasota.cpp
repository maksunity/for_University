#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>
#include <iterator>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> main_vector = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vec_1;
	vector<int> vec_2; //инициализируем вектора, для будущих множеств
	vector<int> vec_3;
	vector<int> vec_res;
	vector<int> vec_help;
	vector<int>::iterator out1;
	vector<int>::iterator out2;
	vector<int>::iterator out3;
	int main_menu, menu_3, operation_menu, exit;

	mt19937 range{static_cast<std::mt19937::result_type>(time(nullptr))};
	uniform_int_distribution<> num{-9, 9}; //функция для заполнения ветора из диапазона
										   // Ниже консольное меню и главный цикл

	while (exit != 0)
	{
		cout << "Choose the method of setting the set: " << endl;
		cout << "1) Autofill." << endl;
		cout << "2) Manual input." << endl;
		cout << "3) Input according to the conditions." << endl;
		cout << "To end the program, enter 0." << endl;
		cin >> main_menu;
		cout << endl;

		switch (main_menu)
		{
		case (1):
			cout << "Enter the number of elements for the set: " << endl;
			int count;
			count = 0;
			cin >> count;
			for (int i = 0; i < count; i++)
			{
				vec_1.push_back(num(range));
			}

			out1 = unique(vec_1.begin(), vec_1.end());
			vec_1.resize(distance(vec_1.begin(), out1));

			for (out1 = vec_1.begin(); out1 != vec_1.end(); out1++)
			{
				cout << *out1 << " | ";
			}

			/*for (int i=0; i<count-1;i++)
            {
                for (int j=i+1; j<count){
                    if (vec_1[i]==vec_1[j])
                    {

                    }
                }
            }*/

			break;

		case (2):
			cout << "Enter the numbers for the set. To end the input, enter '22'." << endl;
			int check;
			for (int i = 0; i < 19; i++)
			{
			tryAgain:
				while (check != 22)
				{
					cin >> check;
					if ((check <= -10) || (check >= 10) && (check != 22))
					{
						cout << "Error! Repeat input..." << endl;
						goto tryAgain;
					}
					else
						vec_2.push_back(check);
				}
				goto done;
			}

		done:
			out2 = unique(vec_2.begin(), vec_2.end());
			vec_2.resize(distance(vec_2.begin(), out2));
			for (out2 = vec_2.begin(); out2 < vec_2.end() - 1; out2++)
			{
				cout << *out2 << " | ";
			}

			break;

		case (3):
			cout << "Select the condition to fill in: " << endl;
			cout << "Enter 1 to enter by parity." << endl;
			cout << "Enter 2 to enter by sign." << endl;
			cout << "Enter 3 to enter by multiplicity." << endl;
			cout << "Enter 0 to exit the mode." << endl;
			cout << "_";
			cin >> menu_3;

			switch (menu_3)
			{
			case (1):
				bool flag;
				cout << "Enter 0 to add only odd elements to the set" << endl;
				cout << "Enter 1 to add only even elements to the set" << endl;
				cin >> flag;

				if (flag == false)
				{
					for (int size = 0; size < main_vector.size(); size++)
					{
						if (main_vector[size] % 2 == 0)
						{
							vec_3.push_back(main_vector[size]);
						}
					}
				}
				else
				{
					for (int size = 0; size < main_vector.size(); size++)
					{
						if (main_vector[size] % 2 != 0)
						{
							vec_3.push_back(main_vector[size]);
						}
					}
				}
				for (int i = 0; i < vec_3.size(); i++)
				{
					cout << vec_3[i] << " | ";
				}
				break;

			case (2):
				bool flag2;
				int k;
				k = 0;
				cout << "Enter 0 to add only non-negative elements to the set" << endl;
				cout << "Enter 1 to add only negative elements to the set" << endl;
				cin >> flag2;

				if (flag2 == false)
				{
					for (int size = 0; size <= vec_3.size(); size++)
					{
						if (vec_3[size] < 0)
						{
							vec_3.erase(vec_3.begin() + size);
						}
					}
				}

				else
				{
					for (int size = 0; size <= vec_3.size(); size++)
					{
						if (vec_3[size] >= 0)
						{
							vec_3.erase(vec_3.begin() + size);
						}
					}
				}

				for (int i = 0; i < vec_3.size(); i++)
				{
					cout << vec_3[i] << " | ";
				}
				break;

			case (3):

				break;

			case (0):
				break;
			}

			break;
		}
		cout << "Programm close. See you later!";
		break;
	}

	return 0;
}
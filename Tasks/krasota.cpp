#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>
#include <iterator>
#include <iomanip>
#include <algorithm>

using namespace std;

vector<int> main_vector = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> vec_1;
vector<int> vec_2; //инициализируем вектора, для будущих множеств
vector<int> vec_3;
vector<int> vec_res;
vector<int> vec_help;
vector<int>::iterator out1;
vector<int>::iterator out2;
vector<int>::iterator out3;
int menu_3, operation_menu;

vector<int> enter(vector<int> vec)
{
	int exit, main_menu, r;

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
		case '1':
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
			break;

		case '2':
			/**cout << "Enter the numbers for the set. To end the input, enter '22'." << endl;
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
			**/
			cout << "Введите размер множества, меньший 20 " << endl;
			cin >> r;
			while (r > 19)
			{
				cout << "Размер множества должен быть меньше 20, введите новый " << endl;
				cin >> r;
			}
			cout << "Введите числа от -9 до 9 " << endl;
			for (int i = 0; i < r; i++)
			{
				int s;
				cin >> s;
				while (check(vec, s) || s < -9 || s > 9)
				{
					if (check(vec_1, s))
					{
						cout << "Такое число уже есть, введите другое " << endl;
						cin >> s;
					}
					if (s < -9 || s > 9)
					{
						cout << "Число не удовлетворяет условие, введите в диапазоне от -9 до 9 " << endl;
						cin >> s;
					}
				}
				vec_1.push_back(s);
			}
			vec_1 = Sort(vec_1);
			return vec_1;
			break;

		case '3':
			cout << "Select the condition to fill in: " << endl;
			cout << "Enter 1 to enter by parity." << endl;
			cout << "Enter 2 to enter by sign." << endl;
			cout << "Enter 3 to enter by multiplicity." << endl;
			cout << "Enter 0 to exit the mode." << endl;
			cout << "_";
			cin >> menu_3;

			switch (menu_3)
			{
			case '1':
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

			case '2':
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

			case '3':
				bool flag3;
				int d;
				d = 0;
				cout << "Enter divider: " << endl;
				cin >> d;
				while (d < -9 || d > 9 || d == 0)
				{
					cout << "Wrong input, try again!" << endl;
					cin >> d;
				}

				for (int i = 0; i < 19; i++)
				{
					if (vec_3[i] % d == 0)
						vec_res.push_back(vec_3[i]);
				}
				break;

			case '0':
				break;
			}

			break;
		}
		cout << "Programm close. See you later!";
		break;
	}
}

bool check(vector<int> k, int num)
{
	bool f = 0;
	for (int i = 0; i < k.size(); i++)
	{
		if (k[i] == num)
		{
			f = 1;
		}
	}
	return f;
}

vector<int> Sort(vector<int> k)
{
	int n = k.size();
	int h = n / 2;
	while (h > 0)
	{
		for (int i = 0; i < n - h; i++)
		{
			int j = i;
			while (j >= 0)
			{
				if (k[j] > k[j + h])
				{
					int d = k[j];
					k[j] = k[j + h];
					k[j + h] = d;
					j -= h;
				}
				else
					j = -1;
			}
		}
		h /= 2;
	}
	return k;
}

vector<int> inter(vector<int> a, vector<int> b)
{
	vector<int> c;
	for (int i = 0; i < a.size(); i++)
	{
		if (check(b, a[i]))
		{
			c.push_back(a[i]);
		}
	}
	return c;
}
vector<int> unific(vector<int> a, vector<int> b)
{
	vector<int> c;
	for (int i = 0; i < a.size(); i++)
	{
		c.push_back(a[i]);
	}
	for (int j = 0; j < b.size(); j++)
	{
		if (!check(c, b[j]))
		{
			c.push_back(b[j]);
		}
	}
	c = Sort(c);
	return c;
}
vector<int> without(vector<int> a, vector<int> b)
{
	vector<int> c;
	for (int i = 0; i < a.size(); i++)
	{
		if (!check(b, a[i]))
		{
			c.push_back(a[i]);
		}
	}
	return c;
}
vector<int> symmetry(vector<int> a, vector<int> b)
{
	vector<int> c;
	for (int i = 0; i < a.size(); i++)
	{
		if (!check(b, a[i]))
		{
			c.push_back(a[i]);
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		if (!check(a, b[i]))
		{
			c.push_back(b[i]);
		}
	}
	return c;
}
vector<int> no(vector<int> a)
{
	vector<int> c;
	for (int i = 0; i < 19; i++)
	{
		if (!check(a, main_vector[i]))
		{
			c.push_back(main_vector[i]);
		}
	}
	return c;
}
void print(vector<int> k)
{
	for (int i = 0; i < k.size(); i++)
	{
		cout << k[i] << " ";
	}
}

vector<vector<int>> oper(vector<int> a, vector<int> b, vector<int> c, vector<int> result)
{
	vector<vector<int>> t;
	char z;
	cout << "Enter first multitude: " << endl
		 << "1 - multitude а" << endl
		 << "2 - multitude b" << endl
		 << "3 - multitude с " << endl
		 << "4 - multitude of results past calculations" << endl;
	cin >> z;
	char w;
	switch (z)
	{
	case '1':
		cout << "Enter second multitude:" << endl
			 << "1 - multitude b" << endl
			 << "2 - multitude c" << endl
			 << "3 - multitude of results past calculations" << endl;
		cin >> w;
		if (w == '1')
		{
			t.push_back(a);
			t.push_back(b);
		}
		else if (w == '2')
		{
			t.push_back(a);
			t.push_back(c);
		}
		else if (w == '3')
		{
			if (!result.empty())
			{
				t.push_back(a);
				t.push_back(result);
			}
			else
				cout << "It's empty" << endl;
		}
		return t;
		break;
	case '2':
		cout << "Enter second multitude:" << endl
			 << "1 - multitude a" << endl
			 << "2 - multitude c" << endl
			 << "3 - multitude of results past calculations" << endl;
		cin >> w;
		if (w == '1')
		{
			t.push_back(b);
			t.push_back(a);
		}
		else if (w == '2')
		{
			t.push_back(b);
			t.push_back(c);
		}
		else if (w == '3')
		{
			if (!result.empty())
			{
				t.push_back(b);
				t.push_back(result);
			}
			else
				cout << "It's empty" << endl;
		}
		return t;
		break;
	case '3':
		cin >> w;
		if (w == '1')
		{
			t.push_back(c);
			t.push_back(a);
		}
		else if (w == '2')
		{
			t.push_back(c);
			t.push_back(b);
		}
		else if (w == '3')
		{
			if (!result.empty())
			{
				t.push_back(c);
				t.push_back(result);
			}
			else
				cout << "It's empty" << endl;
		}
		return t;
		break;
	case '4':
		if (!result.empty())
		{
			cout << "Enter second multitude:" << endl
				 << "1 - multitude a" << endl
				 << "2 - multitude b" << endl
				 << "3 - multitude c" << endl;
			cin >> w;
			if (w == '1')
			{
				t.push_back(result);
				t.push_back(a);
			}
			else if (w == '2')
			{
				t.push_back(result);
				t.push_back(b);
			}
			else if (w == '3')
			{
				if (!result.empty())
				{
					t.push_back(result);
					t.push_back(c);
				}
				else
					cout << "It's empty" << endl;
			}
			return t;
		}
		else
		{
			cout << "It's empty " << endl;
		}
		break;
	}
}

int main()
{
	bool flag = 1;
	vector<int> a;
	vector<int> b;
	vector<int> c;
	vector<int> result;
	vector<vector<int>> o;
	while (flag)
	{
		char com;
		cout << "Select:" << endl
			 << "1 - enter multitude" << endl
			 << "2 - print all multitude" << endl
			 << "3 - delete all multitude" << endl
			 << "4 - exit" << endl
			 << "5 - operations" << endl;
		cin >> com;
		switch (com)
		{
		case '1':
			a = enter(a);
			b = enter(b);
			c = enter(c);
			break;
		case '2':
			if (!a.empty() && !b.empty() && !c.empty() && !c.empty())
			{
				cout << "a: ";
				print(a);
				cout << endl
					 << "b: ";
				print(b);
				cout << endl
					 << "c: ";
				print(c);
				cout << endl
					 << "result: ";
				print(result);
				cout << endl;
			}
			break;
		case '3':
			a.clear();
			b.clear();
			c.clear();
			result.clear();
			break;
		case '4':
			flag = 0;
			break;
		case '5':
			char q;
			cout << "Select operation " << endl
				 << "1 - Crossing" << endl			   // пересечение
				 << "2- Union" << endl				   // объединение
				 << "3 - difference" << endl		   //разность
				 << "4 - symmetric difference" << endl // симметричная разность
				 << "5 - addition" << endl;			   // дополнение
			cin >> q;
			switch (q)
			{
			case '1':
				o = oper(a, b, c, result);
				result = inter(o[0], o[1]);
				print(o[0]);
				cout << endl;
				print(o[1]);
				cout << endl;
				print(result);
				cout << endl;
				break;
			case '2':
				o = oper(a, b, c, result);
				result = unific(o[0], o[1]);
				print(o[0]);
				cout << endl;
				print(o[1]);
				cout << endl;
				print(result);
				cout << endl;
				break;
			case '3':
				o = oper(a, b, c, result);
				result = without(o[0], o[1]);
				print(o[0]);
				cout << endl;
				print(o[1]);
				cout << endl;
				print(result);
				cout << endl;
				break;
			case '4':
				o = oper(a, b, c, result);
				result = symmetry(o[0], o[1]);
				print(o[0]);
				cout << endl;
				print(o[1]);
				cout << endl;
				print(result);
				cout << endl;
				break;
			case '5':
				char w;
				cout << "Enter multitude for addition " << endl
					 << "1 - multitude а " << endl
					 << "2 - multitude b" << endl
					 << "3- multitude c" << endl
					 << "4 - result multitude " << endl;
				cin >> w;
				if (w == '1')
				{
					result = no(a);
				}
				else if (w == '2')
				{
					result = no(b);
				}
				else if (w == '3')
				{
					result = no(c);
				}
				else if (w == '4')
				{
					if (!result.empty())
					{
						result = no(result);
					}
					else
						cout << "It's empty" << endl;
				}
				break;
			}
			break;
		}
	}
}
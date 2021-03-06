#include <iostream>
#include <string>
using namespace std;

string *name = new string[15];

struct Database
{
    string name;
    string birthday;
    string number;
};

int main()
{

    int a = 15;
    string name[a] = {
        "Зимин Пантелей Егорович",
        "Калинин Гарри Альбертович",
        "Егоров Альфред Семенович",
        "Костин Платон Вячеславович",
        "Носков Святослав Владимирович",
        "Емельянов Савелий Феликсович",
        "Корнилов Орест Созонович",
        "Фадеев Май Геннадиевич",
        "Щербаков Тимофей Кириллович",
        "Блинов Людвиг Витальевич",
        "Андреев Гурий Владиславович",
        "Самойлов Аристарх Авксентьевич",
        "Наумов Гордей Романович",
        "Лаврентьев Вальтер Германнович",
        "Степанов Самуил Мэлорович",
    };

    string birthday[a] = {
        "11.03.1970",
        "21.06.1970",
        "06.04.1973",
        "20.10.1973",
        "23.09.1974",
        "03.12.1974",
        "10.10.1977",
        "03.12.1977",
        "17.07.1980",
        "04.03.1981",
        "11.01.1983",
        "25.04.1984",
        "03.05.1986",
        "16.11.1986",
        "10.02.1988",
    };

    string number[a] = {
        "1",
        "12",
        "123",
        "1234",
        "12345",
        "123456",
        "1234567",
        "12345678",
        "123456789",
        "2",
        "23",
        "234",
        "2345",
        "23456",
        "234567",

    };

    cout << "Line Search : " << endl;
    // Линейный поиск по дате рождения!
    string key;
    cout << "Enter key for search: " << endl;
    cin >> key;
    for (int a = 0; a < 15; a++)
    {
        if (birthday[a] == key)
        {
            cout << "Family: " << name[a] << endl;
            cout << "Date: " << birthday[a] << endl;
            cout << "Number: " << number[a] << endl;
        }
    }
    /////////////////////////////////////////////////////////////////

    //////// Интерполяционный поиск ///////////
    /*cout << "Interpolution Search: " << endl;
    cout << "Enter new key: " << endl;
    int key_new;
    cin >> key_new;
    int mid;
    int left = 0;
    int right = a - 1;

    while (left <= key_new && right >= key_new)
    {
        mid = left + ((key_new - left) * (right - left)) / (right - left);
        if (mid < key_new)
            left = mid + 1;
        else 
        if (mid > key_new)
            right = mid - 1;
        else
            left = mid;
    }
    if (left == key_new)
    return left;
    for (int a=left ; a<=left; a++)
    {
        cout << "Family: " << name[a] << endl;
        cout << "Date: " << birthday[a] << endl;
        cout << "Number: " << number[a] << endl;
    }
    */

    ////Поиск подстроки в строке/////

    cout << "Search string in upstring: " << endl;
    string key_string;
    cin >> key_string;
    for (int a = 0; a<= 15 ; a++)
    {
        if ((birthday[a].find(key_string)) !=0)
        {
            cout << "Family: " << name[a] << endl;
            cout << "Date: " << birthday[a] << endl;
            cout << "Number: " << number[a] << endl;
        
        }
    }


return 0;
}

#include "Object.h"
#include "Print.h"

Print::Print(void)
{
    name = "";
    autor = "";
}
//деструктор
Print::~Print(void)
{
}
//констрктор с параметрами
Print::Print(string N, string A)
{
    name = N;
    autor = A;
}
//конструктор копирования
Print::Print(const Print &Print)
{
    name = book.name;
    autor = book.autor;
}

//селекторы
void Print::Set_name(string C)
{
    name = C;
}
void Print::Set_autor(string M)
{
    autor = M;
}

//оператор присваивания
Print &Print::operator=(const Print &c)
{
    if (&c == this)
        return *this;
    name = c.name;
    autor = c.autor;
    return *this;
}
//метод для просмотра атрибутов
void Print::Show()
{
    cout << "\nName: " << name;
    cout << "\nAutor: " << autor;
    cout << "\n";
}
//метод для ввода значений атрибутов
void Print::Input()
{
    cout << "\nName:";
    cin >> name;
    cout << "\nAutor:";
    cin >> autor;
}

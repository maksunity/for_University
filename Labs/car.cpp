#include <iostream>
#include<list>

using namespace std; 

struct Car{
    string CarName;
    string SerialNumber;
    string RegestrationNumber;
    string Year;
};

struct List 
{
    Car data;
    List *next;
};

List* ReadFile()
{
    List *first, *p;
    first = NULL;
    FILE *fp;
    if ((fp=fopen("Car.dat", "rb")) == NULL)
    {
        perror ("Ошибка при открытии файла");
        exit(0);
    }
    p = new List;
    if (!feof(fp))
    {
        fread(&p, sizeof(p), 1, fp);
    }
    first=p;
    fclose(fp);
    return first;
}

void NewFile (List *first)
{
    if (first == NULL)
    {
        cout << "Список пуст";
    }
    else
    {
        List *p = first;
        FILE *fp;
        if ((fp = fopen("Car.dat", "wb")) == NULL)
        {
            perror ("Ошибка");
            exit(0);
        }
        rewind (fp);

        while (!feof(fp) && p!=NULL)
        {
            fwrite(&p, sizeof(*p), 1, fp);
            p = p-> next;
        }
        fclose(fp);
    }
}

List* make()
{
    List *first, *p;
    first = NULL;
    p = new List;    

    p -> data.CarName = "Mazda";
    p -> data.SerialNumber = "1234";
    p -> data.RegestrationNumber = "Q111QQ";
    p -> data.Year = "2009";
    p -> next = NULL;
    first = p;

    List *h = new List;
    p -> next = h;
    p = p-> next;
    p -> data.CarName = "Nissan";
    p -> data.SerialNumber = "111";
    p -> data.RegestrationNumber = "K444KK";
    p -> data.Year = "2002";
    p -> next = NULL;
    first = p;

    List *u = new List;
    p -> next = u;
    p = p-> next;
    p -> data.CarName = "Peugeot";
    p -> data.SerialNumber = "322";
    p -> data.RegestrationNumber = "A777MP";
    p -> data.Year = "2020";
    p -> next = NULL;
    first = p;

    List *i = new List;
    p -> next = i;
    p = p -> next;
    p -> data.CarName = "VAZ";
    p -> data.SerialNumber = "009";
    p -> data.RegestrationNumber = "A123CC";
    p -> data.Year = "1998";
    p -> next = NULL;
    return first;
}

void add (List *&first, int count)
{
    if (first == NULL)
    {
        cout << "Список пустой";
    }
    else
    {
        string number;
        cout << "Введите номер авто, после которого добавится нвоый элемент: ";
        cin >> number;
        List *p = first;
        int k=0;
        while (p -> next != NULL)
    {
        p = p-> next;
        k++;
    }
    p = first;
    for (int i = 1; i<k; i++)
    {
        p = p -> next;
    }
        if ( p-> data.RegestrationNumber == number)
        {
        List *h = new List;
        List *u = p;
        p -> next = h;
        p = p -> next;
        cout << "Введите марку авто: " << endl;
        cin >> p -> data.CarName;
        cout << endl;
        cout << "Введите серийный номер авто: "<< endl;
        cin >> p -> data.SerialNumber;
        cout << endl;
        cout << "Введите регистрационный номер авто: " << endl;
        cin >> p-> data.RegestrationNumber;
        cout << endl;
        cout << "Введите год производства авто: " << endl;
        cin >> p -> data.Year;
        cout << endl;
        p -> next = NULL;
        }
    }
}

void del (List *&first)
{
    if (first == NULL)
    {
        cout << "Список пуст";
    }
    else
    {
        List *p = first;
        cout << "Введите кол-во элементов для удаления";
        int k = 0;
        cin >> k;
        for (int i=1; i<=k; i++)
        {
            first = p ->next;
            delete[]p;
            p -> next = first;
        }
    }
}

void print (List *first)
{
    if (first == NULL)
    {
        cout << "Списко пуст";
    }
    else 
    {
        List *p =first;
        while (p != NULL)
        {
            cout << "Марка авто: " << p -> data.CarName << endl;
            cout << "Серийный номер авто: " << p -> data.SerialNumber << endl << endl;
            cout << "Регистрационный номер авто: " << p -> data.RegestrationNumber << endl << endl;
            cout << "Год производства авто: " << p -> data.Year << endl << endl;
            p = p-> next;
        }    
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    List *list = make();
    NewFile(list);

    List *list_file = ReadFile();
    print(list_file);

    print(list);
    cout << endl;
    del(list);
    print(list);
    add(list, 1);
    print(list);
    NewFile(list);



    return 0;

}
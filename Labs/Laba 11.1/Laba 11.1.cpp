#include <iostream> //DONE!
using namespace std;

struct List{ 
    char data;
    List* next;
};

List* make_char()
{
    List* first, *p;
    first = NULL;
    p = new List;
    p->data = 'a' + rand() %25;
    p-> next = NULL;
    first = p;

    for (int i = 1; i<5; i++)
    {
        List* h = new List;
        p->next = h;
        p = p->next;
        p->data = 'a' + rand() %25;
        p->next = NULL;
    }
     return first;
}

void print(List* first)
{
    if( first == NULL)
    {
        cout << "Список пуст";
    }
    List* p= first;
    while (p!=NULL)
    {
        cout << p->data << endl;
        p=p->next;
    }
    cout << endl;
}


void add(List* &first)
{
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
    }
    cout << "Введите элемент, после которого будет произведено добавление элеменат в список:  ";
    char a[2];
    cin >> a[0];
    cout << "Введите элемент для добавления:  ";
    cin >> a[1];
    List* p = first;
    while (p != NULL)
    {
        if ( p->data == a[0])
        {            
            List* h = new List;
            h->data = a[1];
            h->next = p->next;
            p->next = h;
            p= p->next->next;   
        }
        else
        {
            p=p->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List* list= make_char();
    print (list);
    add (list);
    print (list);
    return 0;
}





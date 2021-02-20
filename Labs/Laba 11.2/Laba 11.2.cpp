#include <iostream> 
using namespace std;

struct List{ 
    int data;
    List* next;
    List* prev;
};

List* make_int()
{
    List* first, *p;
    first = NULL;
    p = new List;
    p->data = rand() %100;
    p-> prev = NULL;
    p-> next =NULL;
    first = p;

    for (int i = 1; i<5; i++)
    {
        List* h = new List;
        List* q = p;
        p->next = h;
        p = p->next;
        p->data = rand() %100;
        p->next = NULL;
        p->prev = q;
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


void del(List* first) //Доделать эту функцию
{
    cout << "Происходит удаление всех элементов с четным значением" << endl;
    if (first == NULL)
    {
        cout << "Список пуст" << endl;
    }
    List* p = first;
    List* q = NULL;
    while (p != NULL)
    {
        if ( p->next-> data %2 == 0)
        {                
            q->data=p->data;
            p->prev = q;
            
        }
        else{
            p= p->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    List* list= make_int();
    print (list);
    cout << endl;
    del (list);
    print (list);
    return 0;
}





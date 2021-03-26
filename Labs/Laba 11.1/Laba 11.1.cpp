#include <iostream> 
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
        cout << "List is empty";
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
        cout << "List is empty" << endl;
    }
    cout << "Enter the item after which the item will be added to the list:  ";
    char a[2];
    cin >> a[0];
    cout << "Enter elemenr for add:  ";
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
    cout << "New List:" << endl;
    List* list= make_char();
    print (list);
    add (list);
    print (list);
    return 0;
}





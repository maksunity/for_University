#include <iostream>
using namespace std;

struct List{
    char data;
    List* next;
};

void add(List **top, char a){
    List *p;
    p= new List();
    cout << "Print element: " << endl;
    cin >> a;
    p->data = a;
    if (top == NULL)
    {
        *top = p;
    }
    else
    {
        p->next = *top;
        *top = p;
    }
}

void print(List *top){
    List *p = top;
    while(p)
    {
        cout << p->data << endl;
    }
}


int main(){

    List* list = add();




}


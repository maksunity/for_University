#include <iostream>
using namespace std;

struct List{
    char data;
    List* prev;
};

char a;

List* make_List(int n){
List* top, *p;
top = NULL;
p = new List; 
cout << "Enter 1st element: " << endl;
cin >> a;
p->data = a;
p->prev = NULL;
top = p;
for (int i = 2; i <= n; i++)
{
    List *h = new List;
    cout << "Enter " << i << " element" << endl;
    cin >> a;
    h->data = a;
    h->prev = top;
    top = h;
}
return top;
}

void add(List* &first, char a){
    char n;
    List *p = first;
    cout << "After element?: " << endl;
    cin >> n;
    while (p->prev != NULL)
    {
    
        List* h = new List; // доделать эту функцию
        cout << "Enter element for add: " << endl;
        cin >> h->data;
        h->prev = p->prev;
        p->prev = h;
        p = p->prev;
    }
}

void print(List *top){
    List *p = top;
    while(p !=NULL)
    {
        cout << p->data << endl;
        p = p->prev;
    }
    cout << endl;
}


int main(){
    cout << "Enter quantity of element: " << endl;
    int n;
    cin >> n;
    cout << endl;
    List* l = make_List(n);
    cout << "Stack: " << endl;; print(l);
    add(l,n);
    cout << "Stack after add: " << endl;;
    print(l);
    return 0;




}


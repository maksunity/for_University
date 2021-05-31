#include <iostream>

using namespace std;
int a;
class stack
{
public:
    int data;
    stack *prev;
};

stack *make_stack(int n)
{
    if (n == 0)
    {
        return NULL;
    }
    stack *top, *p;
    top = NULL;
    p = new stack;
    cout << "Enter first element: ";
    cin >> a;
    p->data = a;
    p->prev = NULL;
    top = p;
    for (int i = 2; i <= n; i++)
    {
        stack *h = new stack;
        cout << "Enter " << i << " element: ";
        cin >> a;
        h->data = a;
        h->prev = top;
        top = h;
    }
    return top;
}

void add(stack *&first, int n)
{
    stack *p = first;
    stack *h = new stack;
    cout << "Enter new first element: ";
    cin >> h->data;
    h->prev = p;
    first = h;
    while (p->prev != NULL)
    {
        stack *h = new stack;
        cout << "Enter element to add: ";
        cin >> h->data;
        h->prev = p->prev;
        p->prev = h;
        if (p->prev->prev != NULL)
        {
            p = p->prev->prev;
        }
        else
        {
            p = p->prev;
        }
    }
}

void print(stack *top)
{
    if (top == NULL)
    {
        cout << "Error!" << endl;
    }
    else
    {
        stack *p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }
}

int main()
{
    cout << "Enter size: ";
    int n;
    cin >> n;
    stack *st = make_stack(n);
    cout << "Stack: ";
    print(st);
    add(st, n);
    cout << endl;
    cout << "After: ";
    print(st);
    return 0;
}
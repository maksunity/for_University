#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

struct List{
    string name;
    string birth;
    string phone;
    string pass;
    List* next;
};

void read(const int s, List* st){
    string a = "F1.txt";
    ifstream fn;
    fn.open(a, ios::in);
    if (!fn.is_open()){
        cout << "File dosen't open";
    }
    else{
        cout << "file is open" << endl;
        for (int i = 0; i < s; i++)
        {
            getline(fn, st[i].name);
            getline (fn, st[i].birth);
            getline(fn, st[i].phone);
            getline(fn , st[i].pass);
        }
    }
}

void print (const int s, List* st){
    for(int i = 0; i < s; i++)
    {
        cout << "Name: " << st[i].name << endl;
        cout << "Birthday : " << st[i].birth << endl;
        cout << "Phone number: " << st[i].phone << endl;
        cout << "Passport number: " << st[i].pass << endl;
        cout << "||||||||||||||||||||||||||||||||||||" << endl;
    }
}

int Hash_func(string key, int k)
{
   return (k%10);
}

void Hash(List* st, int s, List* table){
    for (int i = 0; i<s; i++)
    {
        table[i].phone = "0";
    }
    int c = 0;
    double A = 0.00001;
    for (int i = 0; i < s; i++)
    {
        int id = Hash_func(st[i].phone, s);
        if (table[id].phone == "0")
        {
            table[id].name = st[i].name;
            table[id].birth = st[i].birth;
            table[id].phone = st[i].phone;
            table[id].pass = st[i].pass;
            table[id].next = NULL;
        }
        else{
            c++;
            List* h = new List;
            List* p = &table[id];
            while (p->next != NULL)
            {
                p=p->next;
            }
            h->name = st[i].name;
            h->birth = st[i].birth;
            h->phone = st[i].phone;
            h->pass = st[i].pass;
            p->next = h;
            h->next = NULL;
        }
    }
    cout << "Kolvo kolizie: " << c << endl;
}

void Find(int s, List* table){
    string key;
    cout << "Enter phone for search: " << endl;
    cin.get();
    getline(cin, key);
    double A = 0.00001;
    int id = Hash_func(key, s);
    cout << "Find person: " << id << endl;
    if (table[id].phone == key)
    {
        cout << "Name: " << table[id].name << endl;
        cout << "Birthday : " << table[id].birth << endl;
        cout << "Phone number: " << table[id].phone << endl;
        cout << "Passport number: " << table[id].pass << endl;
    }
    else if (table[id].phone != key && table[id].next !=NULL)
    {
        List* p = table[id].next;
        bool flag = true;
        while (p != NULL && flag)
        {
            if (p->phone == key)
            {
                cout << "Name: " << p->name << endl;
                cout << "Birthday : " << p->birth << endl;
                cout << "Phone number: " << p->phone << endl;
                cout << "Passport number: " << p->pass << endl;
                flag = false;
            }
            p = p->next;
        }
    }
    else{
        cout << "Error Element" << endl;
    }
}


int main(){
    int s = 10;
    List* st = new List[s];
    List* table = new List[s];
    read(s, st);
    print (s, st);
    Hash (st, s,table);
    Find (s, table);
    return 0;
}
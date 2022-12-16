#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;
 int n;
struct ID{
	string data;
	string fnp;
	string number;
};
	int size=100;
	ID* arr = new ID[size];
void create(){
	string a;
	ifstream str("struct.txt");
    for(int i=0; i<size; i++){
        if(str.is_open()){
            if(getline(str, a)){
                arr[i].data = a;
            }
            if(getline(str, a)){
                arr[i].fnp = a;
            }
            if(getline(str, a)){
                arr[i].number = a;
            }
        }    
    }
    str.close();
}
void linear_search(){
	string a;
	int i;
	int n=-1;
	cout<<"Enter key:";
	getline(cin,a);
	getline(cin,a);
	for(int i=0;i<size; i++){
		if(arr[i].data ==a){
			n=i;
		}
	}
	if(n!=-1){
		cout<<"Element poition is:"<<n+1<<endl;
		cout<<"This element:"<<endl;
		cout << "|" << arr[i].data <<"|"<<endl;
        cout << "|"<< arr[i].fnp<< "|"<<endl;
	    cout <<"|"<< arr[i].number << "|"<<endl;
	}else{
		cout<<"Error, no elements with this key"<<endl;
	}
}
void substr_search(){
    string substr;
    cout << "Enter the substring: ";
    getline(cin,substr);
    getline(cin,substr);
    string str;
    bool x=true, n=true;
    for(int i=0; i<size; i++){
        str=arr[i].data;
        for(int j=0; j<str.size(); j++){
            x=true;
            for(int k=0; k<substr.size();k++){
                if(substr[k]!=str[j+k]){
                    x=false;
                }
            }
            if(x==true){
                cout << "Element number: " << i+1 << endl;
                cout << "This element: " << endl;
                cout << "    " << arr[i].data<< endl;
                cout << "    " << arr[i].fnp<< endl;
                cout << "    " << arr[i].number<< endl;
                n=false;
            }
        }
    }
    if(n=false){
        cout << "There is no element with this key" << endl;
    }
}

/*void interpolsearch(ID arr[], int key) {
	string num;
	int int_num, buf, change, key, mid;
	for (int i = 0; i < size; i++)
	{
		int_num = stoi (arr[i].data);
		buf = stoi(arr[i+1].data);
		if (buf < int_num)
		{
			change = int_num;
			int_num = buf;
			buf = change;
		}
	}
	cout << "Enter key: " << endl;
	cin >> key;
	for (int i = 1; i <= size; i++)
	{
		mid = 
	}
}
	*/


void print(){
    cout << "Your struct: " << endl;
    for(int i=0; i<size;i++){
        cout << "Your " << i+1 << " person: " << endl;
        cout << "|" << arr[i].data<<"|"<<endl;
        cout << "|"<< arr[i].fnp<< "|"<<endl;
        cout <<"|"<< arr[i].number << "|"<<endl;
    }
}
void save(){
	string a;
	ofstream str;
    ifstream gg("struct.txt");
	str.open("save_struct.txt");
	for(int i=0;i<size;i++){
        if(getline(gg,a)){
		str<<"|"<<arr[i].data<<"|"<<arr[i].fnp<<"|"<<arr[i].number<<"|"<<endl;
        }
	}
	str.close();
}
int main(){
	cout<<"1 - Show data."<<endl;
	cout<<"2 - Choice search."<<endl;
	cout<<"3 - Clear console."<<endl;
	cout<<"4 - Save in .txt format."<<endl;
	cout<<"5 - Exit."<<endl;
	int choice;
	while(choice!=5){
		cout<<"Choice is:";
		cin>>choice;
		switch(choice){
			case 1:
				create();	
				print();
				break;
			case 2:
				cout<<"Choice search method:"<<endl;
				cout<<"1 - Lenear search"<<endl;
				cout<<"2 - Method of straight search of substring in a string"<<endl;
				cout<<"3 - Interpolation search"<<endl;
				int choice2;
				cout<<"Choice is:"<<endl;
				cin>>choice2;
				switch(choice2){
					case 1://linear search
						linear_search();
						break;
					case 2://Str in str
                        substr_search();
						break;
					case 3://interpolsearch();
						break;
					default:
						cout<<"Illegial choice."<<endl;
				}
				break;
			case 3:
				system("cls");
				break;
			case 4:
				save();
				break;
			case 5:
                cout<<"*Have a good day*"<<endl;
                break;
            default:
				cout<<"Illegial choice."<<endl;
		}
	}
	system("pause");
	return 0;
}

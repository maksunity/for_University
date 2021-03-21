#include <iostream>
#include <string>
#include <cstdlib>
#include <locale.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;
 int n;
 string key;
 string line;

struct ID{
	string data;
	string fnp;
	long long number;
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

ID* users;

void KMP_search(List* ID, string key, string line)
{
	int lenline = line.size();
	int lenkey = key.size();

	int* array = new int[lenkey];
	array[0] = 0;
	int i = 1;
	int j = 0;
	for (int v = 0; v < lenkey; v++)
	{
		if (key[i] == key[j])
		{
			array[i] = j + 1; i++; j++;
		}
		else if (j == 0)
		{
			array[i] = 0;
			i++;
		}
		else
		{
			j = array[j - 1];
		}
	}
	cout << "Префикс функция:";
	for (int i = 0; i < lenkey; i++)
	{
		cout << " " << array[i];
	}
	cout << endl;
	int index_line = 0;
	int index_key = 0;
	int o = 0;
	while (index_line < lenline)
	{
		if (line[index_line] == key[index_key])
		{
			index_line++;
			index_key++;
			if (index_key == lenkey)
			{
				string tmp;
				tmp = tmp + line[index_line];
				int i = 1;

				while (index_line < lenline && (line[index_line + 1] != ' ')) {
					tmp = tmp + line[index_line + i];
					index_line++;
				}
				
				cout << "Пользователь найден. Он находится под номером: " << stoi(tmp);
			}
		}

		if (line[index_line] != key[index_key])
		{
			if (index_key == 0)
			{
				index_line++;
			}
			else
			{
				index_key = array[index_key - 1];
			}
		}
	}
}




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
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int main(){
		ifstream inf;
		inf.open("f1.txt");
		string inp; 
		string word;
		int check;
		ofstream outf;
		outf.open("f2.txt");

		for (getline(inf, inp); !inf.eof(); getline(inf, inp)){
			cout<<inp<<endl;
			check = 0;
			stringstream ss(inp);
			while(ss >> word)
			{
				cout << "word: " << word << endl;
				if (word == "hello")
				{
					check++;
				}
			}
			if (check > 0)
			{
				cout << "found string " << inp << endl;
				outf << inp << endl;
			}
			else
			{
				cout << "No strings found" << endl;
			}
			}
			outf.close();
		return 0;
		}	


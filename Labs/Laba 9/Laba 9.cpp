#include <iostream> //доделать
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int count (string str)
{
	int k=0;
	for (auto c :str)
	{
		switch (c)
			{
				case 'q':
				case 'Q':
				case 'w':
				case 'W':
				case 'r':
				case 'R':
				case 't':
				case 'T':
				case 'p':
				case 'P':
				case 's':
				case 'S':
				case 'd':
				case 'D':
				case 'f':
				case 'F':
				case 'g':
				case 'G':
				case 'h':
				case 'H':
				case 'j':
				case 'J':
				case 'k':
				case 'K':
				case 'l':
				case 'L':
				case 'z':
				case 'Z':
				case 'x':
				case 'X':
				case 'c':
				case 'C':
				case 'v':
				case 'V':
				case 'b':
				case 'B':
				case 'n':
				case 'N':
				case 'm':
				case 'M':
				k++;
			}
		}
		return k;
}
int main(){	
		ifstream inf;
		inf.open("f1.txt");
		string inp; 
		string str;
		string word;
		int check;
		ofstream outf;
		outf.open("f2.txt");
		ifstream f1;

		for (getline(inf, inp); !inf.eof(); getline(inf, inp)){
			cout<<inp<<endl;
			check = 0;
			string z;
			getline(f1, z);
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

	 	ifstream f2;
		 int n;
		 cout << "Kolvo strok: " << endl;
		 cin >> n;
		 for(int i=0; i<n; i++)
		 {
			 getline(f2, str);
		 }
			
		 cout << "Кол-во согласных букв в последней строке: " << count(str);

		return 0;
		}	


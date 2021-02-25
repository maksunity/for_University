#include <iostream> //доделать,.,..
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int main(){
	string z, firstword, word;
	inf.open("f1.txt");

	for (getline(z,word); !in.eof(); getline(z. word))
	{
		
	}
	
	{
		stringstream ss(z);
		bool flag = false;
		ss >> firstword;
		while (ss>>word)
		{
			if (word == firstword)
			{
				ofstream out("f2.txt");
				cin.getline(in, ss);
			}

		}
		
	}

		
		
		
		
		/**ifstream inf;
		inf.open("f1.txt");
		string inp; 
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
				if (word == z)
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
**/

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;
int main(){	
		int count = 0;
		int stroka = 0;
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
				stroka++;
			}
			else
			{
				cout << "No strings found" << endl;
			}
			}
			cout << stroka << endl;
			outf.close();
           
		string a = "qQwWrRtTpPsSdDfFgGhHjJkKlLzZxXcCvVbBnNmM";
        int cs;
        ifstream sec("f2.txt");
        if(sec.is_open()){
                while(getline(sec,str,'y')){
                }
                cout<<str;
                for(int i=0;i<=str.length();i++){
                    for(int zz=0;zz<=a.length();zz++){
                    if(str[i]==a[zz]){
                        cs++;
                }
            }
        }
    }
        cout<<cs-1;
        sec.close();
		cout << "Programm done!"; 
		return 0;
		}	

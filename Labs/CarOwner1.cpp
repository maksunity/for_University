#include <iostream>
#include <string>
using namespace std;

struct CarOwner{
    string SNP;
    string CarNumber;
    string PhoneNumber; 
    string TechPassNumber;
};
int main()
    {
    int amount=10;
    CarOwner person[amount];
    //////////////////////////////////////////////////////////////////
    person[0].SNP="Andreas Nikolaus Lauda";  
    person[0].CarNumber="022";
    person[0].PhoneNumber="81043112345";
    person[0].TechPassNumber="Ferrari 312T";

    person[1].SNP="Lewis Carl Davidson Hamilton";   
    person[1].CarNumber="44";
    person[1].PhoneNumber="447441428091";
    person[1].TechPassNumber="Mercedes M11 EQ Performance 1,6 V6T";

    person[2].SNP="Michael Schumacher";
    person[2].CarNumber="1";
    person[2].PhoneNumber="447332128091";
    person[2].TechPassNumber="Mercedes FO 108X 2,4 V8";

    person[3].SNP="Fernando Alonso Diaz"; 
    person[3].CarNumber="314";
    person[3].PhoneNumber="032804982304";
    person[3].TechPassNumber="Renault R.E.18 1,6 V6T";
    //print
    unsigned short int calc=0;
    unsigned short int count=1;
    for(int i=0;i<amount;i++){
        if(person[i].SNP==""){
            continue;}
        calc++;
        cout<<i+1<<". "<<person[i].SNP<<endl;
        cout<<"   "<<person[i].CarNumber<<endl;
        cout<<"   "<<person[i].PhoneNumber<<endl;
        cout<<"   "<<person[i].TechPassNumber<<endl;
    }
    //delete pos
    unsigned short int choice;
    cout<<"Choice position: ";
    cin>>choice;
    string k = person[choice].SNP;
    if(choice>calc || choice<0){
        cout<<"Error:"<<endl;}
    else{person[choice-1].SNP="";}
    //print new
    for(int i=0;i<calc;i++){
        if(person[i].SNP==""){
            continue;}
        cout<<count<<". "<<person[i].SNP<<endl;
        cout<<"   "<<person[i].CarNumber<<endl;
        cout<<"   "<<person[i].PhoneNumber<<endl;
        cout<<"   "<<person[i].TechPassNumber<<endl;
        count++;
    }
    //choiceSNP
    string choiceSNP;
    cout<<"Find people: "<<endl;
    getline(cin,choiceSNP);
    int i=calc-1;
    do{
        if(person[i].SNP==""){
            continue;}
        person[i+2].SNP=person[i].SNP;
        person[i+2].CarNumber=person[i].CarNumber;
        person[i+2].PhoneNumber=person[i].PhoneNumber;
        person[i+2].TechPassNumber=person[i].TechPassNumber;
        i--;}while(person[i].SNP!=choiceSNP);
    getline(cin,person[i].SNP);
    getline(cin,person[i].SNP);
    getline(cin,person[i].CarNumber);
    getline(cin,person[i].PhoneNumber);
    getline(cin,person[i].TechPassNumber);
    getline(cin,person[i+1].SNP);
    getline(cin,person[i+1].CarNumber);
    getline(cin,person[i+1].PhoneNumber);
    getline(cin,person[i+1].TechPassNumber);
    count=1;
    for(int i=0;i<calc+2;i++){
        if(person[i].SNP==""){
            continue;}
        cout<<count<<". "<<person[i].SNP<<endl;
        cout<<"   "<<person[i].CarNumber<<endl;
        cout<<"   "<<person[i].PhoneNumber<<endl;
        cout<<"   "<<person[i].TechPassNumber<<endl;
        count++;
    }








    return 0;
}














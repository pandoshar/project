#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void cat(string name);
string Ceasar(int key, string str);
string Vigenere(string dau, string sec);
string reverseVigenere(string dau, string sec);
string reverseCeasar(int key, string str);
char arr[26][26];
int main(){
    int big = 65;
    int smal = 0;
    for(int i =0;i<26;i++){
        arr[i][0]= (char)big;
        smal = big+1;
        for(int a = 1;a<26;a++){
            if(smal>90){
                smal-=26;
            }
            arr[i][a] = (char)smal;
            smal++;
        }
        big++;
    }
    string ui;
    string ou, au;
    int jk;
    cat("Adilet");
    cout<<"What do you want c for Ceasar enc and v for Vigenyer or if you want to decrypt you can use rc for Ceasar and rv for Vigenyer ";
    cin>>ui;
    if(ui=="c"){
        cout<<"type a num key ";
        cin>>jk;
        cout<<"type a word ";
        cin>>au;
        cout<<Ceasar(jk, au);
    }
    if(ui=="v"){
        cout<<"type a key ";
        cin>>ou;
        cout<<"type a word ";
        cin>>au;
        cout<<Vigenere(ou, au);
        
    }
    if(ui=="rc"){
        cout<<"type a num key ";
        cin>>jk;
        cout<<"type a word ";
        cin>>au;
        cout<<reverseCeasar(jk, au);
    }
    if(ui=="rv"){
        cout<<"type a key ";
        cin>>ou;
        cout<<"type a word ";
        cin>>au;
        cout<<reverseVigenere(ou, au);
        
    }
    
    
}

void cat(string name){//приветствие
    cout<<" ____________"<<endl;
    cout<<"(Hello " + name +")"<<endl;
    cout<<" ------------"<<endl;
    cout<<"          /'"<<endl;
    cout<<" (^o w o^)";
    cout<<"WELCOME TO ECRYPTOR/DECRYPTORE"<<endl;
}

string Ceasar(int key, string str){//для вызова шифра цезаря
    for(int d = 0;d<str.length();d++){
        if((int)str[d]<90 or (int)str[d]>96 and (int)str[d]<123){
            str[d] += key;
        }
        else{
            str[d] -= 25;
        }
    }
    return str;
}

string reverseCeasar(int key, string str){//дешифратор цезаря
    for(int d = 0;d<str.length();d++){
        if((int)str[d]>64 and (int)str[d]<91 or (int)str[d]>96){
            str[d] -= key;
        }
        else{
            str[d] += 25;
        }
    }
    return str;
}

string Vigenere(string dau, string sec){//шифр вигенера
    string ado = "";
    int her,der;
    int len = dau.length();
    int aldo = 0;
    for(int c = 0;c<sec.length();c++){
        her = toupper(dau[aldo])-65;
        der = toupper(sec[c])-65;
        ado += arr[her][der];
        
        aldo++;
        if(aldo==len){
            aldo -= len;
        }
    }
    return ado;
}

string reverseVigenere(string dau, string sec){//дешифратор вигенера
    string ado = "";
    int her;
    int len = dau.length();
    int aldo = 0;
    for(int c = 0;c<sec.length();c++){
        her = 
        dau[aldo]-65;
        for(int j = 1;j<26;j++){
            char der = arr[her][j];
            if(der==sec[c]){
                ado += arr[0][j];
            }
        }
        
        aldo++;
        if(aldo==len){
            aldo -= len;
        }
    }
    return ado;
}
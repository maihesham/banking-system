#include "account.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include<cmath>
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
account::account(){siz=64;num=0;}
void account::create_accout(){//take info from customer and determin offest of record in file using rrn
    customer i;
    string name,balance;
    string type,number;
    cout<<"enter your account number ";//must be unique
    cin>>i.account_number;
    cout<<endl;
    cout<<"enter your name :- ";
    cin>>i.name;
    cout<<endl;
    cout<<"enter type of account (c/s): -";
    cin>>i.type_of_account;
    cout<<endl;
    cout<<"enter your balance :- ";
    cin>>i.deposit;
    string h="0";
    strcpy(i.withdraw,h.c_str());
    write_in_file(i);
}

void account::write_in_file(customer i){//write in file and determine offest of this record and return it
    fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    f.seekg(num*siz,ios::beg);
    f.write((char*)&i,sizeof(i));
    f.close();
    num++;

}
void account::show(){//list all accounts in files
    fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    cout<<"=======================================================\n";
	cout<<"A/c         no.      NAME        Type           Balance\n";
	cout<<"=======================================================\n";
    for(int y=0;y<num;y++){
        customer i;
        f.seekg(y*siz,ios::beg);
        f.read((char*)&i,sizeof(i));
        string number(i.account_number);
        for(int i=number.size()-1;i>=0;i--){if(number[i]==' '){number.erase(i--,1);}else{break;}}
        if(number=="-1"){continue ;}
        cout<<y+1<<"            "<<i.account_number<<"        "<<i.name;
        cout<<"        "<<i.type_of_account<<"            "<<i.deposit<<endl;
    }
     f.close();

}
///////////////////////////////////////////////////////////////////////////////////////////////////
bool account::delete_record(){//delete record from vector not from file
    int n;
    cout<<"enter your account number "<<endl;
    cin>>n;
    customer i;
    int z=make_offest(n);
    if(z==-1){return 0;}
    else{

        fstream f;
       f.open("info_about_customer.txt",ios::in|ios::out);
       f.seekg(z,ios::beg);
       f.read((char*)&i,sizeof(i));
       string number(i.account_number);
     for(int i=number.size()-1;i>=0;i--){if(number[i]==' '){number.erase(i--,1);}else{break;}}
     if(number=="-1"){
        cout<<"sorry not found "<<endl;
     }else{
         string newnum="-1";
         strcpy(i.account_number,newnum.c_str());
         f.seekg(z,ios::beg);
         f.write((char*)&i,sizeof(i));
         cout<<"done , is deleted now "<<endl;
     }
    }

}
void account::show_state(int i){//show account
    int offest=make_offest(i);
    if(offest==-1){cout<<"not found try again "<<endl;}
    else{
    fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    customer w;
    f.seekg(offest,ios::beg);
    f.read((char*)&w,sizeof(w));
    cout<<"------------- account state--------------------"<<endl;
    cout<<"              account number :-  "<<w.account_number<<endl;
    cout<<"              your money :-   "<<w.deposit<<endl;
    cout<<"               your name :-  "<<w.name<<endl;
    f.close();
    }

}
void account::WITHDRAW_AMOUNT(){//to withdraw from account
    cout<<"enter your account number"<<endl;
    int n;
    cin>>n;
    int offet=make_offest(n);
    if(offet==-1){cout<<"not found "<<endl;}
    else{
    customer i;
     fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    f.seekg(offet,ios::beg);
    f.read((char*)&i,sizeof(i));
    string h(i.account_number);
    if(h!="-1"){
      cout<<"enter the amount of withdraw"<<endl;
       int d;
      cin>>d;
      string dep(i.deposit);
      int deposti=atoll(dep.c_str());
      if(deposti==d ||deposti>d){
        cout<<"you account now are "<<deposti-d<<endl;
        int newdeposit=deposti-d;
        string new_deposit;
       ostringstream convert;
       convert << newdeposit;
       new_deposit = convert.str();
      strcpy(i.deposit,new_deposit.c_str());
      int z=make_offest(n);
    if(z!=-1){
      f.seekg(z,ios::beg);
      f.write((char*)&i,sizeof(i));
    }
      f.close();
    }else{cout<<"cant take this amount "<<endl;}

 }
}
}
void account::DEPOSIT_AMOUNT(){//to deposit
    cout<<"enter your account number"<<endl;
    int n;
    cin>>n;
    customer i;
    string nu;
    ostringstream convert;
    convert << n ;
    nu = convert.str();
    fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    bool b=0;
    for(int y=0;y<num;y++){
        f.seekg(y*siz,ios::beg);
        f.read((char*)&i,sizeof(i));
        string number(i.account_number);
        for(int i=number.size()-1;i>=0;i--){if(number[i]==' '){number.erase(i--,1);}else{break;}}
        if(number=="-1"){continue ;}
        if(number==nu){
            b=1;
            break;
        }

    }

    if(b==0){
        cout<<"sorry not found "<<endl;
        f.close();
    }else{
      string h(i.account_number);
      if(h!="-1"){
        cout<<"enter the amount of deposit"<<endl;
        int d;
        cin>>d;
        string dep(i.deposit);
        int deposita=atoll(dep.c_str());
       cout<<"you account now are "<<d+deposita<<endl;
       int newdeposti=d+deposita;
       cout<<"new      ---      "<<newdeposti<<endl;
        string new_deposti;
       ostringstream convert;
       convert << newdeposti ;
       new_deposti = convert.str();
       strcpy(i.deposit,new_deposti.c_str());
      int z=make_offest(n);
      cout<<"balance       "<<i.deposit<<endl;
    if(z!=-1){
      f.seekg(z,ios::beg);
      f.write((char*)&i,sizeof(i));
    }
      f.close();
}}

}

int account::make_offest(int n){//return offest to search about it
    string q;
    customer i;
    int z,d=0;
    ostringstream convert;
    convert << n;
    fstream f;
    f.open("info_about_customer.txt",ios::in|ios::out);
    q = convert.str();
     for(int y=0;y<num;y++){
        f.seekg(y*siz,ios::beg);
        f.read((char*)&i,sizeof(i));
        string number(i.account_number);
        for(int i=number.size()-1;i>=0;i--){if(number[i]==' '){number.erase(i--,1);}else{break;}}
        if(number=="-1"){continue ;}
        if(number==q){
            d=1;
            return y*siz;
            break;
        }
     }


    if(d==0){cout<<"not found try again "<<endl;return -1;}
}
void account::modefiy(){// to modify in account
    cout<<"enter your account number"<<endl;
    int n;
    cin>>n;
    int offest=make_offest(n);
    if(offest==-1){cout<<"sorry not found "<<endl;}
    else{
     fstream f;
      f.open("info_about_customer.txt",ios::in|ios::out);
      customer i;
      f.seekg(offest,ios::beg);
      f.read((char*)&i,sizeof(i));
      string h(i.account_number);
     if(h!="-1"){
      string name,type;
      cout<<"enter new "<<endl;
      cout<<"in name"<<endl;
      cin>>name;
      cout<<"in type"<<endl;
      cin>>type;
      strcpy(i.name,name.c_str());
      strcpy(i.type_of_account,type.c_str());
      cout<<i.account_number<<"."<<i.name<<"."<<i.type_of_account<<endl;
      f.seekg(offest,ios::beg);
      f.write((char*)&i,sizeof(i));
      f.close();}
     else{
        cout<<"sorry not found"<<endl;
     }
}
}

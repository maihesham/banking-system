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
#include "account.h"
#include <string>
using namespace std;
/*
banking system project can choose any thing from MAIN MENU and back to it after make the process ,
in the project I use fixed lengh (RRN) using ofset assum no dublicat no names or account number is the same
*/
int main()
{


    char x='-1';
    account i;
    while(x!='8'){
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>x;
		if(x=='1'){
            i.create_accout();
		}else if(x=='2'){
		    i.DEPOSIT_AMOUNT();
		}
		else if(x=='3'){
            i.WITHDRAW_AMOUNT();
		}else if(x=='4'){
		    int n;cout<<"please enter your account number "<<endl;
		    cin>>n;
		    i.show_state(n);

		}else if(x=='5'){
		    i.show();
		}else if(x=='6'){
		    i.delete_record();
		}else if(x=='7'){
		    i.modefiy();
		}else if(x=='8'){break;}
		else{cout<<"wrong try again"<<endl;}

    }
    cout<<"thank for used our app"<<endl;


    return 0;
}

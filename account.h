#ifndef ACCOUNT_H
#define ACCOUNT_H
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
struct customer{
    char  account_number[4];//4
    char  name[50];//50
    char deposit[4];//4
    char withdraw[4];//4
    char type_of_account[2];//2


};
class account
{
    public:
        account();
        void show();
        void create_accout();
        void write_in_file(customer i);
        void DEPOSIT_AMOUNT();
        void WITHDRAW_AMOUNT();
        void show_state(int i);
        bool delete_record();
        void modefiy();
        int make_offest(int n);
    protected:
    private:
        int siz;
        int num;
};

#endif // ACCOUNT_H

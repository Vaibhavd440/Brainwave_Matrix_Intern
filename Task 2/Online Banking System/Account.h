#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string accountHolderName;
    double balance;

    Account(int accNo, const string& name, double bal) 
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}
};

#endif // ACCOUNT_H

#ifndef ATM_H
#define ATM_H

#include <string>
using namespace std;

class ATM {
private:
    string userPIN;
    double balance;

public:
    ATM(string pin, double initialBalance);

    bool authenticate(string inputPIN);
    void checkBalance();
    void depositMoney();
    void withdrawMoney();
    void changePIN(); // Declaration of changePIN function
};

#endif

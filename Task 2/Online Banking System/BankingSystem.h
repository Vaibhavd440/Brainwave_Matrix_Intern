#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include "Account.h"
#include <vector>

class BankingSystem {
private:
    std::vector<Account> accounts;
    int nextAccountNumber;
    Account* findAccount(int accountNumber);

public:
    BankingSystem();
    void createAccount();
    void deposit();
    void withdraw();
    void transfer();
    void displayAccounts();
};

#endif // BANKINGSYSTEM_H

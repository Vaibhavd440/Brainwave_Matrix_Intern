#include "BankingSystem.h"
#include <iostream>
#include <iomanip>
using namespace std;

BankingSystem::BankingSystem() : nextAccountNumber(1001) {}

Account* BankingSystem::findAccount(int accountNumber) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            return &account;
        }
    }
    return nullptr;
}

void BankingSystem::createAccount() {
    string name;
    double initialDeposit;

    cout << "\nEnter Account Holder Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Initial Deposit Amount: ";
    cin >> initialDeposit;

    accounts.emplace_back(nextAccountNumber, name, initialDeposit);
    cout << "Account created successfully! Your account number is: " 
         << nextAccountNumber << endl;
    nextAccountNumber++;
}

void BankingSystem::deposit() {
    int accountNumber;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Amount to Deposit: ";
    cin >> amount;

    Account* account = findAccount(accountNumber);
    if (account) {
        account->balance += amount;
        cout << "Amount deposited successfully! Updated Balance: " 
             << fixed << setprecision(2) << account->balance << endl;
    } else {
        cout << "Account not found.\n";
    }
}

void BankingSystem::withdraw() {
    int accountNumber;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;
    cout << "Enter Amount to Withdraw: ";
    cin >> amount;

    Account* account = findAccount(accountNumber);
    if (account) {
        if (account->balance >= amount) {
            account->balance -= amount;
            cout << "Amount withdrawn successfully! Updated Balance: " 
                 << fixed << setprecision(2) << account->balance << endl;
        } else {
            cout << "Insufficient balance.\n";
        }
    } else {
        cout << "Account not found.\n";
    }
}

void BankingSystem::transfer() {
    int fromAccountNumber, toAccountNumber;
    double amount;

    cout << "\nEnter Your Account Number: ";
    cin >> fromAccountNumber;
    cout << "Enter Recipient Account Number: ";
    cin >> toAccountNumber;
    cout << "Enter Amount to Transfer: ";
    cin >> amount;

    Account* fromAccount = findAccount(fromAccountNumber);
    Account* toAccount = findAccount(toAccountNumber);

    if (fromAccount && toAccount) {
        if (fromAccount->balance >= amount) {
            fromAccount->balance -= amount;
            toAccount->balance += amount;
            cout << "Amount transferred successfully! Updated Balance in Your Account: " 
                 << fixed << setprecision(2) << fromAccount->balance << endl;
        } else {
            cout << "Insufficient balance for the transfer.\n";
        }
    } else {
        cout << "Invalid account number(s).\n";
    }
}

void BankingSystem::displayAccounts() {
    if (accounts.empty()) {
        cout << "\nNo accounts found.\n";
        return;
    }

    cout << "\nAccount List:\n";
    cout << left << setw(15) << "Account No" 
         << setw(25) << "Account Holder Name" 
         << setw(15) << "Balance" << endl;
    for (const auto& account : accounts) {
        cout << left << setw(15) << account.accountNumber 
             << setw(25) << account.accountHolderName 
             << setw(15) << fixed << setprecision(2) << account.balance << endl;
    }
}

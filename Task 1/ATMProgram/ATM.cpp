#include "ATM.h"
#include <iostream>
using namespace std;

ATM::ATM(string pin, double initialBalance) {
    userPIN = pin;
    balance = initialBalance;
}

bool ATM::authenticate(string inputPIN) {
    return inputPIN == userPIN;
}

void ATM::checkBalance() {
    cout << "\nYour current balance is: Rs. " << balance << endl;
}

void ATM::depositMoney() {
    double amount;
    cout << "\nEnter amount to deposit: Rs. ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Rs. " << amount << " deposited successfully!" << endl;
    } else {
        cout << "Invalid amount entered!" << endl;
    }
}

void ATM::withdrawMoney() {
    double amount;
    cout << "\nEnter amount to withdraw (only multiples of Rs. 200 or Rs. 500 are allowed): Rs. ";
    cin >> amount;

    if (amount > balance) {
        cout << "Insufficient balance!" << endl;
    } else if (static_cast<int>(amount) % 200 != 0 && static_cast<int>(amount) % 500 != 0) {
        cout << "Invalid denomination! Withdrawals must be in multiples of Rs. 200 or Rs. 500.\n";
    } else {
        balance -= amount;
        cout << "Rs. " << amount << " withdrawn successfully!" << endl;
    }
}

void ATM::changePIN() {
    string oldPIN, newPIN, confirmPIN;

    cout << "\nEnter your current PIN: ";
    cin >> oldPIN;

    if (authenticate(oldPIN)) {
        cout << "Enter new PIN: ";
        cin >> newPIN;

        cout << "Confirm new PIN: ";
        cin >> confirmPIN;

        if (newPIN == confirmPIN) {
            userPIN = newPIN;
            cout << "PIN changed successfully!\n";
        } else {
            cout << "New PIN and confirmation PIN do not match. PIN change failed.\n";
        }
    } else {
        cout << "Incorrect current PIN. PIN change failed.\n";
    }
}

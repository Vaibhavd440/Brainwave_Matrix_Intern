#include <iostream>
#include "ATM.h"

using namespace std;

int main() {
    string userPIN = "1234";  // Default PIN
    double initialBalance = 5000.0;  // Default balance

    ATM atm(userPIN, initialBalance);
    string enteredPIN;
    int attempts = 3;

    cout << "Welcome to the ATM!\n";
    cout << "Note: Withdrawals must be in multiples of Rs 200 or Rs 500.\n";

    // Authentication
    while (attempts > 0) {
        cout << "Please enter your PIN: ";
        cin >> enteredPIN;

        if (atm.authenticate(enteredPIN)) {
            cout << "Authentication successful!\n";
            break;
        } else {
            attempts--;
            cout << "Incorrect PIN. Attempts remaining: " << attempts << endl;
        }
    }

    if (attempts == 0) {
        cout << "Too many failed attempts. Exiting...\n";
        return 0;
    }

    int choice;
    do {
        // Display menu
        cout << "\nATM Menu:\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Change PIN\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            atm.checkBalance();
            break;
        case 2:
            atm.depositMoney();
            break;
        case 3:
            atm.withdrawMoney();
            break;
        case 4:
            atm.changePIN();
            break;
        case 5:
            cout << "Thank you for using the ATM. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

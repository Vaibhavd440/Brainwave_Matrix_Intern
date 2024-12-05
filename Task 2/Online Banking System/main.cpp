#include "BankingSystem.h"
#include <iostream>
using namespace std;

int main() {
    BankingSystem bank;
    int choice;

    do {
        cout << "\n===== Online Banking System =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Transfer Money\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.transfer();
                break;
            case 5:
                bank.displayAccounts();
                break;
            case 6:
                cout << "Thank you for using the Online Banking System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

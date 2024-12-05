# Online Banking System (C++)

This is a simple online banking system built in C++ that allows users to create accounts, deposit and withdraw funds, and transfer money between accounts. The system is designed with modularity in mind, separating different functionalities into separate files for easy maintainability.

## Features

1. **Account Creation**: Allows the user to create an account with an initial deposit.
2. **Deposit**: Allows users to deposit money into an existing account.
3. **Withdraw**: Allows users to withdraw money from their account.
4. **Transfer**: Allows users to transfer money between accounts.
5. **Display Accounts**: Displays all accounts in the system with their balance.

### **Explanation of Files:**

- `Account.h`: Contains the `Account` structure that holds account details like account number, account holder name, and balance.
- `BankingSystem.h`: Declares the `BankingSystem` class that encapsulates all banking functionalities such as creating accounts, depositing money, withdrawing money, transferring money, and displaying account details.
- `BankingSystem.cpp`: Contains the implementation of all functions defined in the `BankingSystem` class.
- `main.cpp`: The main program file that provides the user interface and handles the user input and interaction with the banking system.

## Prerequisites

- A C++ compiler (e.g., GCC or Clang).
- A text editor or IDE (e.g., Visual Studio Code, CLion).

## Compilation and Execution

### Step 1: Save the files
Ensure that all the files (`main.cpp`, `BankingSystem.cpp`, `BankingSystem.h`, and `Account.h`) are saved in the same directory.

### Step 2: Compile the program
Use the following command to compile the program:

" g++ main.cpp BankingSystem.cpp -o BankingSystem "

Step 3: Run the program

" ./BankingSystem "




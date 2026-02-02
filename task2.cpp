#include <iostream>
#include <string>
using namespace std;

struct Account {
    int accountNumber;
    string holderName;
    double balance;
};

void displayAccount(const Account& acc) {
    cout << "\nAccount Information\n";
    cout << "Account Number: " << acc.accountNumber << endl;
    cout << "Account Holder: " << acc.holderName << endl;
    cout << "Current Balance: " << acc.balance << endl;
}

void deposit(Account& acc, double amount) {
    if (amount > 0) {
        acc.balance += amount;
        cout << "Deposit successful. New balance: " << acc.balance << endl;
    } else {
        cout << "Invalid deposit amount.\n";
    }
}

void withdraw(Account& acc, double amount) {
    if (amount > 0 && amount <= acc.balance) {
        acc.balance -= amount;
        cout << "Withdrawal successful. New balance: " << acc.balance << endl;
    } else {
        cout << "Invalid withdrawal amount or insufficient balance.\n";
    }
}

int main() {
    Account acc;

    cout << "Enter account number: ";
    cin >> acc.accountNumber;
    cin.ignore();
    cout << "Enter account holder name: ";
    getline(cin, acc.holderName);
    cout << "Enter initial balance: ";
    cin >> acc.balance;

    if (acc.balance < 0) {
        acc.balance = 0;
        cout << "Initial balance cannot be negative. Set to 0.\n";
    }

    int choice;
    double amount;

    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Info\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter deposit amount: ";
            cin >> amount;
            deposit(acc, amount);
        }
        else if (choice == 2) {
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            withdraw(acc, amount);
        }
        else if (choice == 3) {
            cout << "Current Balance: " << acc.balance << endl;
        }
        else if (choice == 4) {
            displayAccount(acc);
        }

    } while (choice != 0);

    cout << "\nFinal Account Status:";
    displayAccount(acc);

    return 0;
}

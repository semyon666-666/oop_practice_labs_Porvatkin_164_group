#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(string accNum, double initialBalance = 0)
        : accountNumber(accNum), balance(initialBalance) {}


    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }


    void setAccountNumber(const string& newNumber) {
        accountNumber = newNumber;
    }


    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }


    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayInfo() const {
        cout << "schet: " << accountNumber << endl;
        cout << "balance: " << balance << " rub." << endl;
    }
};

int main() {
    BankAccount acc("123456789", 1000);

    acc.displayInfo();
    cout << endl;

    acc.deposit(500);
    cout << "posle popolneniya: " << acc.getBalance() << " rub." << endl;

    if (acc.withdraw(300)) {
        cout << "uspeshno. balance: " << acc.getBalance() << " rub." << endl;
    }

    if (!acc.withdraw(2000)) {
        cout << "oshibka: nedostatochno sredstv!" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <string>


class BankAccount {
protected:
    std::string ownerName;
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& ownerName, const std::string& accountNumber, double balance)
        : ownerName(ownerName), accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) {
        if (isValidAmount(amount)) {
            balance += amount;
        } else {
            std::cerr << "Invalid deposit amount: " << amount << std::endl;
        }
    }

    virtual bool withdraw(double amount) {
        if (!isValidAmount(amount)) {
            std::cerr << "Invalid withdrawal amount: " << amount << std::endl;
            return false;
        }
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            std::cerr << "Insufficient funds for withdrawal: " << amount << std::endl;
            return false;
        }
    }

    virtual void displayInfo() const {
        std::cout << "Owner: " << ownerName << ", Account Number: " << accountNumber << ", Balance: " << balance << std::endl;
    }

    bool isValidAmount(double amount) const {
        return amount > 0;
    }

    BankAccount& operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    BankAccount& operator-=(double amount) {
        if (!withdraw(amount)) {
            std::cerr << "Failed to withdraw " << amount << std::endl;
        }
        return *this;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }


    const std::string& getOwnerName() const { return ownerName; }
    const std::string& getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& ownerName, const std::string& accountNumber, double balance, double interestRate)
        : BankAccount(ownerName, accountNumber, balance), interestRate(interestRate) {}

    void deposit(double amount) override {
        if (isValidAmount(amount)) {
            balance += amount;
            balance += amount * interestRate / 100;
        } else {
            std::cerr << "Invalid deposit amount: " << amount << std::endl;
        }
    }

    void displayInfo() const override {
        BankAccount::displayInfo();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};


void processTransaction(BankAccount& account, double amount) {
    account.deposit(amount);
    std::cout << "Deposited " << amount << " to account " << account.getAccountNumber() << std::endl;
}

void processTransaction(BankAccount& from, BankAccount& to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        std::cout << "Transferred " << amount << " from account " << from.getAccountNumber()
                  << " to account " << to.getAccountNumber() << std::endl;
    } else {
        std::cerr << "Failed to transfer " << amount << " from account " << from.getAccountNumber() << std::endl;
    }
}

int main() {
    std::vector<BankAccount*> accounts;
    accounts.push_back(new BankAccount("Ivan Ivanov", "123456789", 1000.0));
    accounts.push_back(new SavingsAccount("Petr Petrov", "987654321", 2000.0, 5.0));


    for (const auto& account : accounts) {
        account->displayInfo();
    }


    BankAccount* account1 = accounts[0];
    *account1 += 500.0;
    std::cout << "After depositing 500: ";
    account1->displayInfo();

    *account1 -= 200.0;
    std::cout << "After withdrawing 200: ";
    account1->displayInfo();


    processTransaction(*account1, 300.0);
    processTransaction(*account1, *accounts[1], 400.0);


    if (*account1 > *accounts[1]) {
        std::cout << "Account " << account1->getAccountNumber() << " has a larger balance than "
                  << accounts[1]->getAccountNumber() << std::endl;
    } else {
        std::cout << "Account " << account1->getAccountNumber() << " does not have a larger balance than "
                  << accounts[1]->getAccountNumber() << std::endl;
    }


    for (const auto& account : accounts) {
        delete account;
    }

    return 0;
}

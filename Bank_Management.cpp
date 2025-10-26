#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    string accountHolder;
    double balance;

public:
    Account(const string &name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) { // made virtual so override is valid
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    virtual ~Account() = default; // added virtual destructor

    double getBalance() const {
        return balance;
    }

    void displayInfo() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingAccount : public Account {
private:
    double interestRate;

public:
    SavingAccount(const string &name, double initialBalance, double rate)
        : Account(name, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout << "Interest applied: " << interest << endl;
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const string &name, double initialBalance, double overdraft)
        : Account(name, initialBalance), overdraftLimit(overdraft) {}

    void setOverdraftLimit(double limit) {
        overdraftLimit = limit;
        cout << "Overdraft limit set to: " << overdraftLimit << endl;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        } else {
            cout << "Exceeded overdraft limit!" << endl;
        }
    }
};

int main() {
    SavingAccount saveAcc("John Doe", 1000, 5.0);
    saveAcc.displayInfo();
    saveAcc.deposit(500);
    saveAcc.applyInterest();
    saveAcc.withdraw(200);
    saveAcc.displayInfo();

    cout << endl;

    CurrentAccount currAcc("Alice Smith", 500, 1000);
    currAcc.displayInfo();
    currAcc.deposit(200);
    currAcc.withdraw(1000);
    currAcc.withdraw(700);
    currAcc.displayInfo();

    return 0;
}

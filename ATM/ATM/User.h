// User.h
#pragma once
#include <string>

class User {
private:
    std::string accountID;
    std::string name;
    double balance;
    std::string currency;
    std::string pin;
    bool isLocked;

public:
    User(std::string id, std::string n, double bal, std::string curr, std::string p)
        : accountID(id), name(n), balance(bal), currency(curr), pin(p), isLocked(false) {
    }

    std::string getAccountID() const { return accountID; }
    std::string getPin() const { return pin; }
    std::string getName() const { return name; }
    double getBalance() const { return balance; }
    bool getIsLocked() const { return isLocked; }
    std::string getCurrency() const { return currency; }

    void unlock() { isLocked = false; }
    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) { balance -= amount; }

    void transferMoney(User& recipientID, double amount) {
        if (balance >= amount) {
            balance -= amount;
            recipientID.deposit(amount);
        }
    }

    void changePin(const std::string& newPin) {
        pin = newPin;
    }

};

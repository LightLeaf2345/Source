#include "User.h"
#include <iostream>
using namespace std;
User::User(string accountID, string name, double balance, string currency, string pin)
    : accountID(accountID), name(name), balance(balance), currency(currency), pin(pin) {
}

void User::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    }
    else {
        cout << "Invalid deposit amount.\n";
    }
}

void User::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    }
    else {
        cout << "Invalid or insufficient funds for withdrawal.\n";
    }
}

void User::transfer(User& recipient, double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        recipient.deposit(amount);
    }
    else {
        cout << "Transfer failed. Invalid amount or insufficient funds.\n";
    }
}

double User::getBalance() const {
    return balance;
}

string User::getAccountID() const {
    return accountID;
}

string User::getName() const {
    return name;
}

string User::getCurrency() const {
    return currency;
}

string User::getPin() const {
    return pin;
}

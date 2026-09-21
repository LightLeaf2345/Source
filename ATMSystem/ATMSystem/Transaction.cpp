#include "Transaction.h"
#include <iostream>

void Transaction::deposit(User& user, double amount) {
    if (amount > 0) {
        user.deposit(amount); // Calls User's deposit method
        std::cout << "Deposited " << amount << " to account " << user.getAccountID() << ".\n";
    }
    else {
        std::cout << "Invalid deposit amount.\n";
    }
}

void Transaction::withdraw(User& user, double amount) {
    if (amount > 0) {
        user.withdraw(amount); // Calls User's withdraw method
        std::cout << "Withdrew " << amount << " from account " << user.getAccountID() << ".\n";
    }
    else {
        std::cout << "Invalid withdrawal amount.\n";
    }
}

void Transaction::transfer(User& sender, User& receiver, double amount) {
    if (amount > 0) {
        sender.transfer(receiver, amount); // Calls User's transfer method
        std::cout << "Transferred " << amount << " from account " << sender.getAccountID() << " to account " << receiver.getAccountID() << ".\n";
    }
    else {
        std::cout << "Invalid transfer amount.\n";
    }
}

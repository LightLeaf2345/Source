//Transaction.h
#pragma once
#include <string>
#include "User.h"

class Transaction{
    public:
    static void deposit(User & user, double amount);
    static void withdraw(User& user, double amount);
    static void transfer(User& sender, User& receiver, double amount);
    };
};

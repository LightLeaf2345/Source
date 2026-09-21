//Transaction.h
#pragma once
#include <string>

class Transaction {
public:
    std::string userId;
    std::string type;
    double amount;
    std::string date;

    Transaction(std::string id, std::string t, double amt, std::string d)
        : userId(id), type(t), amount(amt), date(d) {
    }
};

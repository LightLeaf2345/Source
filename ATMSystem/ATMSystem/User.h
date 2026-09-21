#include <string>

class User {
private:
    std::string accountID;
    std::string name;
    double balance;
    std::string currency;
    std::string pin;

public:
    User(std::string accountID, std::string name, double balance, std::string currency, std::string pin);

    void deposit(double amount);
    void withdraw(double amount);
    void transfer(User& recipient, double amount);

    double getBalance() const;
    std::string getAccountID() const;
    std::string getName() const;
    std::string getCurrency() const;
    std::string getPin() const;
};
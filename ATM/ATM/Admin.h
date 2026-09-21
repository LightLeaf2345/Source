//Admin.h
#pragma once
#include <string>
#include "LinkedList.h"
#include "User.h"

template <typename T>
class LinkedList;
class Admin {
private:
    std::string username;
    std::string password;

public:
    Admin(std::string uname, std::string pass) : username(uname), password(pass) {}

    bool login(std::string user, std::string pass);
    void manageUsers(LinkedList<User>& users);
    void displayUsersFromFile();
    void saveUsersToFile(const LinkedList<User>& users);

    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
};
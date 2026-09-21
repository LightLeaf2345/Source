// ATMSystem.h
#pragma once
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"

class ATMSystem {
public:
    void loadSystemData(LinkedList<Admin>& admins, LinkedList<User>& users);
    void saveSystemData(const LinkedList<Admin>& admins, const LinkedList<User>& users);
    void adminLogin(LinkedList<Admin>& admins, LinkedList<User>& users);
    void userOperations(LinkedList<User>& users, const std::string& accountID);
    void roleSelection(LinkedList<Admin>& admins, LinkedList<User>& users);
};
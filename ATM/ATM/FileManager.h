//FileManager.h
#pragma once
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"
#include "Transaction.h"
#include <string>

class FileManager {
public:
    void loadAdmins(LinkedList<Admin>& admins);
    void saveAdmins(const LinkedList<Admin>& admins);

    void loadUsers(LinkedList<User>& users);
    void saveUsers(const LinkedList<User>& users);

    void loadTransactions(LinkedList<Transaction>& transactions);
    void saveTransactions(const LinkedList<Transaction>& transactions);
};

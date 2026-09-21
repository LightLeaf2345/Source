#include <iostream>
#include "ATMSystem.h"
#include "FileManager.h"
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"

using namespace std;

int main() {
    LinkedList<Admin> admins;
    LinkedList<User> users;
    ATMSystem atmSystem;
    int ans;

    // Load system data (Admins and Users)
    atmSystem.loadSystemData(admins, users);

    cout << "Press (1) for Admin login or (2) for User login: ";
    cin >> ans;

    if (ans == 1) {
        // Admin login process
        atmSystem.adminLogin(admins, users);
    }
    else if (ans == 2) {
        // User operations
        string accountID;
        cout << "Enter your account ID: ";
        cin >> accountID;

        atmSystem.userOperations(users, accountID);
    }
    else {
        cout << "Invalid input! Please restart the program.\n";
    }

    // Save system data after operations
    atmSystem.saveSystemData(admins, users);

    return 0;
}

//Main.cpp
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
    int Admins = 1, Users = 2, ans;
    cout << "Press (1) for Admins or (2) for Users ";
    cin >> ans;
    if (ans == 1)
    {
        // Load system data (Admins and Users)
        atmSystem.loadSystemData(admins, users);

        // Admin login process
        atmSystem.adminLogin(admins, users);
    }
    else if (ans == 2)
    {
        // User operations (You can simulate user login here)
        string accountID;
        cout << "Enter your account ID: ";
        cin >> accountID;  // This is correct since accountID is a string
        atmSystem.userOperations(users, accountID);  // Ensure the correct argument type

        // Save system data after operations
        atmSystem.saveSystemData(admins, users);
    }
    else
    {
        cout << "Error 404";
    }
    return 0;
}
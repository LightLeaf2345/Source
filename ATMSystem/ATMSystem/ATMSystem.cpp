#include "Admin.h"
#include "LinkedList.h"
#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

void Admin::manageUsers(LinkedList<User>& users) {
    string action;
    cout << "1. View users\n";
    cout << "2. Add user\n";
    cout << "3. Delete user\n";
    cout << "4. Unlock user\n";
    cout << "Enter action: ";
    cin >> action;

    if (action == "1") {
        displayUsersFromFile();
    }
    else if (action == "2") {
        string newUserID, newName, newPin;
        double newBalance;
        string newCurrency;

        cout << "Enter new user ID: ";
        cin >> newUserID;
        cout << "Enter new name: ";
        cin.ignore(); // To clear the buffer
        getline(cin, newName);
        cout << "Enter initial balance: ";
        cin >> newBalance;
        cout << "Enter currency (e.g., VND, USD): ";
        cin >> newCurrency;
        cout << "Enter new PIN: ";
        cin >> newPin;

        User newUser(newUserID, newName, newBalance, newCurrency, newPin);
        users.add(newUser);

        // Save the user to a new file
        ofstream userFile(newUserID + ".txt");
        if (userFile.is_open()) {
            userFile << newUser.getAccountID() << endl;
            userFile << newUser.getName() << endl;
            userFile << newUser.getBalance() << endl;
            userFile << newUser.getCurrency() << endl;
            userFile << newUser.getPin() << endl;
            userFile.close();
        }

        saveUsersToFile(users);
        cout << "User added successfully!\n";
    }
    else if (action == "3") {
        string userToDelete;
        cout << "Enter user ID to delete: ";
        cin >> userToDelete;

        Node<User>* userNode = users.findByID(userToDelete);
        if (userNode != nullptr) {
            users.deleteNodeByID(userToDelete);

            // Delete the user's file
            string userFileName = userToDelete + ".txt";
            if (remove(userFileName.c_str()) == 0) {
                cout << "User file deleted successfully.\n";
            }
            else {
                cout << "Failed to delete user file.\n";
            }

            saveUsersToFile(users);
            cout << "User deleted successfully.\n";
        }
        else {
            cout << "User not found.\n";
        }
    }
    else if (action == "4") {
        string userToUnlock;
        cout << "Enter user ID to unlock: ";
        cin >> userToUnlock;

        Node<User>* userNode = users.findByID(userToUnlock);
        if (userNode != nullptr) {
            userNode->data.unlockAccount();
            saveUsersToFile(users);
            cout << "User unlocked successfully.\n";
        }
        else {
            cout << "User not found.\n";
        }
    }
}

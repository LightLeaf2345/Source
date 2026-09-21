//Admin.cpp
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"

using namespace std;

bool Admin::login(string user, string pass) {
    return (user == username && pass == password);
}

// Utility function to read all users from TheTu.txt
void Admin::displayUsersFromFile() {
    ifstream inputFile("TheTu.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    }
    else {
        cout << "Unable to open TheTu.txt.\n";
    }
}

// Function to save the list of users to TheTu.txt
void Admin::saveUsersToFile(const LinkedList<User>& users) {
    ofstream outputFile("TheTu.txt");
    if (outputFile.is_open()) {
        Node<User>* currentNode = users.getHead();
        while (currentNode != nullptr) {
            User& user = currentNode->data;
            outputFile << user.getAccountID() << ","
                << user.getName() << ","
                << user.getBalance() << ","
                << user.getCurrency() << ","
                << user.getPin() << endl;
            currentNode = currentNode->next;
        }
        outputFile.close();
    }
    else {
        cout << "Unable to open TheTu.txt for writing.\n";
    }
}

void Admin::manageUsers(LinkedList<User>& users) {
    string action;
    cout << "* 1. Xem danh sach Tai khoan\n* 2. Them Tai Khoan\n* 3. Xoa Tai Khoan\n* 4. Mo khoa Tai Khoan\n****************************\n\nChoose action: ";
    cin >> action;

    if (action == "1") {
        // Display all users from TheTu.txt
        displayUsersFromFile();
    }
    else if (action == "2") {
        string newUserID, newName, newPin;
        double newBalance;
        string newCurrency;

        cout << "Enter new user ID: ";
        cin >> newUserID;

        // Check if the ID already exists
        Node<User>* existingUserNode = users.findByID(newUserID);
        if (existingUserNode != nullptr) {
            cout << "User ID already exists. Please choose a different ID.\n";
            return;
        }

        cout << "Enter new user name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, newName); // Use getline to allow spaces in the name
        cout << "Enter new balance: ";
        cin >> newBalance;
        cout << "Enter new currency (e.g., VND, USD): ";
        cin >> newCurrency;
        cout << "Enter new user PIN: ";
        cin >> newPin;

        // Create a new User and add to the list
        User newUser(newUserID, newName, newBalance, newCurrency, newPin);
        users.add(newUser);

        // Save the user to a new file [ID].txt
        ofstream userFile(newUserID + ".txt");
        if (userFile.is_open()) {
            userFile << newUser.getAccountID() << endl;
            userFile << newUser.getName() << endl;
            userFile << newUser.getBalance() << endl;
            userFile << newUser.getCurrency() << endl;
            userFile << newUser.getPin() << endl;
            userFile.close();
        }
        else {
            cout << "Unable to create user file.\n";
        }

        // Update TheTu.txt by saving all users to the file
        saveUsersToFile(users);

        cout << "User added successfully!\n";
    }
    else if (action == "3") {
        string userToDelete;
        cout << "Enter user ID to delete: ";
        cin >> userToDelete;

        // Find the user by ID and delete it
        Node<User>* userNode = users.findByID(userToDelete);
        if (userNode != nullptr) {
            users.deleteNodeByID(userToDelete); // Delete the user by ID

            // Delete the user's file
            string userFileName = userToDelete + ".txt";
            if (remove(userFileName.c_str()) != 0) {
                cout << "User file deleted fail.\n";
            }
            else {
                cout << "User file deleted successfully.\n";
            }

            // Update TheTu.txt by saving all users to the file
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

        // Find the user by ID and unlock
        Node<User>* userNode = users.findByID(userToUnlock);
        if (userNode != nullptr) {
            userNode->data.unlock();
            cout << "User unlocked successfully.\n";
        }
        else {
            cout << "User not found.\n";
        }
    }
}

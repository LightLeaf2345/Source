//FileManager.cpp
#include "FileManager.h"
#include "Admin.h"
#include "User.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Load Admins from file (already provided)
void FileManager::loadAdmins(LinkedList<Admin>& admins) {
    ifstream file("Admin.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string username, password;

        getline(ss, username, ',');
        getline(ss, password, ',');

        Admin admin(username, password);
        admins.add(admin);
    }

    file.close();
}
// Save Admins to file
void FileManager::saveAdmins(const LinkedList<Admin>& admins) {
    ofstream file("Admin.txt");

    Node<Admin>* current = admins.getHead();
    while (current != nullptr) {
        file << current->data.getUsername() << "," << current->data.getPassword() << "\n";
        current = current->next;
    }

    file.close();
}

// Load Users from file (already provided)
void FileManager::loadUsers(LinkedList<User>& users) {
    ifstream file("User.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string accountID, name, pin, currency;
        double balance;

        getline(ss, accountID, ',');
        getline(ss, name, ',');
        ss >> balance;
        ss.ignore();
        getline(ss, currency, ',');
        getline(ss, pin, ',');

        User user(accountID, name, balance, currency, pin);
        users.add(user);
    }

    file.close();
}

// Save Users to file
void FileManager::saveUsers(const LinkedList<User>& users) {
    ofstream file("User.txt");

    Node<User>* current = users.getHead();
    while (current != nullptr) {
        file << current->data.getAccountID() << ","
            << current->data.getName() << ","
            << current->data.getBalance() << ","
            << current->data.getCurrency() << ","
            << current->data.getPin() << "\n";
        current = current->next;
    }

    file.close();
}


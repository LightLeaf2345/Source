//ATMSystem.cpp
#include <iostream>
#include <fstream>  
#include <string>   
#include "LinkedList.h"
#include "Admin.h"
#include "User.h"
#include "ATMSystem.h"
#include "FileManager.h"

using namespace std;

void ATMSystem::loadSystemData(LinkedList<Admin>& admins, LinkedList<User>& users) {
    FileManager fileManager;
    fileManager.loadAdmins(admins);
    fileManager.loadUsers(users);
}

void ATMSystem::saveSystemData(const LinkedList<Admin>& admins, const LinkedList<User>& users) {
    FileManager fileManager;
    fileManager.saveAdmins(admins);
    fileManager.saveUsers(users);
    cout << "System data saved successfully!" << endl;
}

void ATMSystem::adminLogin(LinkedList<Admin>& admins, LinkedList<User>& users) {
    string username, password;
    bool loggedIn = false;
    Admin* currentAdmin = nullptr;

    while (!loggedIn) {
        cout << "*********************\n";
        cout << "*  DANG NHAP ADMIN  *\n";
        cout << "*********************\n";
        cout << "\nUser: ";
        cin >> username;
        cout << "Pin: ";
        cin >> password;
        cout << "\n";

        // Find admin by username and validate login
        Node<Admin>* adminNode = admins.findByID(username);
        if (adminNode != nullptr && adminNode->data.login(username, password)) {
            loggedIn = true;
            currentAdmin = &adminNode->data;
            cout << "************MENU*************\n";
        }
        else {
            cout << "Invalid username or password. Try again.\n";
        }
    }

    // Admin can now manage users
    currentAdmin->manageUsers(users);
}

void ATMSystem::userOperations(LinkedList<User>& users, const string& accountID) {
    Node<User>* userNode = users.findByID(accountID);
    if (userNode != nullptr) {
        User& currentUser = userNode->data;
        string operation;
        cout << "************MENU*************\n";
        cout << "Choose operation: * 1. Xem thong tin Tk\n* 2. Gui tien\n*3. Rut tien\n*4. Chuyen tien\n*5. Xem noi dung giao dich\n*6. Doi ma Pin\n*7. Thoat\n";
        cout << "************MENU*************\n";
        cin >> operation;

        if (operation == "1") {
            cout << "Xem thong tin Tk: " << currentUser.getBalance() << endl;
        }
        else if (operation == "2") {
            double amount;
            cout << "Nhap so tien gui: ";
            cin >> amount;
            currentUser.deposit(amount);
        }
        else if (operation == "3") {
            double amount;
            cout << "Nhap so tien rut: ";
            cin >> amount;
            currentUser.withdraw(amount);
        }
        else if (operation == "4") {
            string recipientID;
            double amount;
            cout << "Nhap ID tai khoan nhan tien: ";
            cin >> recipientID;
            cout << "Nhap so tien chuyen: ";
            cin >> amount;

            // Find the recipient user by ID
            Node<User>* recipientNode = users.findByID(recipientID);
            if (recipientNode != nullptr) {
                currentUser.transferMoney(recipientNode->data, amount);
            }
            else {
                cout << "Recipient user not found.\n";
            }
        }
        else if (operation == "5") {
            cout << "Xem noi dung giao dich:\n";
            ifstream transactionFile("Transaction.txt");
            if (transactionFile.is_open()) {
                string line;
                while (getline(transactionFile, line)) {
                    cout << line << endl;
                }
                transactionFile.close();
            }
            else {
                cout << "Khong the mo file giao dich.\n";
            }
        }
        else if (operation == "6") {
            string newPin;
            cout << "Nhap ma PIN moi: ";
            cin >> newPin;
            currentUser.changePin(newPin);
        }
        else if (operation == "7") {
            cout << "Thoat...\n";
        }
    }
}

#pragma once
#include <iostream>
#include "Node.h"
#include "Admin.h"
#include "User.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Pointer to the first node in the list

public:
    // Constructor initializes an empty linked list
    LinkedList() : head(nullptr) {}

    // Destructor to delete all nodes and free memory
    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add a new node with the given value at the end of the list
    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Find the first node by matching user ID (only for User or Admin objects)
    Node<T>* findByID(const std::string& id) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if constexpr (std::is_same<T, Admin>::value) {
                if (current->data.getUsername() == id) { // Ensure Admin has getUsername
                    return current;
                }
            }
            else if constexpr (std::is_same<T, User>::value) {
                if (current->data.getAccountID() == id) { // Ensure User has getAccountID
                    return current;
                }
            }
            current = current->next;
        }
        return nullptr;  // Return null if no match is found
    }

    // Delete the first node by matching user ID (only for User objects)
    void deleteNodeByID(const std::string& id) {
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        if constexpr (std::is_same<T, User>::value) {
            // Check if the head node needs to be deleted
            if (current != nullptr && current->data.getAccountID() == id) {
                head = current->next;
                delete current;
                return;
            }

            // Search for the node to delete
            while (current != nullptr && current->data.getAccountID() != id) {
                previous = current;
                current = current->next;
            }

            if (current == nullptr) return;  // ID not found

            // Unlink the node from the list
            previous->next = current->next;
            delete current;
        }
    }

    // Display all nodes in the list
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }
    }

    // Get the head of the list
    Node<T>* getHead() const { return head; }
};

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::clear() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

bool LinkedList::contains(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}

void LinkedList::remove(int value) {
    Node* current = head;
    Node* previous = nullptr;
    while (current) {
        if (current->data == value) {
            if (previous)
                previous->next = current->next;
            else
                head = current->next;
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void LinkedList::display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::findSubsequence(LinkedList& L2) {
    return nullptr;
}

LinkedList LinkedList::intersect(LinkedList& L2) {
    LinkedList result;
    Node* current = head;
    while (current) {
        if (L2.contains(current->data))
            result.append(current->data);
        current = current->next;
    }
    return result;
}

LinkedList LinkedList::removeMin(int minValue) {
    LinkedList result;
    Node* current = head;
    while (current) {
        if (current->data != minValue)
            result.append(current->data);
        current = current->next;
    }
    return result;
}

#pragma once
#include "Node.h"

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void append(int value);
    void clear();
    bool contains(int value);
    void remove(int value);
    void display();

    Node* getHead();  // Add getter for head
    Node* findSubsequence(LinkedList& L2);
    LinkedList intersect(LinkedList& L2);
    LinkedList removeMin(int minValue);
};

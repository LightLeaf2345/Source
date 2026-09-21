#pragma once
#include "Node.h"
#include <iostream>

class Stack {
private:
    Node* top;

public:
    Stack();
    ~Stack();

    void push(char value);  // Push an element onto the stack
    char pop();             // Pop an element from the stack
    char peek();            // Peek at the top element of the stack
    bool isEmpty();         // Check if the stack is empty
};

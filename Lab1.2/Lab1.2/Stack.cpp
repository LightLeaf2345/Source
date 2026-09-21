#include "Stack.h"

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(char value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

char Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack underflow");
    }
    Node* temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}

char Stack::peek() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return top->data;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

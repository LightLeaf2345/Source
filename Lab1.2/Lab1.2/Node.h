#pragma once

class Node {
public:
    char data; // Can hold operators, operands, or parentheses
    Node* next;

    Node(char value) : data(value), next(nullptr) {}
};

#include <iostream>
using namespace std;

template <class DataType>
class Node {
public:
    DataType data;
    Node* pNext;
    Node(DataType value) : data(value), pNext(nullptr) {}
};

template <class DataType>
class Stack {
private:
    Node<DataType>* top;

public:
    Stack() : top(nullptr) {}

    void push(DataType value) {
        Node<DataType>* newNode = new Node<DataType>(value);
        newNode->pNext = top;
        top = newNode;
    }

    DataType pop() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        DataType value = top->data;
        Node<DataType>* temp = top;
        top = top->pNext;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to test Stack operations
void testStack() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Popping: " << s.pop() << endl;
    cout << "Popping: " << s.pop() << endl;
    cout << "Popping: " << s.pop() << endl;
}

int main() {
    testStack();
    return 0;
}

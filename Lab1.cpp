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

// Function to convert decimal to binary
void convertToBinary(int num) {
    Stack<int> stack;
    while (num > 0) {
        stack.push(num % 2);
        num /= 2;
    }
    cout << "Binary representation: ";
    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
    cout << endl;
}

int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
    convertToBinary(number);
    return 0;
}

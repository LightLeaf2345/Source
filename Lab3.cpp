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
            return "";
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

// Function to convert prefix to postfix
void prefixToPostfix(const string& expr) {
    Stack<string> stack;
    for (int i = expr.size() - 1; i >= 0; i--) {
        if (isalnum(expr[i])) {
            string op(1, expr[i]);
            stack.push(op);
        }
        else {
            string op1 = stack.pop();
            string op2 = stack.pop();
            string result = op1 + op2 + expr[i];
            stack.push(result);
        }
    }
    cout << "Postfix expression: " << stack.pop() << endl;
}

int main() {
    string expr;
    cout << "Enter a prefix expression: ";
    cin >> expr;
    prefixToPostfix(expr);
    return 0;
}

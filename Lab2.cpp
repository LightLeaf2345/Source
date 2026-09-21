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
            return '\0';
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

// Function to check if parentheses are balanced
bool isBalanced(const string& expr) {
    Stack<char> stack;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            stack.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;
            char top = stack.pop();
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                return false;
        }
    }
    return stack.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;
    if (isBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    return 0;
}

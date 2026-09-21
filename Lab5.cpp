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

template <class DataType>
class Queue {
private:
    Stack<DataType> stack1, stack2;

public:
    void enqueue(DataType value) {
        stack1.push(value);
    }

    DataType dequeue() {
        if (stack2.isEmpty()) {
            if (stack1.isEmpty()) {
                cout << "Queue is empty." << endl;
                return -1;
            }
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
        }
        return stack2.pop();
    }

    bool isEmpty() {
        return stack1.isEmpty() && stack2.isEmpty();
    }
};

// Function to test Queue operations
void testQueue() {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;
}

int main() {
    testQueue();
    return 0;
}

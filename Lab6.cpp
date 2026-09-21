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
class Queue {
private:
    Node<DataType>* front;
    Node<DataType>* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(DataType value) {
        Node<DataType>* newNode = new Node<DataType>(value);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->pNext = newNode;
        rear = newNode;
    }

    DataType dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        Node<DataType>* temp = front;
        DataType value = front->data;
        front = front->pNext;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
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

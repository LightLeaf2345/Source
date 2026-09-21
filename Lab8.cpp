#include <iostream>
using namespace std;

template <class DataType>
class Queue {
private:
    DataType* arr;
    int front, rear, size;

public:
    Queue(int n) : size(n), front(-1), rear(-1) {
        arr = new DataType[size];
    }

    void enqueue(DataType value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full." << endl;
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % size;
        arr[rear] = value;
    }

    DataType dequeue() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        DataType value = arr[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
        return value;
    }

    bool isEmpty() {
        return front == -1;
    }
};

// Function to test Circular Queue operations
void testQueue() {
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;
    cout << "Dequeuing: " << q.dequeue() << endl;
}

int main() {
    testQueue();
    return 0;
}

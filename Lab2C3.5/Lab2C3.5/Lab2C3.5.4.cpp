#include <iostream>
#include <algorithm> // for std::sort
using namespace std;

template <typename DataType>
struct Node {
    DataType _data;
    Node* _pNext;

    Node(DataType data) : _data(data), _pNext(nullptr) {}
};

template <typename DataType>
class LinkedList {
private:
    Node<DataType>* _pHead;
    Node<DataType>* _pTail;
    int _iSize;

public:
    LinkedList() : _pHead(nullptr), _pTail(nullptr), _iSize(0) {}

    ~LinkedList() {
        clear();
    }

    void addTail(DataType data) {
        Node<DataType>* newNode = new Node<DataType>(data);
        if (!_pHead) {
            _pHead = newNode;
            _pTail = newNode;
        }
        else {
            _pTail->_pNext = newNode;
            _pTail = newNode;
        }
        _iSize++;
    }

    void display() {
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            cout << pWalker->_data << " ";
            pWalker = pWalker->_pNext;
        }
        cout << endl;
    }

    Node<DataType>* getHead() {
        return _pHead;
    }

    void clear() {
        while (_pHead) {
            Node<DataType>* temp = _pHead;
            _pHead = _pHead->_pNext;
            delete temp;
        }
        _pTail = nullptr;
        _iSize = 0;
    }

    LinkedList<DataType> difference(LinkedList<DataType>& L2) {
        LinkedList<DataType> L3;
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            Node<DataType>* pWalkerL2 = L2._pHead;
            bool found = false;
            while (pWalkerL2) {
                if (pWalker->_data == pWalkerL2->_data) {
                    found = true;
                    break;
                }
                pWalkerL2 = pWalkerL2->_pNext;
            }
            if (!found) {
                L3.addTail(pWalker->_data);
            }
            pWalker = pWalker->_pNext;
        }
        return L3;
    }

    LinkedList<DataType> intersection(LinkedList<DataType>& L2) {
        LinkedList<DataType> L3;
        Node<DataType>* pWalker = _pHead;
        while (pWalker) {
            Node<DataType>* pWalkerL2 = L2._pHead;
            while (pWalkerL2) {
                if (pWalker->_data == pWalkerL2->_data) {
                    L3.addTail(pWalker->_data);
                    break;
                }
                pWalkerL2 = pWalkerL2->_pNext;
            }
            pWalker = pWalker->_pNext;
        }
        return L3;
    }

    LinkedList<DataType> unionList(LinkedList<DataType>& L2) {
        LinkedList<DataType> L3;
        Node<DataType>* pWalker = _pHead;

        while (pWalker) {
            L3.addTail(pWalker->_data);
            pWalker = pWalker->_pNext;
        }

        pWalker = L2._pHead;
        while (pWalker) {
            Node<DataType>* pWalkerL3 = L3.getHead();
            bool found = false;
            while (pWalkerL3) {
                if (pWalker->_data == pWalkerL3->_data) {
                    found = true;
                    break;
                }
                pWalkerL3 = pWalkerL3->_pNext;
            }
            if (!found) {
                L3.addTail(pWalker->_data);
            }
            pWalker = pWalker->_pNext;
        }
        return L3;
    }

    void sort() {
        if (!_pHead) return;

        DataType* dataArray = new DataType[_iSize];
        Node<DataType>* pWalker = _pHead;
        int index = 0;

        while (pWalker) {
            dataArray[index++] = pWalker->_data;
            pWalker = pWalker->_pNext;
        }

        // Use std::sort to avoid the ambiguity with sort()
        std::sort(dataArray, dataArray + _iSize);

        clear();
        for (int i = 0; i < _iSize; ++i) {
            addTail(dataArray[i]);
        }

        delete[] dataArray;
    }
};

int main() {
    LinkedList<int> L1, L2;

    L1.addTail(1);
    L1.addTail(5);
    L1.addTail(3);
    L1.addTail(7);
    L1.addTail(4);
    L1.addTail(2);
    L1.addTail(9);

    L2.addTail(9);
    L2.addTail(6);
    L2.addTail(2);
    L2.addTail(3);
    L2.addTail(8);

    cout << "List L1: ";
    L1.display();

    cout << "List L2: ";
    L2.display();

    LinkedList<int> L3_diff = L1.difference(L2);
    L3_diff.sort();
    cout << "List L3 (L1 - L2 in ascending order): ";
    L3_diff.display();

    LinkedList<int> L3_intersect = L1.intersection(L2);
    L3_intersect.sort();
    cout << "List L3 (L1 ∩ L2 in ascending order): ";
    L3_intersect.display();

    LinkedList<int> L3_union = L1.unionList(L2);
    L3_union.sort();
    cout << "List L3 (L1 ∪ L2 in ascending order): ";
    L3_union.display();

    return 0;
}

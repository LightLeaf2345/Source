#include <iostream>
#include <string>
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

    void clear() {
        while (_pHead) {
            Node<DataType>* temp = _pHead;
            _pHead = _pHead->_pNext;
            delete temp;
        }
        _pTail = nullptr;
        _iSize = 0;
    }

    LinkedList<DataType> findSubsequence(LinkedList<DataType>& L2) {
        LinkedList<DataType> L3;
        Node<DataType>* pWalker1 = _pHead;

        while (pWalker1) {
            Node<DataType>* pWalker2 = L2._pHead;
            Node<DataType>* pStart = pWalker1; 

            while (pWalker2) {
                Node<DataType>* tempWalker = pStart;
                bool isMatch = true;

                while (tempWalker && pWalker2) {
                    if (tempWalker->_data != pWalker2->_data) {
                        isMatch = false;
                        break;
                    }
                    tempWalker = tempWalker->_pNext;
                    pWalker2 = pWalker2->_pNext;
                }

                if (isMatch) {
                    while (pStart && pStart->_data == tempWalker->_data) {
                        L3.addTail(pStart->_data);
                        pStart = pStart->_pNext;
                    }
                    return L3;
                }

                pWalker2 = L2._pHead; 
                pWalker1 = pWalker1->_pNext;
            }

            pWalker1 = pWalker1->_pNext; 
        }

        return L3; 
    }
};

int main() {
    LinkedList<int> L1, L2;

    L1.addTail(2);
    L1.addTail(6);
    L1.addTail(1);
    L1.addTail(5);
    L1.addTail(4);
    L1.addTail(3);
    L1.addTail(8);
    L1.addTail(7);
    L1.addTail(9);

    L2.addTail(8);
    L2.addTail(3);
    L2.addTail(6);
    L2.addTail(1);
    L2.addTail(5);
    L2.addTail(4);
    L2.addTail(3);
    L2.addTail(7);
    L2.addTail(9);
    L2.addTail(0);

    cout << "List L1: ";
    L1.display();

    cout << "List L2: ";
    L2.display();

    LinkedList<int> L3 = L1.findSubsequence(L2);
    cout << "List L3 (First subsequence of L1 in L2): ";
    L3.display();

    return 0;
}

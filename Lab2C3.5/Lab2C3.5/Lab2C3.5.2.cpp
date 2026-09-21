#include <iostream>
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

    void append(LinkedList<DataType>& L2) {
        if (L2._pHead) {
            if (!_pHead) {
                _pHead = L2._pHead;
                _pTail = L2._pTail;
            }
            else {
                _pTail->_pNext = L2._pHead;
                _pTail = L2._pTail;
            }
            _iSize += L2._iSize;
            L2.clear();  
        }
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

    LinkedList<DataType> totalSum(LinkedList<DataType>& L2) {
        LinkedList<DataType> L3;
        Node<DataType>* pWalker1 = _pHead;
        Node<DataType>* pWalker2 = L2._pHead;

        while (pWalker1 || pWalker2) {
            int value1 = (pWalker1) ? pWalker1->_data : 0;
            int value2 = (pWalker2) ? pWalker2->_data : 0;
            L3.addTail(value1 + value2);
            if (pWalker1) pWalker1 = pWalker1->_pNext;
            if (pWalker2) pWalker2 = pWalker2->_pNext;
        }
        return L3;
    }

    bool isSame(LinkedList<DataType>& L2) {
        if (_iSize != L2._iSize) {
            return false;
        }

        Node<DataType>* pWalker1 = _pHead;
        Node<DataType>* pWalker2 = L2._pHead;

        while (pWalker1) {
            if (pWalker1->_data != pWalker2->_data) {
                return false;
            }
            pWalker1 = pWalker1->_pNext;
            pWalker2 = pWalker2->_pNext;
        }
        return true;
    }

    void deleteGreaterThanSum(LinkedList<DataType>& L2) {
        int sumL2 = 0;
        Node<DataType>* pWalker = L2.getHead();
        while (pWalker) {
            sumL2 += pWalker->_data;
            pWalker = pWalker->_pNext;
        }

        pWalker = L2.getHead();
        Node<DataType>* prev = nullptr;
        while (pWalker) {
            if (pWalker->_data > sumL2) {
                if (prev) {
                    prev->_pNext = pWalker->_pNext;
                }
                else {
                    L2._pHead = pWalker->_pNext;
                }
                delete pWalker;
                L2._iSize--;
                break; 
            }
            prev = pWalker;
            pWalker = pWalker->_pNext;
        }
    }

    void deleteMaxInOther(LinkedList<DataType>& L2) {
        if (L2._pHead == nullptr) return;

        Node<DataType>* pWalker = L2._pHead;
        DataType maxVal = pWalker->_data;
        while (pWalker) {
            if (pWalker->_data > maxVal) {
                maxVal = pWalker->_data;
            }
            pWalker = pWalker->_pNext;
        }

        pWalker = _pHead;
        Node<DataType>* prev = nullptr;
        while (pWalker) {
            if (pWalker->_data == maxVal) {
                if (prev) {
                    prev->_pNext = pWalker->_pNext;
                }
                else {
                    _pHead = pWalker->_pNext;
                }
                delete pWalker;
                _iSize--;
                pWalker = (prev) ? prev->_pNext : _pHead;  
            }
            else {
                prev = pWalker;
                pWalker = pWalker->_pNext;
            }
        }
    }
};

int main() {
    LinkedList<int> L1, L2;

    L1.addTail(1);
    L1.addTail(3);
    L1.addTail(5);
    L1.addTail(7);

    L2.addTail(2);
    L2.addTail(3);
    L2.addTail(6);
    L2.addTail(7);

    cout << "List L1: ";
    L1.display();

    cout << "List L2: ";
    L2.display();

    LinkedList<int> L3;
    L3.append(L1);
    L3.append(L2);
    cout << "List L3 (after appending L2 to L1): ";
    L3.display();

    LinkedList<int> L3_diff = L1.difference(L2);
    cout << "List L3 (L1 - L2): ";
    L3_diff.display();

    LinkedList<int> L3_intersect = L1.intersection(L2);
    cout << "List L3 (L1 ∩ L2): ";
    L3_intersect.display();

    LinkedList<int> L3_union = L1.unionList(L2);
    cout << "List L3 (L1 ∪ L2): ";
    L3_union.display();

    LinkedList<int> L3_total = L1.totalSum(L2);
    cout << "List L3 (Sum of corresponding elements): ";
    L3_total.display();

    cout << "Do L1 and L2 have the same values? " << (L1.isSame(L2) ? "Yes" : "No") << endl;

    L2.deleteGreaterThanSum(L2);
    cout << "List L2 after deleting first element greater than sum of L2: ";
    L2.display();

    L1.deleteMaxInOther(L2);
    cout << "List L1 after deleting elements equal to the largest value in L2: ";
    L1.display();

    return 0;
}

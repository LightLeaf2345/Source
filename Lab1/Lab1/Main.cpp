#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>  // For std::min

#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {
    LinkedList L1, L2, L3, L4, L5;
    int value;

    cout << "Nhap danh sach L1 (press Enter without input to stop):" << endl;
    while (true) {
        string input;
        getline(cin, input);  // Read the whole line
        if (input.empty()) break;  // Stop if the input is empty
        stringstream(input) >> value;  // Convert string to int
        L1.append(value);
    }

    cout << "Nhap danh sach L2 (press Enter without input to stop):" << endl;
    while (true) {
        string input;
        getline(cin, input);  // Read the whole line
        if (input.empty()) break;  // Stop if the input is empty
        stringstream(input) >> value;  // Convert string to int
        L2.append(value);
    }

    L3 = L1.intersect(L2);

    Node* subsequence = L1.findSubsequence(L2);
    if (subsequence) {
        Node* current = subsequence;
        while (current) {
            L4.append(current->data);
            current = current->next;
        }
    }

    int minValue = INT_MAX;
    Node* current = L2.getHead();
    while (current) {
        minValue = min(minValue, current->data);
        current = current->next;
    }
    L5 = L1.removeMin(minValue);

    cout << "L3: ";
    L3.display();

    cout << "L4: ";
    L4.display();

    cout << "L5: ";
    L5.display();

    return 0;
}

#include <iostream>
using namespace std;

void readArray(int M[], int& n, int& x) {
    cout << "n = ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> M[i];
    }
    cout << "x = ";
    cin >> x;
}

void binarySearch(int M[], int n, int x) {
    int left = 0;
    int right = n - 1;
    int mid;
    int splitCount = 0;

    while (left <= right) {
        mid = left + (right - left) / 2;
        splitCount++;
        cout << "Lan " << splitCount << " trong khoang [" << left << ".." << right << "] // mid = " << M[mid] << endl;

        if (M[mid] == x) 
        {
            break;
        }
        else if (M[mid] < x) 
        {
            left = mid + 1; 
        }
        else 
        {
            right = mid - 1;
        }
    }
    cout << "So lan chia doi " << splitCount << endl;
}

int main() {
    int M[100];
    int n; 
    int x; 
    readArray(M, n, x); 
    binarySearch(M, n, x);
    return 0;
}
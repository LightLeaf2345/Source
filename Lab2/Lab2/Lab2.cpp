#include <iostream>
using namespace std;
int A = 100;
void readarray(int A[], int &n, int &x) 
{
    cout << "n = ";
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << "x = ";
    cin >> x;
}
void search(int A[], int n, int x) {
    int count = 0;
    int pos[100];

    for (int i = 0; i < n; i++) {
        if (A[i] == x) {
            pos[count] = i+1; 
            count++;
        }
    }

    if (count > 0) {
        cout << x << " is positioned at: ";
        for (int i = 0; i < count; i++) {
            cout << pos[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << x << " not found in the array." << endl;
    }
}

void erase(int A[], int& n, int x) {
    int i = 0; 
    int j = 0; 
    while (i < n) {
        if (A[i] != x) { 
            A[j] = A[i]; 
            j++; 
        }
        i++; 
    }
    n = j; 
}

void display(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[100];
    int n;
    int x;
    readarray(A, n, x);
    search(A, n, x);
    erase(A, n, x);
    display(A, n);
    return 0;
}

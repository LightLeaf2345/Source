#include <iostream>
using namespace std;

// Function to initialize the spiral matrix
void initializeSpiral(int spiral[][100], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            spiral[i][j] = 0; // Set all elements to 0 initially
        }
    }
}

// Function to fill the spiral matrix
void fillSpiral(int spiral[][100], int N, int M) {
    int left = 0, right = M - 1, top = 0, bottom = N - 1;
    int num = 1; // Start filling numbers from 1

    while (left <= right && top <= bottom) {
        // Fill top row
        for (int i = left; i <= right; i++) {
            spiral[top][i] = num++;
        }
        top++;

        // Fill right column
        for (int i = top; i <= bottom; i++) {
            spiral[i][right] = num++;
        }
        right--;

        // Fill bottom row (if applicable)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                spiral[bottom][i] = num++;
            }
            bottom--;
        }

        // Fill left column (if applicable)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                spiral[i][left] = num++;
            }
            left++;
        }
    }
}

// Function to print the spiral matrix
void printSpiral(int spiral[][100], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << spiral[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int spiral[100][100]; // Declare a fixed size array (adjust size as needed)

    initializeSpiral(spiral, N, M);
    fillSpiral(spiral, N, M);
    printSpiral(spiral, N, M);

    return 0;
}

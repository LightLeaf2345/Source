#include <iostream>
#include <algorithm> // For std::find
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int records[100000]; // Assuming n ≤ 100000
    // Initialize the array with records 1 to n
    for (int i = 0; i < n; i++) {
        records[i] = i + 1; // records[0] = 1, records[1] = 2, ..., records[n-1] = n
    }

    // Process the m pull requests
    for (int i = 0; i < m; i++) {
        int disc;
        cin >> disc;

        // Find the index of the disc
        int index = -1; // Initialize index to -1
        for (int j = 0; j < n; j++) {
            if (records[j] == disc) {
                index = j; // Store the index if found
                break;
            }
        }

        if (index != -1) {
            // Shift elements to remove the disc
            for (int j = index; j > 0; j--) {
                records[j] = records[j - 1]; // Shift to the right
            }
            records[0] = disc; // Place the disc at the top
        }
    }

    // Output the final order of the records
    for (int i = 0; i < n; i++) {
        cout << records[i] << " ";
    }
    cout << endl;

    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm> // Include for std::find

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> records(n);
//     // Initialize the stack with records 1 to n
//     for (int i = 0; i < n; i++) {
//         records[i] = i + 1; // records[0] = 1, records[1] = 2, ..., records[n-1] = n
//     }

//     // Process the m pull requests
//     for (int i = 0; i < m; i++) {
//         int disc;
//         cin >> disc;

//         // Find the index of the disc
//         vector<int>::iterator it = find(records.begin(), records.end(), disc); // Use explicit type
//         if (it != records.end()) {
//             // Remove the disc from its current position
//             records.erase(it);
//             // Add the disc back to the top
//             records.insert(records.begin(), disc);
//         }
//     }

//     // Output the final order of the records
//     for (int i = 0; i < n; i++) {
//         cout << records[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

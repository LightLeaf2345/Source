#include "Utility.h"
#include <iostream>

using namespace std;

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    try {
        string postfix = infixToPostfix(infix);
        int result = evaluatePostfix(postfix);

        cout << "Postfix expression: " << postfix << endl;
        cout << "Evaluation result: " << result << endl;
    }
    catch (const std::exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}

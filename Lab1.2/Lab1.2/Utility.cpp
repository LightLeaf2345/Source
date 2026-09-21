#include "Utility.h"
#include <cctype>
#include <stdexcept>
#include <cmath>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For non-operator characters
}

std::string infixToPostfix(const std::string& infix) {
    Stack stack;
    std::string postfix;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            stack.push(ch);
        }
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += ' ';
                postfix += stack.pop();
            }
            stack.pop(); // Remove '('
        }
        else {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += ' ';
                postfix += stack.pop();
            }
            postfix += ' ';
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += ' ';
        postfix += stack.pop();
    }

    return postfix;
}

int evaluatePostfix(const std::string& postfix) {
    Stack stack;
    std::string operand;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            operand += ch;
        }
        else if (ch == ' ') {
            if (!operand.empty()) {
                stack.push(stoi(operand));
                operand.clear();
            }
        }
        else {
            int b = stack.pop();
            int a = stack.pop();
            int result;

            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: throw std::runtime_error("Unknown operator");
            }
            stack.push(result);
        }
    }
    return stack.pop();
}

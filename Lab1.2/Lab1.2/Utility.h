#pragma once
#include <string>
#include "Stack.h"

int precedence(char op);
std::string infixToPostfix(const std::string& infix);
int evaluatePostfix(const std::string& postfix);

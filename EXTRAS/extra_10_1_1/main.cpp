#include <iostream>
#include <stack>
#include <string>
#include "s.h"

bool areBracketsBalanced(const std::string &expr) {
    std::stack<char> bracketStack;

    for (char c : expr) {
        if (c == '(' || c == '[' || c == '{') {
            bracketStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (bracketStack.empty()) {
                return false; // Unbalanced - no matching open bracket
            }

            char topChar = bracketStack.top();
            bracketStack.pop();

            // Check if the current closing bracket matches the popped open bracket
            if ((c == ')' && topChar != '(') ||
                (c == ']' && topChar != '[') ||
                (c == '}' && topChar != '{')) {
                return false; // Mismatched brackets
            }
        }
    }

    return bracketStack.empty(); // Check if there are any unmatched open brackets left
}

int main() {
    // In the main function, applying the real data values
    std::string sent = "(a+...)";

    if (areBracketsBalanced(sent)) {
        std::cout << "Balanced" << std::endl;
    } else {
        std::cout << "Not balanced" << std::endl;
    }

    return 0;
}


//fix this function  jkdsk extra_10_1_3


//write a function to reverse a stack recursively extra_10_1_2(new code)
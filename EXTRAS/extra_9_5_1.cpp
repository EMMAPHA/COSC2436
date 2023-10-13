#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string inputString, reversedString;
    
    cout << "Your name(not the anime): ";
    getline(cin, inputString);
    
    stack<char> charStack;

    // pushes characters onto the stack
    for (char c : inputString) {
        charStack.push(c);
    }

    // pop characters from the stack and append to the reversed string
    while (!charStack.empty()) {
        reversedString += charStack.top();
        charStack.pop();
    }

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}

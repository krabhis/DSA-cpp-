#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s) {
    stack<char> stc;  // Use 'char' as we are working with characters, not 'int'
    
    for (int i = 0; i < s.size(); i++) {
        char a = s[i];  // 'char' should be used to store characters
        
        if (a == '(' || a == '+' || a == '-' || a == '*' || a == '/') {
            stc.push(a);  // Push operators and opening bracket onto the stack
        }
        else if (a == ')') {
            bool isRedundant = true;  // Assume the brackets are redundant

            // Check what's inside the brackets
            while (stc.top() != '(') {
                char top = stc.top();
                stc.pop();

                // If we find an operator inside, the brackets aren't redundant
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    isRedundant = false;
                }
            }

            stc.pop();  // Pop the opening bracket '('

            if (isRedundant) {
                return true;  // Redundant brackets found
            }
        }
    }
    
    return false;  // No redundant brackets found
}

int main() {
    string expr = "(a+b) + ((c))";  // Test case

    if (findRedundantBrackets(expr)) {
        cout << "Redundant brackets found" << endl;
    } else {
        cout << "No redundant brackets found" << endl;
    }

    return 0;
}

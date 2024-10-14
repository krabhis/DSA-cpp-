#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> mainStack;    // Main stack to store elements
    stack<int> minStack;     // Auxiliary stack to store minimum elements

public:
    // Function to push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        // If minStack is empty or the current element is less than or equal to the top of minStack
        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);  // Push it onto the minStack
        }
    }

    // Function to pop the top element
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        // If the top element of mainStack is equal to the top element of minStack
        if (mainStack.top() == minStack.top()) {
            minStack.pop();  // Pop from the minStack as well
        }

        mainStack.pop();  // Pop from the mainStack
    }

    // Function to get the top element
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return mainStack.top();
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return mainStack.empty();
    }

    // Function to get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty, no minimum element" << endl;
            return -1;
        }

        return minStack.top();  // The top of minStack is the minimum element
    }
};

int main() {
    SpecialStack s;
    
    // Push elements onto the stack
    s.push(10);
    s.push(5);
    s.push(20);
    s.push(3);
    s.push(15);

    // Display minimum element
    cout << "Minimum Element: " << s.getMin() << endl;  // Should print 3

    // Pop elements and display minimum after each pop
    s.pop();
    cout << "Minimum Element after pop: " << s.getMin() << endl;  

    s.pop();
    cout << "Minimum Element after pop: " << s.getMin() << endl;  

    s.pop();
    cout << "Minimum Element after pop: " << s.getMin() << endl;  

    return 0;
}

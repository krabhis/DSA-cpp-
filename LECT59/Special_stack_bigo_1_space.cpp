#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
private:
    stack<int> mainStack;   // Main stack to store elements
    int minElement;         // Variable to store the current minimum element

public:
    // Function to push an element into the stack
    void push(int x) {
        // If the stack is empty, simply push the element and set it as the minimum
        if (mainStack.empty()) {
            mainStack.push(x);
            minElement = x;
        } else {
            // If the new element is smaller than the current minimum, we store a modified value
            if (x < minElement) {
                mainStack.push(2 * x - minElement); // Modified value
                minElement = x;  // Update the minimum to the new element
            } else {
                mainStack.push(x);  // Push the element normally
            }
        }
    }

    // Function to pop an element from the stack
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        int topElement = mainStack.top();
        mainStack.pop();

        // If the popped element is less than the current minimum, it means it was a modified value
        if (topElement < minElement) {
            // Restore the previous minimum element
            minElement = 2 * minElement - topElement;
        }
    }

    // Function to return the minimum element in constant time
    int getMin() {
        if (mainStack.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return minElement;
    }

    // Function to return the top element of the stack
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int topElement = mainStack.top();
        // If the top element is less than the current minimum, it means it's a modified value
        if (topElement < minElement) {
            return minElement;  // Return the current minimum element
        } else {
            return topElement;  // Return the actual top element
        }
    }
};

int main() {
    SpecialStack s;
    
    s.push(10);
    s.push(20);
    cout << "Current Min: " << s.getMin() << endl;  // Output: 10
    
    s.push(5);
    cout << "Current Min: " << s.getMin() << endl;  // Output: 5
    
    s.pop();
    cout << "After popping, Current Min: " << s.getMin() << endl;  // Output: 10
    
    s.push(1);
    cout << "Current Min: " << s.getMin() << endl;  // Output: 1
    
    s.pop();
    cout << "After popping, Current Min: " << s.getMin() << endl;  // Output: 10

    return 0;
}

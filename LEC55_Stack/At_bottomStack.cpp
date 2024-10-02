#include <bits/stdc++.h> 
using namespace std;

void solve(stack<int>& myStack, int x) {
    if (myStack.empty()) {
        myStack.push(x);
        return;
    }

    int num = myStack.top();
    myStack.pop();

    solve(myStack, x); 

    myStack.push(num); 

}

int main() {
    stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    int x = 8; 
 
     solve(myStack, x);

    // Print the stack
    cout << "Stack after pushing " << x << " at the bottom: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }

    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>& stc, int size) {
    stack<int> res;
    int mid = (size%2==0)?(size/2)-1:size/2;

    // Pop elements until the middle is reached and push them to the temporary stack
    for (int i = 0; i < mid; i++) {
        int topi = stc.top();
        res.push(topi);
        stc.pop();
    }

    // Remove the middle element
    stc.pop();

    while (!res.empty()) {
        stc.push(res.top());
        res.pop();
    }
}

int main() {
    stack<int> stc;
    
    // Push elements into the stack
    stc.push(1);
    stc.push(2);
    stc.push(3);
    stc.push(4);
    stc.push(5);
    stc.push(6);
    stc.push(7);
    stc.push(8); // Stack: 1 2 3 4 5 6 7 8 (8 is at the top)

    int size = 8;

    // Solve to remove the middle element
    solve(stc, size);

    // Print the remaining elements of the stack after deleting the middle element
    cout << "Stack after deleting the middle element: ";
    while (!stc.empty()) {
        cout << stc.top() << " ";
        stc.pop();
    }

    cout << endl;
    cout << "Love you Zindagi" << endl;
    return 0;
}


///if size of stack is odd then remove the which come first;
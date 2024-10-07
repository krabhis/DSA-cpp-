#include <bits/stdc++.h>
using namespace std;

class TwoStack {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Constructor to initialize the stacks
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push operation for the first stack
    void push1(int data) {
        // Ensure there is space between top1 and top2
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = data;
        } else {
            cout << "Stack Overflow for Stack 1" << endl;
        }
    }

    // Push operation for the second stack
    void push2(int data) {
        // Ensure there is space between top1 and top2
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = data;
        } else {
            cout << "Stack Overflow for Stack 2" << endl;
        }
    }

    // Pop operation for the first stack
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow for Stack 1" << endl;
            return -1;
        }
    }

    // Pop operation for the second stack
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow for Stack 2" << endl;
            return -1;
        }
    }
};

int main() {
    TwoStack ts(5);

    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push2(40);
    ts.push1(50);

    cout << "Popped from Stack 1: " << ts.pop1() << endl; // Output: 50
    cout << "Popped from Stack 2: " << ts.pop2() << endl; // Output: 40

    return 0;
}

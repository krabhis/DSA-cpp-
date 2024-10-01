#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

class Stack {
    Node* top;
    int size; // actual size of the stack

public:
    Stack() {
        top = NULL;
        size = 0;
    }

    // Push
    void push(int value) {
        Node* temp = new Node(value);
        if (temp == NULL) {
            cout << "Stack Overflow\n";
            return;
        } else {
            temp->next = top;
            top = temp;
            size++;
        }
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        } else {
            Node* temp = top;
            cout << "Popped " << top->data << " from the stack\n";
            top = top->next;
            delete temp;
            size--;
        }
    }

    // Peek (get the top element)
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        } else {
            return top->data;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Get the size of the stack
    int getSize() {
        return size;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack s;
    s.push(6);
    s.push(29);
    s.push(23);
    s.pop();
    cout << "Top element is: " << s.peek() << endl;
    cout << "Size of the stack is: " << s.getSize() << endl;

    return 0;
}

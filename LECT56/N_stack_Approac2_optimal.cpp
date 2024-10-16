#include <iostream>
#include <vector>
using namespace std;

class NStack {
private:
    int *arr;       // Array to store actual values
    int *top;       // Array to store index of the top element of each stack
    int *next;      // Array to store the next index for each element (for linked list simulation)
    int free;       // To keep track of the first free index in arr[]
    int total_size; // Total size of the array
    int n;          // Number of stacks

public:
    // Constructor to initialize N stacks in a single array
    NStack(int total_size, int num_stacks) {
        this->total_size = total_size;
        arr = new int[total_size];     // To store the stack elements
        top = new int[num_stacks];     // To store the index of the top elements of each stack
        next = new int[total_size];    // To store the next free or next element index
        n = num_stacks;
        free = 0;  // Initially, the first free index is 0


 for (int i = 0; i < total_size; i++) {
        arr[i] = 0;
    }
        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) {
            top[i] = -1;  // -1 indicates an empty stack
        }

        // Initialize all spaces as free and point next[i] to i+1
        for (int i = 0; i < total_size - 1; i++) {
            next[i] = i + 1;
        }
        next[total_size - 1] = -1;  // -1 indicates the end of free slots
    }

    // Function to push an element onto a given stack
    void push(int stack_num, int value) {
        // Check if there is space available
        if (free == -1) {
            cout << "Stack Overflow in stack " << stack_num + 1 << endl;
            return;
        }

        // Find the first free index
        int i = free;

        // Update the free slot to the next available index
        free = next[i];

        // Insert the value into the array
        arr[i] = value;

        // Update the next array to point to the previous top of this stack
        next[i] = top[stack_num];

        // Update the top of this stack
        top[stack_num] = i;
    }

    // Function to pop an element from a given stack
    int pop(int stack_num) {
        // Check if the stack is empty
        if (top[stack_num] == -1) {
            cout << "Stack Underflow in stack " << stack_num + 1 << endl;
            return -1;
        }

        // Find the top index of the stack
        int i = top[stack_num];

        // Update the top to the next element in this stack
        top[stack_num] = next[i];

        // Add the popped slot to the free list
        next[i] = free;
        free = i;

        // Return the popped element
        return arr[i];
    }

    // Function to display the state of the array and stacks
    void display() {
        cout << "Array: ";
        for (int i = 0; i < total_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Top Indices: ";
        for (int i = 0; i < n; i++) {
            cout << top[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int total_size = 15;   // Total size of the array
    int num_stacks = 3;    // Number of stacks

    NStack stacks(total_size, num_stacks);

    // Pushing elements onto different stacks
    stacks.push(0, 10);  // Push onto stack 1
    stacks.push(0, 20);  // Push onto stack 1
    stacks.push(1, 30);  // Push onto stack 2
    stacks.push(1, 40);  // Push onto stack 2
    stacks.push(2, 50);  // Push onto stack 3
    stacks.push(2, 60);  // Push onto stack 3

    stacks.display();

    // Pop from stack 2
    int popped_value = stacks.pop(1);
    cout << "Popped value from stack 2: " << popped_value << endl;

    stacks.display();

    return 0;
}

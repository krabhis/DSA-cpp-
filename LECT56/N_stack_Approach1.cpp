#include <bits/stdc++.h>

using namespace std;


class Nstack{
    private:

    int *arr;
    int *top;
    int stack_size;
    int n;

    public:
    Nstack(int total_size, int num_stacks){
        arr=new int[total_size];
        top=new int[num_stacks];
        stack_size=total_size/num_stacks;
        n=num_stacks;
// Initialize all elements of the arr array to 0
    for (int i = 0; i < total_size; i++) {
        arr[i] = 0;
    }
//initializes all the top indices to -1 , meaning stacks are empty
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
    }
//function to push an element onto the given stack
    void push(int stack_num , int value){
        int stack_start=stack_num * stack_size;//starting index of stack
        int stack_end=(stack_num+1)*stack_size-1;//Ending index of this stack

        //check if the stack is full
        if(top[stack_num]>=stack_end){
            cout<<"Stack overflow in stack"<<stack_num+1<<endl;
            return;
        }

        //incremennt the top index for the stack amd insert the value
        if(top[stack_num]==-1){
            top[stack_num]=stack_start;
        }
        else {
            top[stack_num]++;
        }
        arr[top[stack_num]] = value;

    }

        // Function to pop an element from the given stack
    int pop(int stack_num) {
        if (top[stack_num] == -1) {
            cout << "Stack Underflow in stack " << stack_num + 1 << endl;
            return -1;   // Return -1 to indicate underflow
        }

        // Get the top value
        int value = arr[top[stack_num]];

        // Decrement the top index for the stack
        if (top[stack_num] == stack_num * stack_size) {
            top[stack_num] = -1;   // Stack is now empty
        } else {
            top[stack_num]--;
        }

        return value;
    }

  // Function to display the current state of the array for each stack
    void display() {
        cout << "Array: ";
        for (int i = 0; i < n * stack_size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {

    int total_size=15;//total size of the array
    int num_stacks=3;//number of stack

    Nstack stacks(total_size, num_stacks);
    // Pushing elements onto different stacks
    stacks.push(0, 10);  // Push onto stack 1
    stacks.push(0, 20);  // Push onto stack 1
    stacks.push(1, 30);  // Push onto stack 2
    stacks.push(1, 40);  // Push onto stack 2
    stacks.push(2, 50);  // Push onto stack 3

    stacks.display();

    // Pop from stack 2
    int popped_value = stacks.pop(1);
    cout << "Popped value from stack 2: " << popped_value << endl;

    stacks.display();

    return 0;









    cout << "Love you Zindagi" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        size = 100001;   // Initialize size first
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue function to add an element to the queue
    bool enqueue(int data) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return false;
        } 
        else if (front == -1) { // First element insertion
            front = rear = 0;
            arr[rear] = data;
        } 
        else if (rear == size - 1 && front != 0) { // Wrap around
            rear = 0;
            arr[rear] = data;
        } 
        else { // Normal case
            rear++;
            arr[rear] = data;
        }
        return true;
    }

    // Dequeue function to remove an element from the queue
    int dequeue() {
        if (front == -1) { // Queue is empty
            cout << "Queue is empty" << endl;
            return -1;
        }

        int data = arr[front];
        arr[front] = -1;

        if (front == rear) { // Queue has only one element
            front = rear = -1;
        } 
        else if (front == size - 1) { // Wrap around
            front = 0;
        } 
        else { // Normal case
            front++;
        }
        return data;
    }

    // Function to display the front element of the queue
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Function to display the rear element of the queue
    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    CircularQueue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl;

    return 0;
}

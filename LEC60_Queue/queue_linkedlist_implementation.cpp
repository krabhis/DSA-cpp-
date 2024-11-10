#include <bits/stdc++.h>
using namespace std;

class Node {
public:  
    int data;
    Node* next;
    
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

class Queue {
    Node *front, *rear;

public:
    Queue(){
        front=nullptr;
        rear=nullptr;

    } 

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue an element to the rear of the queue
    void enqueue(int new_data) {
        Node* new_node = new Node(new_data);

        if (isEmpty()) {
            front = rear = new_node;
            return;
        }

        rear->next = new_node;
        rear = new_node;
    }

    // Dequeue an element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Get the front element of the queue
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return front->data;
    }

    // Get the rear element of the queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return rear->data;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);


    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.dequeue();
    cout << "Front element after dequeue: " << q.getFront() << endl;

    return 0;
}

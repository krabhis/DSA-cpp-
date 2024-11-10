#include <bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;
    
public:
    Queue() {
        size = 100000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    
    bool isEmpty() {
        return qfront == rear;
    }
    
    void enQueue(int data) {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int deQueue() {
        if (qfront == rear) {
            return -1;
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;
        } else {
            return arr[qfront];
        }
    }
    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue elements: ";
            for (int i = qfront; i < rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue obj;
    obj.enQueue(10);
    obj.enQueue(11);
    obj.enQueue(12);
    obj.enQueue(13);
    obj.deQueue();

    obj.display();

    cout << "Love you Zindagi" << endl;
    return 0;
}

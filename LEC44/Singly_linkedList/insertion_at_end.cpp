#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, int d) {
    // Create a new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int d){
        // Create a new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail ->next;//isse tail ko hum last cvale node pe point kra denge initially ek hi node  to tail head ko hi point karega
}



void print(Node* head) {
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
// craeted a new node
    Node* node1=new Node(10);
    // cout << node1 ->data << endl;
    // cout << node1 -> next <<endl;

    //head pointed to node
    Node* head =node1;

    Node* tail =node1;

    print(head);

    insertAtTail(tail, 12);

    print(head);
    
    return 0;
}

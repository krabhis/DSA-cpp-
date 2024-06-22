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
    //u can write temp to new_node for understanding
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
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

    print(head);

    // insertAtHead(head, 12);

    // print(head);
    
    return 0;
}

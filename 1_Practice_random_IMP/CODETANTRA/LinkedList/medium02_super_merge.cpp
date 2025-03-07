#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    void insert(int val) {
        if (!head) {
            head = new Node(val);
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }

    void display()  {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int n, k;

    cout << "Enter the size of the array (n): ";
    cin >> n;

    cout << "Enter the number of linked lists (k): ";
    cin >> k;

    if (k > n) {
        cout << "Error: Number of linked lists (k) cannot exceed array size (n)." << endl;
        return 1;
    }

    // Array of LinkedList objects
    vector<LinkedList> linkedLists(n);

    // Input for k linked lists
    for (int i = 0; i < k; i++) {
        int numNodes;
        cout << "Enter the number of nodes in linked list " << i + 1 << ": ";
        cin >> numNodes;

        for (int j = 0; j < numNodes; j++) {
            int val;
            cout << "Enter value for node " << j + 1 << ": ";
            cin >> val;
            linkedLists[i].insert(val);
        }
    }

    // Display all linked lists
    cout << "\nDisplaying all linked lists:" << endl;
    for (int i = 0; i < k; i++) {
        cout << "Linked list " << i + 1 << ": ";
        linkedLists[i].display();
    }

    return 0;
}

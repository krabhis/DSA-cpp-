#include <bits/stdc++.h>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert a new node at the end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node* result = nullptr;
    if (l1->data < l2->data) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    } 
    else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }
    return result;
}

Node* mergeKLists(vector<LinkedList>& lists, int start, int end) {
    if (start == end) {
        return lists[start].head;
    }
    if (start < end) {
        int mid = start + (end - start) / 2;
        Node* left = mergeKLists(lists, start, mid);
        Node* right = mergeKLists(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
    return nullptr;
}

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

    vector<LinkedList> linkedLists(k);

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
        linkedLists[i].printList();
    }

    // Merge k linked lists
    Node* mergedHead = mergeKLists(linkedLists, 0, k - 1);

    // Display merged linked list
    cout << "\nMerged linked list:" << endl;
    Node* temp = mergedHead;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}

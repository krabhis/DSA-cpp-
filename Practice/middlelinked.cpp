#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
      Node(int x) {
        data = x;
          next = NULL;
    }
};

// Function to add a new node in the beginning of the linked
// list
void pushNode(class Node** head_ref, int data_val)
{

    // Allocate node
    class Node* new_node = new Node(data_val);

    // Link the old list of the new node
    new_node->next = *head_ref;

    // move the head to point to the new node
    *head_ref = new_node;
}

int getMiddle(Node* head)
{
    // vector to store the values of all nodes
    vector<int> v;
    // Traverse through the entire linked list and push all
    // the values into the vector
    while (head != NULL) {
        v.push_back(head->data);
        head = head->next;
    }
    // Find the middle index
    int middleIdx = v.size() / 2;
    // Return the value stored at the middle index
    return v[middleIdx];
}

int main()
{
    Node* head = NULL;
    for (int i = 5; i > 0; i--) {
        pushNode(&head, i);
    }

    cout << "Middle Value Of Linked List is: "
         << getMiddle(head) << endl;
    return 0;
}
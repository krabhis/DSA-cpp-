/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

******************************************/

Node* floydDetectionLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;  
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

  
        if (slow == fast) {
            return slow;  // Returning the meeting point
        }
    }

    return nullptr;  // No loop found
}


Node* startingNode(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* intersectNode = floydDetectionLoop(head);

    // If there's no loop, return nullptr
    if (intersectNode == nullptr) {
        return nullptr;
    }

    Node* slow = head;

    while (slow != intersectNode) {
        slow = slow->next;
        intersectNode = intersectNode->next;
    }

    return slow;
}

// Function to remove the loop in the linked list
Node* removeLoop(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    Node* startOfLoop = startingNode(head);

    if (startOfLoop == nullptr) {
        return head;
    }

    Node* temp = startOfLoop;

    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = nullptr; 

    return head;
}

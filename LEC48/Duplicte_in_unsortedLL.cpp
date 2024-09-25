lass Solution {
  public:
    Node *removeDuplicates(Node *head) {
        set<int> seti;
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {
            if (seti.find(temp->data) != seti.end()) {
                prev->next = temp->next;  // Skip the current node
                Node* toDelete = temp;
                temp = temp->next;        // Move to the next node
                delete(toDelete);         // Delete the duplicate node
            }
            else {
                seti.insert(temp->data);   // Insert the current node's data into the set
                prev = temp;               // Move prev to the current node
                temp = temp->next;         // Move to the next node
            }
        }
        return head;
    }
};
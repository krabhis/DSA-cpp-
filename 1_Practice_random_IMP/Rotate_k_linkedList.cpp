#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateLeft(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head; 
        }

        // Calculate the length of the linked list
        ListNode* temp = head;
        int length = 1;
        while (temp->next != NULL) {
            length++;
            temp = temp->next;
        }

        k = k % length;
        if (k == 0) {
            return head;  
        }

        // Connect the last node to the head to make it circular
        temp->next = head;

        ListNode* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = NULL;

        return newHead;
    }

    void printList(ListNode* head) {
        while (head != NULL) {
            cout << head->val << " -> ";
            head = head->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    cout << "Original List: ";
    sol.printList(head);

    int k = 2;  

    ListNode* newHead = sol.rotateLeft(head, k);

    cout << "Rotated List (left by " << k << " positions): ";
    sol.printList(newHead);

    return 0;
}

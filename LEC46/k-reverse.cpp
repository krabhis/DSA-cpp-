/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(head==NULL){
            return NULL;
        }

     ListNode* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL) {
            return head;
        }
        temp = temp->next;
    }
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* forward=NULL;

        int count=0;

        while(curr!=0 && count<k){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL){
            head->next=reverseKGroup(forward,k);
        }

        return prev;
    }
};
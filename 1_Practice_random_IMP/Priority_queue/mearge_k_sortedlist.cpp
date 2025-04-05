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
class NodeData {
    public:
        int value;
        ListNode* node;
        int listindex;
        NodeData(ListNode* node, int listindex) {
            this->node = node;
            this->value = node->val;
            this->listindex = listindex;
        }
    };
    
    class compare {
    public:
        bool operator()(NodeData& a, NodeData& b) { return a.value > b.value; }
    };
    class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int k = lists.size();
            if (k == 0)
                return nullptr;
            priority_queue<NodeData, vector<NodeData>, compare> pq;
            for (int i = 0; i < k; i++) {
                if (lists[i] != nullptr)
                    pq.push(NodeData(lists[i], i));
            }
            ListNode* dummy = new ListNode(0);
            ListNode* tail = dummy;
            while (!pq.empty()) {
                NodeData curr = pq.top();
                pq.pop();
                tail->next = curr.node;
                tail = tail->next;
                if (curr.node->next != nullptr)
                    pq.push(NodeData(curr.node->next, curr.listindex));
            }
            return dummy->next;
        }
    };
    
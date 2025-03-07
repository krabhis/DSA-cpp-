#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTiterator {
    stack<TreeNode*> mystack;
    bool reverse; // true for reverse iterator, false for normal
    
public:
    BSTiterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !mystack.empty();
    }

    int next() {
        TreeNode* tmpNode = mystack.top();
        mystack.pop();
        
        if (!reverse) 
            pushAll(tmpNode->right); // Normal iterator (In-order)
        else 
            pushAll(tmpNode->left);  // Reverse iterator (Reverse In-order)
        
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node) {
            mystack.push(node);
            if (reverse) 
                node = node->right;  // Move right for reverse iterator
            else 
                node = node->left;   // Move left for normal iterator
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTiterator l(root, false); // Left iterator (In-order)
        BSTiterator r(root, true);  // Right iterator (Reverse In-order)

        int i = l.next();  // Smallest element
        int j = r.next();  // Largest element

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) 
                i = l.next();  // Move left iterator forward
            else 
                j = r.next();  // Move right iterator backward
        }

        return false;
    }
};

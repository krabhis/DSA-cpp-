class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
 
    // Inorder traversal to detect swapped nodes
    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);

        // If current node is smaller than previous node, it's a misplaced node
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;  // First adjacent swap case
            } else {
                last = root;  // Second misplaced node
            }
        }
        
        prev = root;  // Update previous node
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); // Initialize prev with a very small value

        // Step 1: Find the misplaced nodes
        inorder(root);

        // Step 2: Fix the swapped nodes
        if (first && last) {
            swap(first->val, last->val);  // Non-adjacent swap case
        } else if (first && middle) {
            swap(first->val, middle->val);  // Adjacent swap case
        }
    }
};

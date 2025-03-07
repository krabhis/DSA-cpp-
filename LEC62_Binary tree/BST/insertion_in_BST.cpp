class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        TreeNode* temp = root;
        
        while (true) {
            if (val < temp->val) {
                if (temp->left == NULL) {
                    temp->left = new TreeNode(val);
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = new TreeNode(val);
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }
        return root;
    }
};

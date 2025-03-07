/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        unordered_map<int,int> postIndex; // map value to index in postorder
    
        TreeNode* solve(int preStart, int preEnd, int postStart, int postEnd, vector<int>& preorder, vector<int>& postorder) {
            if(preStart > preEnd) return nullptr;
            TreeNode* root = new TreeNode(preorder[preStart]);
            if(preStart == preEnd) return root;
            
            // The next value in preorder is the root of left subtree.
            int leftRootVal = preorder[preStart+1];
            int idx = postIndex[leftRootVal];
            int leftSize = idx - postStart + 1;
            
            root->left = solve(preStart+1, preStart+leftSize, postStart, idx, preorder, postorder);
            root->right = solve(preStart+leftSize+1, preEnd, idx+1, postEnd-1, preorder, postorder);
            return root;
        }
        
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            for (int i = 0; i < n; i++){
                postIndex[postorder[i]] = i;
            }
            return solve(0, n-1, 0, n-1, preorder, postorder);
        }
    };
    
#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> stk;

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    bool hasNext() {
        return !stk.empty();
    }

    int before() {
        TreeNode* tmpNode = stk.top();
        stk.pop();
        pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            stk.push(node);
            node = node->right;
        }
    }
};

class Solution {
public:
    void run() {
        TreeNode* root = new TreeNode(7);
        root->left = new TreeNode(3);
        root->right = new TreeNode(15);
        root->right->left = new TreeNode(9);
        root->right->right = new TreeNode(20);

        BSTIterator it(root);
        while (it.hasNext()) {
            cout << it.before() << " ";
        }
    }
};

int main() {
    Solution s;
    s.run();
    return 0;
}

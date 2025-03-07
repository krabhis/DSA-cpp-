#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Helper function to build the tree recursively
Node* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd) {
        return nullptr;
    }

    // Get the current root node value from postorder
    int curr = postorder[postIndex--];
    Node* node = new Node(curr);

    // If this node has no children, return it
    if (inStart == inEnd) {
        return node;
    }

    // Get the index of this node in inorder to divide left and right subtrees
    int inIndex = inorderMap[curr];

    // Build right and left subtrees
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex, inorderMap);
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex, inorderMap);

    return node;
}

// Function to create a binary tree from inorder and postorder traversals
Node* solve(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    int postIndex = n - 1; // Last index in postorder is the root node

    // Create a map to store the index of each element in inorder for quick lookup
    unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; i++) {
        inorderMap[inorder[i]] = i;
    }

    // Build the tree recursively
    return buildTree(inorder, postorder, 0, n - 1, postIndex, inorderMap);
}

// Helper function to print the tree in level order
void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};

    Node* root = solve(inorder, postorder);

    cout << "Level Order Traversal: ";
    levelOrder(root);
    cout << endl;

    return 0;
}

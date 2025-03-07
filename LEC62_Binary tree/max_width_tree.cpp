#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) { // Constructor should be public
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to build a binary tree
Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) { // -1 indicates NULL node
        return nullptr;
    }

    Node* root = new Node(val);
    cout << "Enter data for root->left of " << val << ": ";
    root->left = buildTree(); // Recursively build left subtree

    cout << "Enter data for root->right of " << val << ": ";
    root->right = buildTree(); // Recursively build right subtree

    return root;
}

// Function for level order traversal
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* temp = q.front();
            q.pop();

            cout << temp->val << " ";

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

// Function to find the maximum width of the binary tree
int widthOfBinaryTree(Node* root) {
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<Node*, long long>> q;
    q.push({root, 0}); // Pair of node and index

    while (!q.empty()) {
        int size = q.size();
        long long first, last;
        long long mini = q.front().second; // Min index at this level

        for (int i = 0; i < size; i++) {
            long long curr_id = q.front().second - mini; // Normalize index
            Node* node = q.front().first;
            q.pop();

            if (i == 0)
                first = curr_id; // First index at this level
            if (i == size - 1)
                last = curr_id; // Last index at this level
            
            if (node->left) {
                q.push({node->left, 2 * curr_id + 1});
            }
            if (node->right) {
                q.push({node->right, 2 * curr_id + 2});
            }
        }
        ans = max(ans, (last - first + 1));
    }
    return ans;
}

int main() {
    cout << "Enter tree nodes in level order (-1 for NULL):" << endl;
    Node* root = buildTree();

    cout << "\nLevel Order Traversal:" << endl;
    levelOrder(root);

    int ans = widthOfBinaryTree(root);
    cout << "\nMaximum Width of Tree: " << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new node(data);

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level

        for (int i = 0; i < levelSize; i++) {
            node* temp = q.front();
            q.pop();

            cout << temp->data << " "; // Print current node

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }

        cout << endl; // Move to the next level
    }
}


int main() {
    node* root = NULL;

    // Building the tree
    root = buildTree(root);
    
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // Performing level order traversal
    // cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    return 0;
}



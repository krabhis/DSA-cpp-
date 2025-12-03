class bst_iterator{
    stack<TreeNode*> myStack;
    public:
    bst_iterator(TreeNode* root){
        pushAll(root);
    }
    bool hasNext(){
        return !mystack.empty();
    }
    int next(){
        TreeNode* tmpNode=mystack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->val;
    }

    private:
    void pushAll(TreeNode* node){
        while (node != NULL) {
            myStack.push(node);
            node = node->left;
        }
    }
            
};




// Using bst_iterator

// Time Complexity (constructor): O(h) → h = height of tree

// Time Complexity (next()): Amortized O(1) (over all operations it's O(n))

// Space Complexity: O(h) → stack only contains the path to current node

////////////////////////////////////////////

// Using normal inorder and storing on vector the nodes and the finding next ...

// Time Complexity (constructor): O(n) → full traversal of tree

// Time Complexity (next() / hasNext()): O(1)

// Space Complexity: O(n) → all nodes stored in a vector
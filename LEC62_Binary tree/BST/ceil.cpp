int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    // Your code here
    int ceil=-1;
    while(root){
        if(root->data==input){
            ceil=root->data;
            return ceil;
        }
        else if(root->data>input){
            ceil=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;
}
vector<int>getinorder(TreeNode* root){
    vector<int>inorder;
    TreeNode* cur=root;
    while(curr!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode *prev=cur->left;
            while(prev->right && prev->right !=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                inorder.push_back(cur.val);
                cur=cur->right;
            }
        }

    }
    return inorder;

}

vector<int>getpreorder(TreeNode* root){
    vector<int>inorder;
    TreeNode* cur=root;
    while(curr!=NULL){
        if(cur->left==NULL){
            inorder.push_back(cur->val);
            cur=cur->right;
        }
        else{
            TreeNode *prev=cur->left;
            while(prev->right && prev->right !=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                preorder.push_back(cur.val);

                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cur=cur->right;
            }
        }

    }
    return inorder;

}


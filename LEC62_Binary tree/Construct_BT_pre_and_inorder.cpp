class Solution {
    public:
    TreeNode* builtTree(vector<int>&preorder,vector<int>inorder){
        map<int , itn>mapi;
        for(int i=0;i<inorder.size();i++){
            mapi[inorder[i]]==i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,
                                 inorder,0,inorder.size()-1,mapi);
                                 return root;
    } 

    TreeNode* buildTree(vector<int>&preorder,int preStart, int preEnd,
                          vector<int>&inorder, int inStart, int inEnd , map<int , int>mapi){


                    if(preorder>preEnd||inStart>inEnd) return NULL;
                    TreeNode* root=new TreeNode(preorder[preStart]);

                    int inRoot= mapi[root->val];
                    int numsleft=inRoot-inStart;
                    root->left=buildTree(preorder,preStart+1,prestart+numsLeft,inorder, inStart,inRoot-1, mapi);
                    root->right=buildTree(preorder, preStart+numsLeft+1,preEnd,inorder, inRoot+1, inEnd, mapi);


                    return root;        
                          }
}
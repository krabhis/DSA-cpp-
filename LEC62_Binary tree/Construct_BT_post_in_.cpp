class Solution{
    TreeNode*  buildTree(vector<int>&inorder,vector<int>&postorder){
        if(inorder.size()!=postorder.size())
        return NULL;

        map<int,int>mapi;
        for(int i=0;i<inorder.size();i++){
            mapi[inorder[i]]=i;
            return buildTreePostIN(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mapi);
        }

    }
    TreeNode* buildTreepostIn(vector<int>&inorder, int is, int ie, vector<int>&postorder,int ps, int pe, map<int,int>&mapi){
        if(ps>pe||is>ie) return NULL;

        TreeNode* root=new TreeNode(postorder[pe]);

        int inRoot=mapi[postorder[pe]];
        int numsLeft=inRoot-is;//inorder vale array ka left part ka length

        root->left=buildTreepostIn(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,mapi);
        root->right=buildTreepostIn(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,mapi);

        return root;

    }
};
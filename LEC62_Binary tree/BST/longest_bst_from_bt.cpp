class NodeValue{
    public:
    int len, mini, maxa;

    NodeValue(int len, int mini, int maxa){
        len=len;
        mini=mini;
        maxa=maxa;
        
    }
};

class Solution{
    private:
    NodeValue largestBST(Node* root){
        if(!root) return NodeValue(0,INT_MAX,INT_MIN);
    }
    NodeValue left=solve(root->left);
    NodeValue right=solve(root->right);
    if((root->data>left.maxi)&&(root->data<right.mini)){
        return NodeValue(1+left.len+right.len,min(left.mini,root->data),max(right.maxi,root->data));

    }
    return NodeValue(max(left.len,right.len),INT_MIN,INT_MAX);
}


int largestBST(Node* root){
    NodeValue n=solve(root);
    return n.len;
}
//decode the string obtained for serialization of binarytree

TreeNode* deserialize(string data){
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root=new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();

        getline(s,str,',');

        if(str=="#"){
            node->left=NULL;

        }
        else{
            TreeNode* leftNode=new TreeNode(stoi(str));
            node->left=leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right=NULL;
        }
        else{
            TreeNode* rightNode=new TreeNode(stoi(str));
            node->right=rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

//Serialize the given bianry tree 

string serialize(TreeNode* root){
    if(!root) return " ";

    string s=" ";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* currNode=q.front();
        q.pop();
        if(currNode==NULL) s.append('#',"");
        else s.append(to_string(curr->Node->val)+',');
        
        if(currNode!=NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
        
return s;


    }
}
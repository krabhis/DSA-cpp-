#include <bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};

Node* buildTree(Node* root){
    int data ;
    cout<<"Enter data"<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    cout<<"Enter the left of root"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the right of root "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelorderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            cout<<temp->data;
            q.push(root->left);
            q.push(root->right);

        }
        cout<<endl;
    }
}


int main() {
    Node* root=NULL;
    root=buildTree(root);
    // levelorderTraversal(root);



    return 0;
}
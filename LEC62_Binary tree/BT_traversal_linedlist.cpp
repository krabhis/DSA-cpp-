#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*  left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }
};

node*  buildbt(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in the left"<<endl;
    root->left=buildbt(root->left);
    cout<<"Enter the data for inserting in the right"<<endl;
    root->right=buildbt(root->right);
    return root;
}

void levelOrdertraversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

int main(){
    node*  root=NULL;//initially null hai...
    root = buildbt(root);
    levelOrdertraversal(root);

return 0;
}

//ex: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
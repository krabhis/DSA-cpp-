#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
int findMaxDistance(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mpp,BinaryTreeNode<int>* target){
    queue<BinaryTreeNode<int>*>q;
    q.push(target);
    map<BinaryTreeNode<int>*,int>visited;
    visited[target]=1;
    int maxi=0;
    while(!q.empty()){
        int size=q.size();
        int flag=0;
        for(int i=0;i<size;i++){
            auto node=q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                flag=1;
                visited[node->left]=1;
                q.push(node->left);
            }
             if(node->right && !visited[node->right]){
                flag=1;
                visited[node->right]=1;
                q.push(node->right);
            }
            if(mpp[node]&& !visited[mpp[node]]){
                flag=1;
                visited[mpp[node]]=1;
                q.push(mpp[node]);
            }
        }
        if(flag) maxi++;

    }
    return maxi;
}
   
    BinaryTreeNode<int>* bfsToMapParents(BinaryTreeNode<int>*root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&mpp,int start){
        queue<BinaryTreeNode<int>*>q;
        q.push(root);
        BinaryTreeNode<int>* res;
        while(!q.empty()){
            BinaryTreeNode<int>* node=q.front();
            if((node->data)==start){
                res=node;
            }
            q.pop();
            if(node->left){
                mpp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);
            }
        }
        return res;

    }
     public:
     int timeToburnTree(BinaryTreeNode<int>* root, int start){
        map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>mpp;
        BinaryTreeNode<int>* target=bfsToMapParents(root,mpp,start);//returns the address of start .mpp me parents ko store kr rha hai
        int maxi=findMaxDistance(mpp,target);
        return max;
     }

};
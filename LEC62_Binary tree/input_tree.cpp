#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *creation(Node *root)
{
    cout << "enter the data" << endl;
    int d;
    cin >> d;
    root = new Node(d);
    if (d == -1)
    {
        return NULL;
    }
    cout << "left data of -> " << d << endl;
    root->left = creation(root->left);
    cout << "right data of -> " << d << endl;
    root->right = creation(root->right);
    return root;
}

void level(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        while(n--) {
            auto p=q.front();
            q.pop();
            cout<<p->data<<" ";
            if(p->left!=NULL) q.push(p->left); 
            if(p->right!=NULL) q.push(p->right); 
        }
        cout<<endl;
    }
}
void solve(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    swap(root->left, root->right);
    solve(root->left);
    solve(root->right);
}
int main()
{
    Node *root = NULL;
    root = creation(root);
    level(root);
    cout << "After operation of the tree is : " << endl;
    solve(root);
    level(root);
    return 0;
}
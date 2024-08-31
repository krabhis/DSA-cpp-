/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    Node* curr=head;
    int count =0;
    while(curr!=NULL){
        count++;
    }
       int ans=count/2;
        Node* temp=head;
        int cnt=0;

       while(cnt<ans){
           temp=temp->next;
           cnt++;

       }
       return temp;   
}

// Node *findMiddle(Node *head) {
//     Node* fast=head;
//     Node* slow=head;





    
// }


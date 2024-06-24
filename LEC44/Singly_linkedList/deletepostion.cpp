#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
//constructor
     Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
//destructor

~Node(){
    int value=this->data;
    //memory free

    if(this->next !=NULL){
        delete next;
        this ->next=NULL;
    }
    cout<<"Memory is free for node with data"<< value <<endl;

}

};

void insertionAtHead(Node* &head , int d){

    Node* new_node= new Node(d);
    new_node->next=head;
    head=new_node;

}
void insertionAtend(Node* &tail,int d){
    Node* new_node= new Node(d);
    tail->next=new_node;
    tail=tail->next;




}

void insertAtposition(Node* &tail, Node* &head , int position ,int d){
    if (position ==1){
        insertionAtHead(head,d);
        return;

    }

    Node* temp=head;
    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertionAtend(tail,d);
        return;
    }

    //creating node for d
    Node* nodeToInsert=new Node(d);

    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

  void  deleteNode(int position,Node*&head){

    //deleting first or start node

    if(position==1){
        Node*temp=head;
        head=head->next;

        //memory free start node
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node* curr= head;
        Node *prev= NULL;

        int cnt=1;
        while(cnt<=position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }

        prev->next=curr -> next;
        curr->next=NULL;
        delete curr;
    }


    }



void print(Node* head){

    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout << endl;
}

int main() {

    Node* node1=new Node(5);

    Node* head =node1;

    Node* tail=node1;
    print(head);

    insertionAtend(tail,45);
    print(head);

    insertionAtend(tail,50);
    print(head);

    deleteNode(1,head);
    print(head);



    return 0;
}
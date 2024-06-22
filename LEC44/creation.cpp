/*
In C++, when you declare a pointer, the type before the * indicates what kind of data the pointer is pointing to. In the case of a linked list node, the next pointer needs to point to another node of the same type. Therefore, the type before the * is the class name Node
*/




#include <iostream>

using namespace std;


class Node {
    public:
    int data;
    Node* next;


    Node(int data){
        this -> data = data;
        this ->next = NULL;
    }
};

int main() {
 
    Node* node1 = new Node(10);
    cout << node1 ->data << endl;
    cout << node1 -> next << endl;

    return 0;
}
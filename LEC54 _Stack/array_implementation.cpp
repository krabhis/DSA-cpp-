#include<iostream>
using namespace std;

class  Stack{
    //properties
    public:

    int *arr;
    int size;
    int top;

    //behaviour
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;

    }

    void push(int element){
        if(size - top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    
    void pop(){
        if(top>0){
            top--;

        }
        else{
            cout<<"Stack is underflow"<<endl;
        }
    }
    
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }
    isEmpty(){
        if(top==-1){
            return true;
        }
        else{

            return false;


        }
    }

};

int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(9);
    st.push(8);
    st.push(28);

    st.pop();
        cout << st.peek() << endl;


}




string s="25";
int a=s*5;
cout<<a;
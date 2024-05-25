#include<iostream>
using namespace std;



int main(){

    char ch='r';
    cout<<sizeof(ch)<<endl;

    char* c=&ch;
    cout<<sizeof(c)<<endl;



}

// In this size of pointer is 4 bit but in most of cases in in of 8 byte.

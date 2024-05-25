#include<iostream>
using namespace std;


int * fun(int n){
    int*ptr=&n;
    return ptr;
}

int main(){
    int n=5;
    fun(n);

}


// same problem which occurs in return referance
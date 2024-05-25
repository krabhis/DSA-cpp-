#include<iostream>
using namespace std;



int & func(int a){
    int num=a;
    int & ans=num;
    return ans;


}

int main(){
    int n=5;

    func(n);
    

}

/*
In the func function, you're returning a reference to a local variable num. When func exits, num goes out of scope and is destroyed. As a result, the reference returned by func becomes a dangling reference, pointing to memory that is no longer valid.

Attempting to use this dangling reference, as you do in main, leads to undefined behavior, typically manifesting as a runtime error or unexpected behavior.

To fix this issue, you should not return a reference to a local variable that goes out of scope. Instead, you might consider returning a reference to a variable with a broader scope or passing the variable by reference into the function, allowing the caller to manage its lifetime.
*/
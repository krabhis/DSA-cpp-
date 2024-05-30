#include<iostream>
using namespace std;

int calSquare(int a, int b){
    if (b==0)
    {
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans=calSquare(a,b/2);

    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
    

}

int main(){
    int a=2;
    int b=10;
    int c=calSquare(2,10);
    cout<<"a to the the power b is equal to-->"<<c;


}
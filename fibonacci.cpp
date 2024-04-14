#include<iostream>
using namespace std;
 int main(){

    // 0,1,1,2,3,5,8....
    int a=0,b=1,i,n,c;
    cout<<"Enter the number"<<endl;
    cin>>n;
    cout<<a<<b;

    if(n>0){
          for(i=0;i<n;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<c;

    }
    }
    else{
        cout<<"sequence not possible";
    }
  
 }


#include<iostream>
using namespace std;
/*
for example k=3  ----- 000,010,001,100,101 
 k=2 00,01,10

 k is integer number i.e no of digit;



*/

void utilfunction(int k , char str[] , int n){

    if(n==k){
        str[n]='\0';
        cout<<str << " ";
        return ;
    }
// condition for  prev bit or n-1 is 1;
    if(str[n-1]=='1'){
        str[n]='0';
        utilfunction(k,str,n+1);

    }

    //conditon for prev bit  or n-1 is 0;
    if(str[n-1]=='0'){
        str[n]='0';
        utilfunction(k,str,n+1);
        str[n]='1';
        utilfunction(k,str,n+1);


    }



}

void generateAllString(int k){

    if(k<=0) return ;

    char str[k+1];

// case :1 starts with zero;
    str[0]='0';
    utilfunction(k, str, 1);

//  case 2: starts with one;
   str[0]='1';
    utilfunction(k, str, 1);

}

int main(){

    int k=3;
    generateAllString(k);
    return 0;


}
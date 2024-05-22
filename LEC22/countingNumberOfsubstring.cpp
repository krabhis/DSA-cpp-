#include<iostream>
using namespace std;

#include<string>

bool isPalindrome(string ss){
    int n=ss.size();
    int s=0,e=n-1;
    while(s<=e){
        if(ss[s++]!=ss[e--])
        return false;
    }
    return true;
}

int palindromicSubstrings(string input){
    int n=input.size(),count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isPalindrome(input.substr(i,j-i+1))){
                count ++;
            }
        }
    }
    return count;
}
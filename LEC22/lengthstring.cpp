#include<iostream>
using namespace std;

int length(char arr[]){
    int count=0;
    for(int i=0;arr[i]!='\0';i++){
        count++;

    }


return count;
  
}


int main(){
    char str[50];
    cout<<"Enter the strings "<<endl;
    cin>>str;
    cout<<"Length of string"<<length(str);



}
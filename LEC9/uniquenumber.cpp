#include<iostream>
using namespace std;

bool uniqueElement(int a[],int size){
        int ans=0;
         for(int i=0;i<size;i++){
        ans=ans^a[i];
        }
        if(ans==0){
            return true;
        
        }
        
            return false;
        
}

int main(){
    int arr[50]={2,2,2,2,2,2,3,3,4,5,5,5,5};
    uniqueElement(arr,13);

}
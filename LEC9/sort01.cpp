#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


void sortOne(int ar[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(ar[i]==1 && ar[j]==0 &&i<j){
                swap(ar[i],ar[j]);
            }

        }
    }



}

int main(){
    int arr[9]={1,1,0,0,0,0,1,1,0};
    sortOne(arr,9);
    printArray(arr,9);

}
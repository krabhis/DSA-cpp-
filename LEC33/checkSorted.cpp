#include<iostream>
using namespace std;
// use arr[] of *arr
bool isSorted(int arr[],int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool remainingPart=isSorted(arr+1,size-1);
        return remainingPart;
    }
    

}

int main(){
    int arr[9]={1,2,3,4,4,5,42,50,63};
    int size=9;

    bool ans=isSorted(arr,size);
    if(ans){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted";
    }
}
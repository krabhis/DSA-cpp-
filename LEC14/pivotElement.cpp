#include<iostream>
using namespace std;
int pivotElement(int arr[],int size){
    int s=0,e=size-1;
    int mid=s+((e-s)/2);
    while (s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s=mid+1;
        }
        else
        {
            e=mid;
        }
        mid=s+((e-s)/2);
    }
    return s;

} 
int main(){
    int arr[7]={9,10,1,2,3,5,6};
    int a=pivotElement(arr,7);
    cout<<"Index of pivot Element is-->"<<a;



}
#include<iostream>
using namespace std;
void printArray(int arr[],int size){
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<< endl;
}

void swapAlternate(int a[],int size){

    for(int i=0;i<size;i+=2){
        
        if((i+1)<size){
            swap(a[i],a[i+1]);

        }
    }



}




int main()
    {
    int brr[6]={2,6,3,9,4,8};
    swapAlternate(brr,6);
    printArray(brr,6);

}
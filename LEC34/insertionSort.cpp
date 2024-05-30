#include<iostream>
using namespace std;

void sortInsertion(int *arr, int n) {
    if(n==0|||n==1){
        return;
    }
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            arr[i+1]=arr[i];
        }


    }



    

}

int main() {

    int arr[5] = {2,5,1,6,9};
    
    sortInsertion(arr,5);

    for(int i=0; i<5; i++) {
        cout << arr[i] << " ";
    }cout << endl;


    return 0;
}
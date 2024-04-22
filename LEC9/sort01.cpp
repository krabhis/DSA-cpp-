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



int seclarge(vector<int> &a, int n){
    int largest=a[0];
    int slargset=-1;
     for(int i=0; i<n;i++){
        if(a[i]>largest){
            slargest=largest;
            largest=a[i];
        }
        else if(a[i]<largest && a[i]>slargest){
            slargest=a[i];
        }


     }
     return slargest;
 }


 int secsmall(vector<int> &a, int n){
    int smallest=a[0];
    int ssmallest=INT_MAX;
     for(int i=0; i<n;i++){
        if(a[i]<smallest){
            ssmallest=smallest;
            smallest=a[i];
        }
        else if(a[i]!= smallest && a[i]<ssmallest){
            ssmallest=a[i];
        }


     }
     return ssmallest;
 }



vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest=seclarge(a, n);
        int ssmallest=secsmall(a,n);
        return { slargest, ssmallest }
}    
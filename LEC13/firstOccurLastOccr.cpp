#include<iostream>
using namespace std;

int first_occur(int ar[],int n,int item){
    int s=0,e=n-1,ans;
    int mid=s+((e-s)/2);
    while(s<=e){
        if(ar[mid]==item){
             ans=mid;
            e=mid-1;}

            else if(ar[mid]<item){
                s=mid+1;

            }
            else{
                e=mid-1;
            }
           
             mid=s+((e-s)/2);
            
        

    }
    return ans;

}


int last_occur(int ar[],int n,int item){
    int s=0,e=n-1,ans;
    int mid=s+((e-s)/2);
    while(s<=e){
        if(ar[mid]==item){
             ans=mid;
            s=mid+1;
            }

            else if(ar[mid]<item){
                s=mid+1;

            }
            else{
                e=mid-1;
            }
             mid=s+((e-s)/2);
            
        

    }
    return ans;

}


int main(){
    int arr[11]={1,2,3,4,4,4,7,7,7,7,7};
    int a=first_occur(arr,11,7);
    int b=last_occur(arr,11,7);
    cout<<"First_Occur at index-->"<<a;
    cout<<"last_Occur at index-->"<<b;

}
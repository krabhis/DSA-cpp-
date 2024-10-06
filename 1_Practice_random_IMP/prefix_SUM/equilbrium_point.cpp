#include <bits/stdc++.h>

using namespace std;

int equilibrium_point(int arr[],int size){
  for(int i=0;i<size;i++){
    long long leftSum=0;
    for(int j=0;j<i;j++){
        leftSum+=arr[j];
    }
    // cout<<leftSum<<endl;

    long long rightSum=0;
    for(int k=i+1;k<size;k++){
        rightSum+=arr[k];
    }
        // cout<<rightSum<<endl;

    if(leftSum==rightSum){
        return i+1;
    }
  }
  return -1;
}

int main() {

    int arr[]={1,3,5,2,2};
   int ans= equilibrium_point(arr,5);
   cout<<ans<<endl;

    cout << "Love you Zindagi" << endl;
    return 0;
}
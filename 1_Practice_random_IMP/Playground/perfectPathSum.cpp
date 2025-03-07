#include <bits/stdc++.h>

using namespace std;
void solve(int arr[6],int target,int n, int &count,int index,int sum){
    if(index>=n) return ;
    if(sum==target){
        count++;
        return;
    }
    sum+=arr[index];
    solve(arr,target,n,count,index+1,sum);
    if(sum>target){
        sum=sum-arr[index]; 
    }
    
    
}
  int perfectSum(int arr[6], int target) {
      int count=0;
      int n=6;
      solve(arr,target,n,count,0,0);
      return count;
  }


int main() {
    cout << "Love you Zindagi" << endl;
    int arr[6] = {5, 2, 3, 10, 6, 8};
    int target = 10;
    int ans=perfectSum(arr,target);
    cout<<ans;
    return 0;
}
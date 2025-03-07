#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    
      int solve( int k , vector<int>&arr , int index){
          if(index==0) return 0;
          int mincost=INT_MAX;
          for(int j=1;j<=k;j++){
              if(index-j>=0){
              int jump=solve(k,arr,index-j)+abs(arr[index]-arr[index-j]);
              mincost=min(mincost,jump);
              }
              
          }
          return mincost;
          
      }
      int minimizeCost(int k, vector<int>& arr) {
          int size=arr.size();
          return solve(k,arr,size-1);
      }
  };

  int main() {
    Solution sol;
    vector<int> arr = {10, 30, 40, 50, 20}; 
    int k = 3;
    int res = sol.minimizeCost(k, arr); 
    cout << res; 
    return 0;
}

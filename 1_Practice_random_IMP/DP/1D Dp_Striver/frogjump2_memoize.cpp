#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int k, vector<int>& arr, int index, vector<int>& dp) {
        if (index == 0) return 0;
        if (dp[index] != -1) return dp[index]; // Memoization check
        
        int mincost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int jump = solve(k, arr, index - j, dp) + abs(arr[index] - arr[index - j]);
                mincost = min(mincost, jump);
            }
        }
        return dp[index] = mincost; // Store the minimum cost in dp
    }

    int minimizeCost(int k, vector<int>& arr) {
        int size = arr.size();
        vector<int> dp(size, -1); // Initialize with -1 for memoization
        return solve(k, arr, size - 1, dp);
    }
};

      int minimizeCost(int k, vector<int>& arr) {
          int size=arr.size();
          vector<int>dp(size,0);
          return solve(k,arr,size-1,dp);
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

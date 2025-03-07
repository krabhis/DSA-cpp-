#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        int solve(vector<int>& nums, int index,vector<int>&dp) {
            if (index == 0) return nums[index];  
            if (index < 0) return 0; 
            if(dp[index]!=-1) return dp[index];

            dp[0]=nums[0];

            
            int pick = nums[index] + solve(nums, index - 2,dp);
            int not_pick = solve(nums, index - 1,dp); 

            dp[index]= max(pick, not_pick);
            return dp[index];
        }

        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int>dp(n,-1);
            return solve(nums, n - 1,dp);  
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int res = sol.rob(nums);
    cout << res;  // Output: 12
    return 0;
}

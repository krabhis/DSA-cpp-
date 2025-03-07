#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        if (index == 0)
            return nums[index];
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int pick = nums[index] + solve(nums, index - 2, dp);
        int not_pick = solve(nums, index - 1, dp);

        dp[index] = max(pick, not_pick);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // Edge case: If there's only one house.

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++) {
            if (i != 0) temp1.push_back(nums[i]);  
            if (i != n - 1) temp2.push_back(nums[i]); 
        }

        vector<int> dp1(n - 1, -1), dp2(n - 1, -1);  
        int res = max(solve(temp1, n - 2, dp1), solve(temp2, n - 2, dp2));
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 2};
    cout << sol.rob(nums) << endl;
    return 0;
}

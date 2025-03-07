#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        int solve(vector<int>& nums, int index) {
            if (index == 0) return nums[index];  
            if (index < 0) return 0; 
            
            int pick = nums[index] + solve(nums, index - 2);
            int not_pick = solve(nums, index - 1); 

            return max(pick, not_pick);
        }

        int rob(vector<int>& nums) {
            int n = nums.size();
            return solve(nums, n - 1);  // Fix: Call with n-1 instead of n
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int res = sol.rob(nums);
    cout << res;  // Output: 12
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& height, vector<int>& dp) {
        if (n == 0) return dp[0] = 0;
        if (n == 1) return dp[1] = abs(height[1] - height[0]);

        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);

        for (int i = 2; i <= n; i++) {
            int first_way = dp[i - 1] + abs(height[i] - height[i - 1]);
            int second_way = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(first_way, second_way);
        }

        return dp[n];
    }
    
    int minCost(vector<int>& height) {
        int n = height.size() - 1;
        vector<int> dp(n + 1, 0);
        return solve(n, height, dp);
    }
};

int main() {
    vector<int> vec = {10, 30, 40, 20, 50};
    Solution sol;
    cout << sol.minCost(vec);
    return 0;
}

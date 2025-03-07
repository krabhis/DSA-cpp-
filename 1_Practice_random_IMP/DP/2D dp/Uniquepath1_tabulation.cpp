#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, int s1, int s2, vector<vector<int>>& dp) {
        // Initialize the base cases
        for (int i = 0; i < m; i++) dp[i][0] = 1;  // First column (only downward movement possible)
        for (int j = 0; j < n; j++) dp[0][j] = 1;  // First row (only rightward movement possible)

        // Filling the DP table using bottom-up approach
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Paths from top + left
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0)); 
        return solve(m, n, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    int res = sol.uniquePaths(m, n);
    cout << res << endl; // Output: 28
    return 0;
}

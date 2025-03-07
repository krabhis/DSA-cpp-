#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& grid, int s1, int s2, int mini, vector<vector<int>>& dp) {
        // Initialize the starting cell
        dp[0][0] = grid[0][0];
        
        // Initialize the first row
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        
        // Initialize the first column
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        
        // Fill in the rest of the DP table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int mini = INT_MAX;  // Not used, but kept for compatibility with your original parameters
        int res = solve(row, col, grid, 0, 0, mini, dp);
        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> grid = { {1,3,1}, {1,5,1}, {4,2,1} };
    int res = sol.minPathSum(grid);
    cout << res;
}

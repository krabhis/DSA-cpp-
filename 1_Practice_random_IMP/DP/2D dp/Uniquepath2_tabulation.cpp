#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 1) break;
            dp[0][j] = 1;
        }

       
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // If there's an obstacle, no path can go through this cell
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]; // Sum of paths from top and left
                }
            }
        }
    
        return dp[m-1][n-1];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) 
            return 0;

        vector<vector<int>> dp(row, vector<int>(col, 0)); 
        return solve(row, col, obstacleGrid, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int res = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << res; // Expected output: 2
    return 0;
}

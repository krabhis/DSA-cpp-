class Solution {
    public:
        int solve(int m, int n, vector<vector<int>>& obstacleGrid, int s1, int s2, vector<vector<int>>& dp) {
            if (s1 >= m || s2 >= n || obstacleGrid[s1][s2] == 1) return 0;
            if (s1 == m - 1 && s2 == n - 1) return 1;
            if (dp[s1][s2] != -1) return dp[s1][s2];
    
            int right = solve(m, n, obstacleGrid, s1, s2 + 1, dp);
            int down = solve(m, n, obstacleGrid, s1 + 1, s2, dp);
    
            return dp[s1][s2] = right + down;
        }
    
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int row = obstacleGrid.size();
            int col = obstacleGrid[0].size();
           // [[1]]
            if (obstacleGrid[0][0] == 1 || obstacleGrid[row - 1][col - 1] == 1) 
                return 0;
            vector<vector<int>> dp(row, vector<int>(col, -1));
            return solve(row, col, obstacleGrid, 0, 0, dp);
        }
    };
    
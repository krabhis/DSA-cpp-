#include <bits/stdc++.h>

using namespace std;



class Solution {
    public:
        int solve(int m, int n , vector<vector<int>>& grid ,int s1, int s2,int mini,vector<vector<int>>&dp){
            if(s1==m-1 && s2==n-1){
                return grid[s1][s2];
            }
            if(s1>m-1||s2>n-1)return INT_MAX;
            if(dp[s1][s2]!=-1) return dp[s1][s2];
            int right=solve(m,n,grid,s1,s2+1,mini,dp);
            int down=solve(m,n,grid,s1+1,s2,mini,dp);

            dp[s1][s2]=grid[s1][s2]+min(right,down); 
            return dp[s1][s2];
    
        }
        int minPathSum(vector<vector<int>>& grid) {
            int row=grid.size();
            int col=grid[0].size();
            vector<vector<int>>dp(row,vector<int>(col,-1));
            int mini=INT_MAX;
            int res=solve(row,col,grid,0,0,mini,dp);
            return res;
        }
    }; 

    
    int main(){
        Solution sol;
        vector<vector<int>>grid= {{1,3,1},{1,5,1},{4,2,1}};
        int res=sol.minPathSum(grid);
        cout<<res;
    }



    
    ////////////////////////////////////////////////////////////////////
    // Moving m-1,n-1 to 0 ,0
    /*
    class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (i < 0 || j < 0) return INT_MAX;
        if (dp[i][j] != -1) return dp[i][j];

        int up = (i > 0) ? grid[i][j] + solve(i - 1, j, grid, dp) : INT_MAX;
        int left = (j > 0) ? grid[i][j] + solve(i, j - 1, grid, dp) : INT_MAX;

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        return solve(row - 1, col - 1, grid, dp);
    }
};

    */

    ///////////////////////////////////////////////////////////////////

    /*
    
    In summary, the code is recursively computing the full minimum path sum from the current cell by considering both right and down paths completely, and then choosing the best one. This is why the formula works correctly and is not merely a greedy approach.
    */
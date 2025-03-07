#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, int s1, int s2, vector<vector<int>>& dp) {
        // Base case: If we reach the bottom-right corner
        if (s1 == m - 1 && s2 == n - 1) 
            return 1;
        
        // If we go out of bounds, return 0
        if (s1 >= m || s2 >= n) 
            return 0;  

        // Check if already computed
        if (dp[s1][s2] != -1) 
            return dp[s1][s2];

        // Move right and down
        int right = solve(m, n, s1, s2 + 1, dp);
        int down = solve(m, n, s1 + 1, s2, dp);

        return dp[s1][s2] = right + down;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, dp);
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    int res = sol.uniquePaths(m, n);
    cout << res << endl;
    return 0;
}


/*
Note:

1.Use three points explained earlier  analyse the edge cases.
2.After memoizationand tabulation we can optimise the space if there is previous row and previous col. 


*/
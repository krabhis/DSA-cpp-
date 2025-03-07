#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, int s1, int s2) {
        // Base case: If we reach the bottom-right corner
        if (s1 == m - 1 && s2 == n - 1) 
            return 1;
        
        // If we go out of bounds, return 0
        if (s1 >= m || s2 >= n) 
            return 0;  

        // Move right
        int right = solve(m, n, s1, s2 + 1);
        // Move down
        int down = solve(m, n, s1 + 1, s2);

        return right + down;
    }

    int uniquePaths(int m, int n) {
        return solve(m, n, 0, 0);
    }
};

int main() {
    Solution sol;
    int m = 3, n = 7;
    int res = sol.uniquePaths(m, n);
    cout << res << endl;
    return 0;
}

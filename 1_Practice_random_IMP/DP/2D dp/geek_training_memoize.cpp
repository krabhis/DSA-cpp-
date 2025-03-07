#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fun(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return dp[day][last] = maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int point = arr[day][task] + fun(day - 1, task, arr, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return fun(n - 1, 3, arr, dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    int res = sol.maximumPoints(arr);
    cout << res << endl;
    return 0;
}

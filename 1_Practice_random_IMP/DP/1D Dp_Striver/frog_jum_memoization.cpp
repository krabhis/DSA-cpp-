#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& height, vector<int>& dp) {
        if (n == 0) return 0; 
        if (dp[n] != -1) return dp[n];
        
        int first_way = solve(n - 1, height, dp) + abs(height[n] - height[n - 1]);
        int second_way = INT_MAX;
        if (n > 1) {
            second_way = solve(n - 2, height, dp) + abs(height[n] - height[n - 2]);
        }
        
        return dp[n] = min(first_way, second_way);
    }
    
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, -1);
        return solve(n - 1, height, dp);
    }
};

int main() {
    vector<int> vec = {10 ,30 ,40 ,20 ,50,70};
    Solution sol;
    cout << sol.minCost(vec);
    return 0;
}


/*
first way

solve(4, height, dp)
├── solve(3, height, dp) + abs(height[4] - height[3])
│   ├── solve(2, height, dp) + abs(height[3] - height[2])
│   │   ├── solve(1, height, dp) + abs(height[2] - height[1])
│   │   │   ├── solve(0, height, dp) + abs(height[1] - height[0])
│   │   │   │   ├── solve(0, height, dp) = 0  (Base Case)
│   │   │   │   ├── abs(30 - 10) = 20
│   │   │   ├── solve(1, height, dp) = 20
│   │   │   ├── abs(40 - 30) = 10
│   │   ├── solve(2, height, dp) = 30
│   │   ├── abs(20 - 40) = 20
│   ├── solve(3, height, dp) = 50
│   ├── abs(50 - 20) = 30
├── solve(4, height, dp) = 80

second way

solve(4, height, dp)
├── solve(2, height, dp) + abs(height[4] - height[2])
│   ├── solve(1, height, dp) + abs(height[2] - height[1])
│   │   ├── solve(0, height, dp) + abs(height[1] - height[0])
│   │   │   ├── solve(0, height, dp) = 0 (Base Case)
│   │   │   ├── abs(30 - 10) = 20
│   │   ├── solve(1, height, dp) = 20
│   │   ├── abs(40 - 30) = 10
│   ├── solve(2, height, dp) = 30
│   ├── abs(50 - 40) = 10
├── solve(4, height, dp) = 40



First Way (solve(3) + abs(height[4] - height[3])): 80
Second Way (solve(2) + abs(height[4] - height[2])): 40

n	solve(n)  Calculation	Result
0	Base Case	0
1	solve(0) + abs(30 - 10)	20
2	solve(1) + abs(40 - 30)	30
3	solve(2) + abs(20 - 40)	50
4 (First Way)  solve(3) + abs(50 - 20)	80
4 (Second Way) solve(2) + abs(50 - 40)	40
4 (Final)	min(80, 40)	40




For (n=6) if 0 based indexing n=0 to 5.

n	solve(n)               Calculation	                 Result
0	Base Case 0	         0
1	                     solve(0) + abs(30 - 10)	0 + 20 = 20
2	                     solve(1) + abs(40 - 30)	20 + 10 = 30
3   (First Way)	         solve(2) + abs(20 - 40)	30 + 20 = 50
3   (Second Way)	     solve(1) + abs(20 - 30)	20 + 10 = 30
3   (Final)	             min(50, 30)	30
4   (First Way)	         solve(3) + abs(50 - 20)	30 + 30 = 60
4   (Second Way)	     solve(2) + abs(50 - 40)	30 + 10 = 40
4   (Final)	             min(60, 40)	             40
5   (First Way)	         solve(4) + abs(70 - 50)	40 + 20 = 60
5   (Second Way)	     solve(3) + abs(70 - 20)	30 + 50 = 80
5   (Final)	             min(60, 80)	              60

*/


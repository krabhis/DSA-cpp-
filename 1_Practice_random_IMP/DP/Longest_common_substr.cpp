#include <iostream>
#include <vector>
using namespace std;

// Memoization table
vector<vector<int>> dp;

// Recursive function with memoization
int lcsUtil(string &s1, string &s2, int i, int j, int &maxLength) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + lcsUtil(s1, s2, i - 1, j - 1, maxLength);

        maxLength = max(maxLength, dp[i][j]);
    } else {
        lcsUtil(s1, s2, i - 1, j, maxLength);
        lcsUtil(s1, s2, i, j - 1, maxLength);
        dp[i][j] = 0; 
    }

    return dp[i][j];
}

// Wrapper function
int longestCommonSubstring(string s1, string s2) { 
    int n = s1.length(), m = s2.length();
    dp.assign(n, vector<int>(m, -1));
    int maxLength = 0;
    lcsUtil(s1, s2, n - 1, m - 1, maxLength);
    return maxLength;
}


int main() {
    string s1 = "abcde", s2 = "abfde";
    cout << "Longest Common Substring Length: " << longestCommonSubstring(s1, s2) << endl;
    return 0;
}

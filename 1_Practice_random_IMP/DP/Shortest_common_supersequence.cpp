class Solution {
    public:
        void lcs(string &str1, string &str2, int a, int b , vector<vector<int>>&dp) {
            for(int i=1; i<=a; i++) {
                for(int j=1; j<=b; j++) {
                    if(str1[i-1] == str2[j-1]) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
        }
        string shortestCommonSupersequence(string str1, string str2) {
            int a = str1.size();
            int b = str2.size();
            vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
            lcs(str1, str2, a, b, dp);
    
            int i = a, j = b;
            string ans = "";
            while(i > 0 && j > 0) {
                if(str1[i-1] == str2[j-1]) {
                    ans.push_back(str1[i-1]);
                    i--;
                    j--;
                } else {
                    if(dp[i-1][j] > dp[i][j-1]) {
                        ans.push_back(str1[i-1]); // Move up
                        i--;
                    } else {
                        ans.push_back(str2[j-1]); // Move left
                        j--;
                    }
                }
            }
            while(i > 0) {
                ans.push_back(str1[i-1]);
                i--;
            }
            while(j > 0) {
                ans.push_back(str2[j-1]);
                j--;
            }
            reverse(ans.begin(), ans.end());
    
            return ans;
        }
    };
    
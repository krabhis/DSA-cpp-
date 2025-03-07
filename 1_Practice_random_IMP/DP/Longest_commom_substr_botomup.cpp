
class Solution {
    public:
      int longestCommonSubstr(string& s1, string& s2) {
          
          int n=s1.length(),m=s2.length();
          vector<vector<int>> dp(n+1,vector<int>(m+1,0));
          int ans=0;
          for(int idx1=1;idx1<=n;idx1++){
              for(int idx2=1;idx2<=m;idx2++){
                  if(s1[idx1-1]==s2[idx2-1]){
                      dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                      ans = max(ans,dp[idx1][idx2]);
                  }
                  else{
                      dp[idx1][idx2]=0;
                  }
              }
          }
          return ans;
      }
  };
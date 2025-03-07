#include <bits/stdc++.h>

using namespace std;

int solve( int n, vector<int>&dp){
    if(n==0||n==1) return 1;
    dp[0]=1, dp[1]=1;
    for(int i=2;i<n+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}

int main() {

    int n;
    cin>>n;
    vector<int>dp(n+1);
    int res=solve(n,dp);
    cout<<res;

    return 0;
}
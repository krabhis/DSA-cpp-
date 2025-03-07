#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int solve(int m, int n , vector<vector<int>>& grid ,int s1, int s2,int mini){
            if(s1==m-1 && s2==n-1){
                return grid[s1][s2];
            }
    
            if(s1>m-1||s2>n-1)return INT_MAX;//invalid paths pe INT_MAX daal do sothat minimum ke time ans me use consider na kre....
            int right=solve(m,n,grid,s1,s2+1,mini);
            int down=solve(m,n,grid,s1+1,s2,mini);

            mini=grid[s1][s2]+min(right,down); //current cell  ko add kro baki recursion sambhal lega 
            return mini;
    
        }
        int minPathSum(vector<vector<int>>& grid) {
            int row=grid.size();
            int col=grid[0].size();
            int mini=INT_MAX; 
    
            int res=solve(row,col,grid,0,0,mini);
            return res;
        }
    }; 

    int main(){
        Solution sol;
        vector<vector<int>>grid= {{1,3,1},{1,5,1},{4,2,1}};
        int res=sol.minPathSum(grid);
        cout<<res;
    }




    /*
    
    In summary, the code is recursively computing the full minimum path sum from the current cell by considering both right and down paths completely, and then choosing the best one. This is why the formula works correctly and is not merely a greedy approach.
    */
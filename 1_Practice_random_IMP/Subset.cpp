#include<bits/stdc++.h>
using namespace std;

void solve( vector<int>result , vector<vector<int>> &ans, int index, int nums[3]){
    int n=3;
    if(index >= n){
        ans.push_back(result);
        return;
    }
    solve(result , ans , index+1 , nums );

    int element=nums[index];
    result.push_back(element);
    solve(result , ans , index+1 , nums);

}

int main(){

    int nums[3]={1,2,3};
    int index=0;
    vector<int>result;
    vector<vector<int>>ans;

    solve(result,ans,index, nums);
      cout << "Subsets:" <<endl;
    for (int i = 0; i < ans.size(); i++) {
        cout <<"{";
        for (int j = 0; j< ans[i].size(); j++) {
            cout <<ans[i][j];
        }
        cout << "}" << endl;
    }
}


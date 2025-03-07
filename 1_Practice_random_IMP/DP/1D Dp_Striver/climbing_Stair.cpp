#include <bits/stdc++.h>

using namespace std;
int solve(int n){
    if(n==0||n==1) return 1;
    int one_step=solve(n-1);
    int two_step=solve(n-2);
    int tot_ways=one_step+two_step;
    return tot_ways;

}
int main() {
    int n ; 
    cin>>n;
    int res=solve(n);
    cout<<res<<endl;



    return 0;
}


/*
1.try to represent the problem in terms of index.
2.Do all the possible stuffs on that and all the problem statement
3.sum of all stuffs-> if asking for  count all ways.
4.min(of all stuffs)-> if asking for find min.
*/
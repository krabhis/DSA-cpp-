#include <bits/stdc++.h>
using namespace std;

int solve(string str, int i, int j, bool istrue, unordered_map<string ,int>&mapi) {
    if (i > j) return 0;
    if (i == j) {
        if (istrue) return str[i] == 'T';//return 1;
        else return str[i] == 'F';//return 0;
    }
    
    //added code for unordered_map  we can use 3d vectaor as well as here three variable are changing i, j, istrue;
    
    string temp=to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));

    if(mapi.find(temp)!=mapi.end()){
        return mapi[temp];
    }

    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        int lefttrue = solve(str, i, k - 1, true,mapi);
        int leftfalse = solve(str, i, k - 1, false,mapi);
        int righttrue = solve(str, k + 1, j, true,mapi);
        int rightfalse = solve(str, k + 1, j, false,mapi);
        
        if (str[k] == '&') {
            if (istrue) {
                ways += (lefttrue * righttrue);
            } else {
                ways += (lefttrue * rightfalse) + (righttrue * leftfalse) + (leftfalse * rightfalse);
            }
        } else if (str[k] == '|') {
            if (istrue) {
                ways += (lefttrue * rightfalse) + (leftfalse * righttrue) + (lefttrue * righttrue);
            } else {
                ways += (leftfalse * rightfalse);
            }
        } else if (str[k] == '^') {
            if (istrue) {
                ways += (lefttrue * rightfalse) + (leftfalse * righttrue);
            } else {
                ways += (lefttrue * righttrue) + (leftfalse * rightfalse);
            }
        }
    }
    mapi[temp]=ways;
    return mapi[temp];
}

int main() {
    string str = "T|F&T^F";
    int n = str.size();
    unordered_map<string, int>mapi;
    int res = solve(str, 0, n - 1, true,mapi);
    cout << res;
    return 0;
}
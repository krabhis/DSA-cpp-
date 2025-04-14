#include <bits/stdc++.h>
using namespace std;

int solve(string str, int i, int j, bool istrue) {
    if (i > j) return 0;
    if (i == j) {
        if (istrue) return str[i] == 'T';//return 1;
        else return str[i] == 'F';//return 0;
    }
    
    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        int lefttrue = solve(str, i, k - 1, true);
        int leftfalse = solve(str, i, k - 1, false);
        int righttrue = solve(str, k + 1, j, true);
        int rightfalse = solve(str, k + 1, j, false);
        
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
    return ways;
}

int main() {
    string str = "T|F&T^F";
    int n = str.size();
    int res = solve(str, 0, n - 1, true);
    cout << res;
    return 0;
}
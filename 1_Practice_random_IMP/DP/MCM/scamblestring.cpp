#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(string s1, string s2) {
        if (s1 == s2) return true;
        int n = s1.size();
        if (n <= 1) return false;

        for (int k = 1; k < n; k++) {
            //first is for swap and other is for no swap
            if ((solve(s1.substr(0, k), s2.substr(n - k, k)) && solve(s1.substr(k), s2.substr(0, n - k))) ||
                (solve(s1.substr(0, k), s2.substr(0, k)) && solve(s1.substr(k), s2.substr(k)))) {
                return true;
            }
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return solve(s1, s2);
    }
};

int main() {
    // string s1 = "great", s2 = "rgeat";
     string s1 = "abcde", s2 = "caebd";

    Solution ss;
    bool res = ss.isScramble(s1, s2);
    cout << (res ? "true" : "false") << endl;
}

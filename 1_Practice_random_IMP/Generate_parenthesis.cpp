#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, string res, int open, int close, vector<string>& ans) {
    // Base case: if the number of open and close parentheses is equal to n
    if (open == n && close == n) {
        ans.push_back(res);  // Push the valid combination into the result vector
        return;              // Return to stop further recursion
    }

    // If the number of open parentheses is less than n, we can add an open one
    if (open < n) {
        generateParenthesis(n, res + "{", open + 1, close, ans);
    }

    // If the number of close parentheses is less than the open ones, we can add a close one
    if (close < open) {
        generateParenthesis(n, res + "}", open, close + 1, ans);
    }
}

int main() {
    vector<string> ans;
    int n = 3;          // Number of pairs of parentheses
    string str;

    generateParenthesis(n, str, 0, 0, ans);   // Generate all valid combinations

    // Print the valid combinations
    for (string c : ans) {
        cout << c << " ";
    }

    return 0;
}

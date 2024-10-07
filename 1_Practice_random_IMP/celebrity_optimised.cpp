#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int n, vector<vector<int>>& M) {
    int top = 0, down = n - 1;
    
    // Find a candidate celebrity by comparing people
    while (top < down) {
        if (M[top][down] == 1) {
            // top knows down, so top cannot be a celebrity
            top++;
        } else {
            // down knows top, so down cannot be a celebrity
            down--;
        }
    }
    
    // Now top is a candidate for celebrity, let's verify
    int candidate = top;

    // Verify that the candidate knows no one, and everyone knows the candidate
    for (int i = 0; i < n; i++) {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
            // If the candidate knows someone, or someone doesn't know the candidate, return -1
            return -1;
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> M = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    
    int n = M.size();
    int celebrity = findCelebrity(n, M);
    
    if (celebrity == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity is person " << celebrity << "." << endl;
    }

    return 0;
}

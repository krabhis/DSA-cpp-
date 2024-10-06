#include <bits/stdc++.h>
using namespace std;

// Recursive function to generate all permutations
void solve(vector<int>& vec, vector<int>& ans, vector<vector<int>>& result, vector<bool>& used) {
    if (ans.size() == vec.size()) { // If current permutation is complete
        result.push_back(ans); // Add permutation to result
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
        if (!used[i]) { // If element not yet used
            ans.push_back(vec[i]); // Add element to the current permutation
            used[i] = true; // Mark element as used
            solve(vec, ans, result, used); // Recursively generate permutations
            ans.pop_back(); // Backtrack: remove last element
            used[i] = false; // Mark element as unused for future possibilities
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3}; // Input array
    vector<vector<int>> result;  // To store all permutations
    vector<int> ans;             // To store a single permutation
    vector<bool> used(arr.size(), false); // To track used elements in the permutation

    // Generate all permutations
    solve(arr, ans, result, used);

    // Print all permutations
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Love you Zindagi" << endl;

    return 0;
}

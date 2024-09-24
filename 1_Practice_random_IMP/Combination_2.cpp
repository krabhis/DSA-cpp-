#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void solve(int index, int target, vector<int>& arr, set<vector<int>>& ans, vector<int>& ds) {
        if (index == arr.size()) {
            if (target == 0) {
                ans.insert(ds);  // Add the combination to the set if target is met
            }
            return;
        }

        // Take the element if it is <= target
        if (arr[index] <= target) {
            ds.push_back(arr[index]);
            solve(index + 1, target - arr[index], arr, ans, ds);  // Move to next index
            ds.pop_back();  // Backtrack after exploring this path
        }

        // Move to the next index without taking the current element
        solve(index + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        set<vector<int>> ans;  // Set to store unique combinations
        vector<int> ds;  // Current combination
        vector<vector<int>> finalAns;  // Store the result in a vector of vectors

        solve(0, target, candidates, ans, ds);  // Recursive function to find combinations

        // Convert set to vector
        for (auto it : ans) {
            finalAns.push_back(it);
        }

        return finalAns;
    }
};

int main() {
    Solution sol;

    // Input
    vector<int> candidates = {10, 1, 6, 1, 1};
    int target = 8;

    // Call the function
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Output the results
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

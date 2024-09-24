#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        if (target == 0) {
            ans.push_back(ds);  // If the target is reached, add the current combination to the answer
            return;
        }

        if (index == arr.size()) {
            return;  // If we've considered all elements, return
        }

        // Include the current element
        if (arr[index] <= target) {
            ds.push_back(arr[index]);  // Add the element to the current combination
            solve(index, target - arr[index], arr, ans, ds);  // Recur with updated target
            ds.pop_back();  // Backtrack
        }

        // Exclude the current element
        solve(index + 1, target, arr, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  // Store the final combinations
        vector<int> ds;  // Temporary storage for the current combination
        solve(0, target, candidates, ans, ds);  // Start the backtracking
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {1,1,1,2,2,2,3,4,5,5,6};
    int target = 4;

    // Get the combinations
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print the results
    cout << "Combinations that sum up to " << target << ":\n";
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

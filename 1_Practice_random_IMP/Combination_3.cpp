class Solution {
public:
    void solve(int item, int sum, vector<vector<int>>& powerset, vector<int>& subset, int k, int target) {
        // If the current sum exceeds the target, we stop exploring this branch
        if (sum > target) return;

        // If we've selected k numbers and the sum equals target, we have a valid subset
        if (k == 0) {
            if (sum == target) {
                powerset.push_back(subset);
            }
            return;
        }

        // If we've reached beyond 9 (since we only need numbers 1-9)
        if (item == 10) return;

        // Pick the current item
        sum += item;
        subset.push_back(item);
        solve(item + 1, sum, powerset, subset, k - 1, target);
        sum -= item; // Backtrack the sum
        subset.pop_back(); // Backtrack the subset

        // Ignore the current item
        solve(item + 1, sum, powerset, subset, k, target);
    }

    vector<vector<int>> combinationSum3(int k, int target) {
        vector<vector<int>> powerset;
        vector<int> subset;
        int sum = 0;
        int item = 1;

        // Start the recursive function
        solve(item, sum, powerset, subset, k, target);
        return powerset;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int start, int currentsize, int &count) {
        if (start + currentsize > nums.size()) return;

        // Check if current subarray is arithmetic
        bool isArithmetic = true;
        int diff = nums[start + 1] - nums[start];
        for (int i = start + 1; i < start + currentsize; ++i) {
            if (nums[i] - nums[i - 1] != diff) {
                isArithmetic = false;
                break;
            }
        }

        if (isArithmetic && currentsize >= 3) {
            count++;
        }

        // Expand the subarray
        solve(nums, start, currentsize + 1, count);
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i <= n - 3; ++i) {
            solve(nums, i, 2, count);
        }
        return count;
    }
};

int main() {
    Solution ss;
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    int res = ss.numberOfArithmeticSlices(nums);
    cout << res << endl;

    return 0;
}

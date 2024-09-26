#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    int result = 0;

    // Initialize the prefix sum count for sum 0
    prefixSumCount[0] = 1;

    for (int num : nums) {
        prefixSum += num;

        // Check if there is a prefix sum that makes a subarray sum to goal
        if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end()) {
            result += prefixSumCount[prefixSum - goal];
        }

        // Update the prefix sum count
        prefixSumCount[prefixSum]++;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << "Number of subarrays with sum " << goal << " is: " << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}

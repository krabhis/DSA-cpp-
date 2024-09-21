#include<bits/stdc++.h>
using namespace std;

void solve(int target_sum, int sum, int arr[], int n, vector<int>& ds, int index) {
    // Base case: if index reaches the size of the array, check if the current sum equals target_sum
    if (index == n) {
        if (sum == target_sum) {
            // Print the elements in the current subset that sum up to target_sum
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }

    // Pick the current element
    ds.push_back(arr[index]);
    sum += arr[index];
    solve(target_sum, sum, arr, n, ds, index + 1);

    // Backtrack: remove the last added element and subtract from the sum
    sum -= arr[index];
    ds.pop_back();

    // Do not pick the current element
    solve(target_sum, sum, arr, n, ds, index + 1);
}

int main() {
    int sum = 0;
    int arr[5] = {1, 2, 1, 1, 2 };  // Array of elements
    int target_sum = 2;      // Target sum to find subsets
    int index = 0;
    vector<int> ds;

    // Call the function with the size of the array (3 in this case)
    solve(target_sum, sum, arr, 5, ds, index);

    return 0;
}

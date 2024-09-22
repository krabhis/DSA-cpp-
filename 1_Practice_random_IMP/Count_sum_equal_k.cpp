#include<bits/stdc++.h>
using namespace std;

// Function to solve the subset sum problem
int solve(int arr[], int n, int index, int s, int sum){
    // Base case: when index reaches the size of the array
    if (index == n) {
        // If the current sum equals the target sum, increment the count
        if (s == sum) {
            return 1;  // One valid subset found
        }
        return 0;  // No valid subset found
    }

    // Recursive case:
    // Option 1: Include the current element in the sum
    s += arr[index];
    int include = solve(arr, n, index + 1, s, sum); // Including the current element

    // Option 2: Backtrack and exclude the current element from the sum
    s -= arr[index];
    int exclude = solve(arr, n, index + 1, s, sum); // Excluding the current element

    // Return the sum of both choices (include and exclude)
    return include + exclude;
}

// Wrapper function to call the recursive function
int perfectSum(int arr[], int n, int sum) {
    int s = 0;
    int index = 0;
    // Call the recursive function and return the result
    return solve(arr, n, index, s, sum);
}

int main() {
    int arr[] = {1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;

    // Call the perfectSum function and print the result
    cout << "Number of subsets with sum " << sum << ": " << perfectSum(arr, n, sum) << endl;

    return 0;
}

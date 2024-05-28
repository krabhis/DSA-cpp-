#include <iostream>
using namespace std;

// Recursive function to calculate the sum of array elements
int sumArray(int arr[], int n) {
    // Base case: when n is 0, the sum is 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: sum of the array is the last element plus the sum of the rest
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    // Define an array of integers
    int arr[] = {1, 2, 3, 4, 5};
    
    // Get the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call the recursive function to get the sum of the array elements
    int sum = sumArray(arr, n);

    // Output the sum
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}

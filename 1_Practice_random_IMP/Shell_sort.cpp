#include <bits/stdc++.h>
using namespace std;

// Function to perform Shell Sort
void shellSort(vector<int>& arr) {
    int n = arr.size();
    
    // Start with a large gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            
            // Shift earlier gap-sorted elements until the correct position is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // Put temp (the original arr[i]) in its correct position
            arr[j] = temp;
        }
    }
}

int main() {
    
    vector<int> arr = {12, 34, 54, 2, 3, 7, 17, 4, 25};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    shellSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

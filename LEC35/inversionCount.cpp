#include<iostream>
using namespace std;

void merge(int *arr, int s, int e, long long &invCount) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge 2 sorted arrays and count inversions
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] <= second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
            invCount += (len1 - index1); // All remaining elements in first are greater than second[index2]
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;
}

void mergeSort(int *arr, int s, int e, long long &invCount) {
    // Base case
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    // Sort left part
    mergeSort(arr, s, mid, invCount);

    // Sort right part
    mergeSort(arr, mid + 1, e, invCount);

    // Merge
    merge(arr, s, e, invCount);
}

int main() {
    int arr[5] = {3, 7, 0, 1, 5};
    int n = 5;
    long long invCount = 0;

    mergeSort(arr, 0, n - 1, invCount);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Inversion count: " << invCount << endl;

    return 0;
}



/*

Why (len1 - index1)?
Remaining Elements: When first[index1] > second[index2], all the remaining elements in first starting from index1 to len1-1 will be greater than second[index2].
Counting Inversions: The number of such elements is (len1 - index1), because index1 is the current position in first, and len1 is the total number of elements in first. Thus, there are len1 - index1 elements remaining in first that are greater than second[index2].
Example
Consider an example to clarify this:

first = [1, 5, 6]
second = [2, 3, 4]
During merging:

Compare 1 and 2: No inversion, so move 1 to the original array.
Compare 5 and 2: Inversion found. Since 5 is greater than 2, and 6 (the remaining element in first) is also greater than 2, there are 2 inversions (5 > 2 and 6 > 2).
Thus, invCount is incremented by len1 - index1, which is 2 in this case (as there are 2 elements in first from index1 onward).





*/
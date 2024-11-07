#include <iostream>
using namespace std;

// Function to partition the array
int partition(int a[], int beg, int end) {
    int left = beg;
    int right = end;
    int loc = beg;
    int temp;

    while (left != right) {
        // Move from right to left
        while (a[loc] <= a[right] && loc != right) {
            right--;
        }

        if (loc == right) {
            break;
        }

        if (a[loc] > a[right]) {
            // Swap elements
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }

        // Move from left to right
        while (a[loc] >= a[left] && loc != left) {
            left++;
        }

        if (loc == left) {
            break;
        }

        if (a[loc] < a[left]) {
            // Swap elements
            temp = a[loc];
            a[loc] = a[left];
            a[left] = temp;
            loc = left;
        }
    }

    return loc;
}

// Recursive Quick Sort function
void quickSort(int a[], int beg, int end) {
    int loc;
    if (beg < end) {
        loc = partition(a, beg, end); // Find the partition index
        quickSort(a, beg, loc - 1);   // Sort the left subarray
        quickSort(a, loc + 1, end);   // Sort the right subarray
    }
}

int main() {
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quickSort(a, 0, n - 1); // Call quicksort on the entire array

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

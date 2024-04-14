#include <iostream>
using namespace std;

void printArray(int a[], int size) {
    cout << "Array is: ";  // Add space after colon
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";  // Add space between elements
    }
    cout << endl;           // Print newline at the end
}

int main() {
    int ar[50];
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    // Input validation (optional): Ensure n is within a reasonable range
    if (n < 0 || n > 50) {
        cout << "Invalid array size. Please enter a value between 0 and 50." << endl;
        return 1; // Indicate error
    }

    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    printArray(ar, n); // Call printArray once after all elements are entered

    return 0;
}

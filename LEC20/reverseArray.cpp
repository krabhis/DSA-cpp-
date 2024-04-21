#include <iostream>

using namespace std;

void printInReverse(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[6] = {3, 9, 2, 4, 5, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Elements in reverse order: ";
    printInReverse(arr, n);

    return 0;
}

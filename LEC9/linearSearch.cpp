#include <iostream>
using namespace std;

void linearSearch(int arr[], int size) {
    int item, flag = 0;
    cout << "Enter the item to search: ";
    cin >> item;

    for (int i = 0; i < size; i++) {
        if (arr[i] == item) {
            cout << "Element Found at index i = " << i << endl;
            flag = 1;  // Set flag to indicate element found
            break;
        }
    }

    if (flag == 0) {
        cout << "Element not found in the array." << endl;
    }
}

int main() {
    int a[50], n;
    cout << "Enter the size of the array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> a[i];
    }

    linearSearch(a, n);

    return 0;
}

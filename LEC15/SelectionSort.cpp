#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
  int temp, minIndex;
  for (int i = 0; i < n - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}

int main() {
  int a[5] = {9, 5, 14, 9, 10};
  int n = sizeof(a) / sizeof(a[0]);

  selectionSort(a, n);

  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}



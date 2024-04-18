#include <iostream>

using namespace std;

int binarySearch(int a[], int size, int key) {
  int start = 0;
  int end = size - 1;
  int mid=(start+end)/2;

  while (start <= end) {

    if (a[mid] == key) {
      return mid;
    } else if (key > a[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = (start + end) / 2;


  }

  return -1; // Key not found
}

int main() {
  int arr[7] = {10, 20, 30, 40, 90, 100, 204};
  int atIndex = binarySearch(arr, 7, 100);
  cout << "key is at index ---> " << atIndex << endl;

  return 0;
}

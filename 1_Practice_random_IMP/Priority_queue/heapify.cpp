#include <bits/stdc++.h>

using namespace std;

void heapify(vector<int>&arr,int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&& arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&& arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}



int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    // Build max-heap
    buildHeap(arr);

    cout << "Heap array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinHeap {
public:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void insertKey(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        // Percolate up: move the new key to its proper position
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);//or (i - 1) / 2
        }
    }

    // Decrease value of key at index i to new_val
    void decreaseKey(int i, int new_val) {
        heap[i] = new_val;
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Extract the minimum element from the heap
    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty." << endl;
            return INT_MAX;
        }
        if (heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        // Store the minimum value, and move the last element to root
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        // Heapify from the root downwards
        minHeapify(0);
        return root;
    }

    // Delete key at index i
    void deleteKey(int i) {
        // To delete a key, decrease its value to negative infinity
        // and then extract the minimum element.
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Heapify the subtree rooted at index i
    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }
};

int main() {
    MinHeap h;

    // Query 1: insertKey(4)
    h.insertKey(4);

    // Query 2: insertKey(2)
    h.insertKey(2);

    // Query 3: extractMin() => should extract 2
    cout << "extractMin: " << h.extractMin() << endl;

    // Query 4: insertKey(6)
    h.insertKey(6);

    // Query 5: deleteKey(0) => deletes element at index 0 (currently 4)
    h.deleteKey(0);

    // Query 6: extractMin() => should extract 6
    cout << "extractMin: " << h.extractMin() << endl;

    // Query 7: extractMin() => Heap is now empty
    cout << "extractMin: " << h.extractMin() << endl;

    return 0;
}

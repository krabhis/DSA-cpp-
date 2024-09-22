#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to remove every other element from left to right
    void leftfunc(vector<int>& arr) {
        vector<int> temp;
        // Start from index 1 and take every other element
        for (int i = 1; i < arr.size(); i += 2) {
            temp.push_back(arr[i]);
        }
        arr = temp;
    }

    // Function to remove every other element from right to left
    void rightfunc(vector<int>& arr) {
        vector<int> temp;
        // Start from the last element and take every other element
        for (int i = arr.size() - 2; i >= 0; i -= 2) {
            temp.push_back(arr[i]);
        }
        reverse(temp.begin(), temp.end());  // Reverse to maintain order
        arr = temp;
    }

public:
    int lastRemaining(int n) {
        // Initialize the array with values 1 to n
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        // Alternating flag to determine direction
        bool leftToRight = true;
        // Repeat the process until only one element remains
        while (arr.size() > 1) {
            if (leftToRight) {
                leftfunc(arr); // Remove elements left to right
            } else {
                rightfunc(arr); // Remove elements right to left
            }
            leftToRight = !leftToRight;  // Switch direction
        }

        // Return the last remaining element
        return arr[0];
    }
};

int main() {
    Solution sol;
    int n = 9;
    cout << "Last remaining number for n = " << n << " is: " << sol.lastRemaining(n) << endl;
    return 0;
}

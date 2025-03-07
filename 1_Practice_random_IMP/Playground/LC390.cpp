#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, bool isLR) {
    if (arr.size() == 1) {
        return;
    }
    vector<int> newArr;
    if (isLR) {
        for (int i = 1; i < arr.size(); i += 2) {
            newArr.push_back(arr[i]);
        }
    } else {
        reverse(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i += 2) {
            newArr.push_back(arr[i]);
        }
        reverse(newArr.begin(), newArr.end());
    }
    arr = newArr;
    isLR = !isLR;
    solve(arr, isLR);
}

int lastRemaining(int n) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    bool isLR = true;
    solve(arr, isLR);
    return arr[0];
}
};

int main() {
    int n;
    cout << "Enter the value of n" << endl;
    cin >> n;
    int result = lastRemaining(n);
    cout << "Result for the value of n is->> " << result << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(vector<int> temp, long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Process first window
    for(int i = 0; i < K; i++) {
        if(temp[i] < 0) {
            dq.push_back(i);
        }
    }

    // Push answer for the first window
    if(!dq.empty()) {
        ans.push_back(temp[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process remaining windows
    for(int i = K; i < N; i++) {
        // Remove elements outside of the current window
        if(!dq.empty() && (i - dq.front()) >= K) {
            dq.pop_front();
        }

        // Add the current element if it's negative
        if(temp[i] < 0) {
            dq.push_back(i);
        }

        // Add the first negative integer of the current window to the answer
        if(!dq.empty()) {
            ans.push_back(temp[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}

// Driver program to test the function
int main() {
    vector<int> temp = {1, -6, 2, -3, 4, 5, -1, -3, 5, 6, 3, -6, -7};
    long long n = temp.size();
    long long k = 4;

    vector<long long> ans = printFirstNegativeInteger(temp, n, k);
    for(auto it : ans) cout << it << " ";
    cout << endl;

    return 0;
}

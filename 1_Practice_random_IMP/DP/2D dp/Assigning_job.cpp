#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>& cost, vector<bool>& usedCols, vector<int>& results,
           int row, int n, int sum) {
    if (row == n) {
        results.push_back(sum);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (!usedCols[col]) {
            usedCols[col] = true;
            solve(cost, usedCols, results, row + 1, n, sum + cost[row][col]);
            usedCols[col] = false;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(N));

=    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    vector<bool> usedCols(N, false);  
    vector<int> results;

    solve(cost, usedCols, results, 0, N, 0);

    sort(results.begin(), results.end());
    cout << results[0] << endl;

    return 0;
}

// 
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
 
// output=>13 selecting 2,6,4,1(only way)
#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;

    return solve(n - 1) + solve(n - 2);
}

int main() {
    int n;
    cin >> n;
    int res = solve(n);
    cout << "Fibonacci of n is " << res << endl;
    return 0;
}

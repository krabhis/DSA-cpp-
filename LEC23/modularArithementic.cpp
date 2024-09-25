long long factorial_mod(int n, int m) {
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % m;
    }
    return result;
}

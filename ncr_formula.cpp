#include <iostream>

using namespace std;

// Function to calculate factorial
long long fact(int n) {
  long long num = 1;

  for (int i = 1; i <= n; i++) {
    num *= i;
  }

  return num;
}


int ncr(int n, int r) {
  long long num, den, result;
  num = fact(n);
  den = fact(r) * fact(n - r);

 
  if (num < 0 || den < 0) {
    result = 0; 
  } else {
    result = num / den;
  }

  return result;
}

int main() {
  int n, r;

  cout << "Enter the value of n and r: ";
  cin >> n >> r;

  int result = ncr(n, r);

  if (result == 0) {
    cout << "Error: Calculation resulted in overflow." << endl;
  } else {
    cout << "nCr(" << n << ", " << r << ") = " << result << endl;
  }

  return 0;
}

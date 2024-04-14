

#include <iostream>

using namespace std;

void fibonacci(int n) {
  // Initialize variables inside the function for better control
  int a = 0, b = 1, c;

  cout << a << " " << b; // Print the first two numbers outside the loop

  for (int i = 0; i < n - 2; i++) { // Loop n-2 times to print n numbers
    c = a + b;
    a = b;
    b = c;
    cout << " " << c;
  }
}

int main() {
  int n;

  cout << "Enter the number of terms in the Fibonacci series: ";
  cin >> n;

  fibonacci(n);

  return 0;
}
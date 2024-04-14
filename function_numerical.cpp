#include <iostream>
using namespace std;

// Function to calculate an arithmetic expression (3n + 7)
int calculateExpression(int n) {
  return (3 * n) + 7;
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;

  int result = calculateExpression(n);

  cout << "Result: " << result << endl;

  return 0;
}

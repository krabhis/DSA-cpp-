#include <iostream>
#include <stack>
#include <string>

string removeAdjacentDuplicates(string str) {
  stack<char> charStack;
  string result;

  for (char ch : str) {
    if (charStack.empty() || charStack.top() != ch) {
      charStack.push(ch);
    } else {
      charStack.pop();
    }
  }

  while (!charStack.empty()) {
    result.insert(result.begin(), charStack.top());
    charStack.pop();
  }

  return result;
}

int main() {
  string str = "AABBCCCDDEEFF";
  string result = removeAdjacentDuplicates(str);
  cout << "Original string: " << str << endl;
  cout << "String without adjacent duplicates: " << result << endl;
  return 0;
}

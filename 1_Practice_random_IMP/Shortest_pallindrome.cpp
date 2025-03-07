#include <bits/stdc++.h>
using namespace std;

string shortestPalindrome(string &s) {
    string copy = s;
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        stk.push(s[i]);
    }
    string add = "";
    int i = 0;
    while (!stk.empty()) {
        if (s[i] == stk.top()) {
            stk.pop();
            i++;
        } else {
            add += stk.top();
            stk.pop(); // Pop the character from the stack
        }
    }
    string result = add + s; // Add the characters to the front of the original string
    return result;
}

int main() {
    cout << "Program started" << endl;
    string s = "aacecaaa";
    string result = shortestPalindrome(s);
    cout << "Program ended" << endl;

    cout << result << endl;

    return 0;
}
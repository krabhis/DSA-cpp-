#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "abhishek";  
    stack<char> s;
    
    
    for (char c : str) {
        s.push(c);
    }

    string ans = "";
    
    // Pop characters from the stack to reverse the string
    while (!s.empty()) {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout << ans << endl;  

    return 0; 
}

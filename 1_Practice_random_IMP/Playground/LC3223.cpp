#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "abaacbcbb";

    int count = s.size();
    vector<int> left;
    vector<int> right;

    for (int i = 1; i < s.size() - 1; i++) {
        int countleft = 0, countright = 0; 

        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == s[i]) {
                countleft++;
                removeCharacter(s, s[i]);
            }
        }
        cout << "leftCount:->" << countleft << endl;

        left.push_back(countleft);

        for (int k = i + 1; k < s.size(); k++) {
            if (s[k] == s[i]) {
                removeCharacter(s, s[i]);
                countright++;
            }
        }
        cout << "RightCount:->" << countright << endl;

        right.push_back(countright);
    }

    int l = 0;
    while (l < left.size()) {
        if (left[l] != 0 && right[l] != 0) {
            count -= 2;
        }
        l++;
    }

    cout << "Final count ans:->" << count << endl;

    for (int i = 0; i < left.size(); i++) {
        cout << right[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < left.size(); i++) {
        cout << left[i] << " ";
    }

    return 0;
}

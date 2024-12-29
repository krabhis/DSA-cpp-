#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;

        int n = word.size();
        int m = n - (numFriends - 1);
        string res = "";
        for (int i = 0; i <= n - m; ++i) {
            res = max(res, word.substr(i, m));
        }
        
        return res;
    }
};

int main() {
    string word;
    int numFriends;
    cout << "Enter the word: ";
    cin >> word;
    cout << "Enter the number of friends: ";
    cin >> numFriends;

    Solution sol;
    string result = sol.answerString(word, numFriends);
    cout << "Lexicographically largest: " << result << endl;

    return 0;
}

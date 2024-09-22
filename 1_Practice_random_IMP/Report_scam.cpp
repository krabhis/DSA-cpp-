#include<bits/stdc++.h>
using namespace std;


    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> bannedSet(bannedWords.begin(), bannedWords.end());
        unordered_map< string, int >mapi;
        for(string c:message){
            mapi[c]++;
        }

        int count = 0;

        for (string word : message) {
            if (bannedSet.find(word) != bannedSet.end()) {
                count++;
                if(count>1)
                return true;
            }
        }

        return false;
    }

int main() {
    vector<string> message = {"hello", "world", "leetcode"};  // Use vector instead of array
    vector<string> bannedWords = {"world", "hello"};  // Use vector instead of array
    bool a = reportSpam(message, bannedWords);
    cout << (a ? "Spam detected" : "No spam") << endl;  // Print result for testing
    return 0;
}

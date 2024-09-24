class Solution {
public:
    // Function to compare two frequency vectors
    bool valid_str(const vector<int>& a, const vector<int>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] < b[i]) {
                return false;
            }
        }
        return true;
    }

    // Function to calculate frequency of characters in a string
    vector<int> freq(const string& str) {
        vector<int> ans(26, 0);
        for(char ch : str) {
            ans[ch - 'a']++;
        }
        return ans;
    }

    long long validSubstringCount(string word1, string word2) {
        // If word2 is longer than word1, return 0 as no valid substrings can be found
        if(word2.size() > word1.size()) {
            return 0;
        }

        // Calculate the frequency of characters in word2
        vector<int> c = freq(word2);
        vector<int> v(26, 0);  // Frequency vector for the sliding window in word1

        long long count = 0;
        int start = 0;

        // Sliding window to traverse through word1
        for(int end = 0; end < word1.size(); end++) {
            char ch = word1[end];
            v[ch - 'a']++;  // Increment frequency of current character

            // Shrink the window if it matches the frequency of word2
            while(valid_str(v, c)) {
                count += (word1.size() - end); // Add valid substrings that word 2 is present in ()
                char start_char = word1[start];
                v[start_char - 'a']--; // Remove the start character from the window
                start++;  // Move start pointer to the right
            }
        }

        return count;
    }
};

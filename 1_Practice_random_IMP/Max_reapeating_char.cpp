#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int characterReplacement(string s, int k) {
    // Array to store the count of each character in the current window
    int count[26] = {0};
    int max_length = 0;
    int max_freq = 0;  // Count of the most frequent character in the window
    int left = 0;
    
    // Sliding window from left to right
    for (int right = 0; right < s.size(); right++) {
        // Update the count of the current character
        count[s[right] - 'A']++;
        
        // Update the max frequency character in the current window
        max_freq = max(max_freq, count[s[right] - 'A']);
        
        // If the current window size minus the most frequent character count
        // is greater than k, shrink the window from the left
        while ((right - left + 1) - max_freq > k) {
            count[s[left] - 'A']--;
            left++;
        }
        
        // Update the maximum length of the valid window
        max_length = max(max_length, right - left + 1);
    }
    
    return max_length;
}

int main() {
    string s = "AABABBA";
    int k = 1;
    cout << "Longest length of repeating characters after at most " << k << " replacements: " 
         << characterReplacement(s, k) << endl;
    return 0;
}

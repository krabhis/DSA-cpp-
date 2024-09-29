#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap; // Stores character and its latest index
        int maxLength = 0;
        int left = 0; // Left pointer of the sliding window
        
        for (int right = 0; right < s.size(); right++) {
            char currentChar = s[right];
            
            // If current character is found in the map and is inside the current window
            if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= left) {
                // Move the left pointer to the right of the last occurrence of the current character
                left = charMap[currentChar] + 1;
            }
            
            // Update the character's latest position in the map
            charMap[currentChar] = right;
            
            // Calculate the maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};


//solve it using set
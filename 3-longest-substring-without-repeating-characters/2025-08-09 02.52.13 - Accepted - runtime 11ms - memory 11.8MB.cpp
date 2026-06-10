class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];

            // If the character is already in the map and its index is within the current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1; // move the left pointer past the duplicate
            }

            // Update the character's index
            charIndexMap[currentChar] = right;

            // Calculate the max length of substring
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

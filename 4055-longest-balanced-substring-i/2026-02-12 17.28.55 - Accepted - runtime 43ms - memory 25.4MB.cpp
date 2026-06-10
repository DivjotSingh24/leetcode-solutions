class Solution {
public:
    int longestBalanced(string s) {
        int substringMaxLen = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int maxFreq = 0;
            int uniqueElement = 0;
            
            for (int j = i; j < n; j++) {
                int elementIndex = s[j] - 'a';
                if (freq[elementIndex] == 0) {
                    uniqueElement++;
                }
                
                freq[elementIndex]++;
                if (freq[elementIndex] > maxFreq) {
                    maxFreq = freq[elementIndex];
                }
                if (maxFreq * uniqueElement == (j - i + 1)) {
                    substringMaxLen = max(substringMaxLen, j - i + 1);
                }
            }
        }
        return substringMaxLen;
    }
};
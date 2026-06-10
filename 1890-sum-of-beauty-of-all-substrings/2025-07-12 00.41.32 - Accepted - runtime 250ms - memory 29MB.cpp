class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            map<char, int> freq;

            for (int j = i; j < n; ++j) {
                freq[s[j]]++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;

                for (auto it : freq) {
                    maxFreq = std::max(maxFreq, it.second);
                    minFreq = std::min(minFreq, it.second);
                }

                totalBeauty += (maxFreq - minFreq);
            }
        }

        return totalBeauty;
    }
};

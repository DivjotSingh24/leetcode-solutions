#include <unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        int left = 0, right = 0;
        int required = t.size();
        unordered_map<char, int> freq;
        for(char c : t) freq[c]++;
        
        int minLen = INT_MAX;
        int start =0;
        while(right < s.size()){
            if(freq[s[right]] > 0) required--;
            freq[s[right]]--;
            
            while(required == 0){
                int len = right - left + 1;
                if(len < minLen){
                    minLen = len;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0) required++;
                left++;
            }
            right++;
        }
        return (minLen == INT_MAX)? "" :s.substr(start, minLen);
    }
};

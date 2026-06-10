class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        map<char, int> m;
        int max_count = 0 ;

        int result=0;
        while(right<s.size()){
            m[s[right]]++;
            max_count = max(max_count, m[s[right]]);
            if((right - left + 1) - max_count > k){
                m[s[left]]--;
                left++;
            }
            result = max(result, right-left+1);
            right++;
        }
        return result;
        
        

    }
};
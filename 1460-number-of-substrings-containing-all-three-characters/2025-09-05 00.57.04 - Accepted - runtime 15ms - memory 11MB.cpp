class Solution {
public:
    bool check(map<char, int>& m){
        for(auto& p:m){
            if(p.second == 0) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        map<char, int> m;
        m['a'] = 0;
        m['b'] = 0;
        m['c'] = 0;
        int left = 0;
        int right =0;
        int answer=0;
        while(right<s.size()){
            m[s[right]]++;
            while(check(m)){
                m[s[left]]--;
                left++;
            }
            answer += right - left +1;
            right++;
        }
        int n = s.size();
        return (int)((long)n*(n+1)/2) - answer;
    }
};
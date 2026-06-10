class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length()!=t.length()) return false;
        int s_map[256]={0};
        int t_map[256]={0};
        for (int i=0;i<s.length();i++){
            char a=s[i];
            char b=t[i];
            if (s_map[a]!=t_map[b])return false;
            s_map[a]=i+1;
            t_map[b]=i+1;
        }
        return true;
    }
};
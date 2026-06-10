class Solution {
public:
    int residuePrefixes(string s) {
        vector<int> freq(26,0);
        int dist=0;
        int ans=0;
        for(int i=0;i<s.size();i++) {
            int index=s[i]-'a';
            if (freq[index]!=1 && freq[index]==0)
                dist++;
            freq[index]++;
            int lmod=(i+1)%3;
            if (dist==lmod)
                ans++;
        }
        return ans;
    }
};

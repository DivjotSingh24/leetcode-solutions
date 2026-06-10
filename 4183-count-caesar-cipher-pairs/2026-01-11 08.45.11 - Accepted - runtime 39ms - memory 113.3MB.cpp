class Solution {
public:
    long long countPairs(vector<string>& words) {
        using ll=long long;
        unordered_map<string,ll> mp;
        for(int i=0;i<words.size();i++) {
            string w=words[i];
            int shift=w[0]-'a';
            string key=w;

            for(int j=0;j<w.size();j++) {
                int val=(w[j]-'a'-shift+26)%26;
                key[j]=char('a'+val);
            }
            mp[key]++;
        }
        ll ans=0;
        for(auto &p : mp) {
            ll c=p.second;
            ans+=c*(c-1)/2;
        }
        return ans;
    }
};

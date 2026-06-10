class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int t1=count(s.begin(),s.end(),'1');
        int t0=n-t1;
        // if(t1==0 || t0==0) return 0;
        vector<int> p1(n+1,0);
        for(int i=0;i<n;i++){
            p1[i+1]=p1[i]+(s[i]=='1' ? 1 : -1);
        }
        unordered_map<int,vector<int>> f;
        for(int i=0;i<=n;i++){
            f[p1[i]].push_back(i);
        }
        unordered_map<int,int> first;
        for(int i=0;i<=n;i++){
            if(!first.count(p1[i])){
                first[p1[i]]=i;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int pref=p1[i];
            if(first.count(pref)){
                ans=max(ans,i-first[pref]);
            }
            if(f.count(pref-2)){
                auto &p=f[pref-2];
                int mini=i-2*t0;
                auto it = lower_bound(p.begin(),p.end(),mini);
                if(it!=p.end() && *it<i){
                    ans=max(ans,i-*it);
                }
            }
            if(f.count(pref+2)){
                auto &p=f[pref+2];
                int mini=i-2*t1;
                auto it = lower_bound(p.begin(),p.end(),mini);
                if(it!=p.end() && *it<i){
                    ans=max(ans,i-*it);
                }
            }
        }
        return ans;
    }
};
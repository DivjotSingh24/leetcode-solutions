class Solution {
public:
    using ll=long long;
    long long countCommas(long long n) {
        ll ans=0;
        ll start=1000;
        int commas=1;
        while(start<=n){
            ll end=start*1000-1;
            ll count=min(n,end) -start+1;
            ans+= count*commas;
            start*=1000;
            commas++;
        }
        return ans;
    }
};
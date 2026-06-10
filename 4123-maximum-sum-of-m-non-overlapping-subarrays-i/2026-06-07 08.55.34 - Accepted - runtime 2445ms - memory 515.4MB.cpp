class Solution {
public:
    using ll=long long;
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n=nums.size();
        vector<ll> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        const ll NEG=-4e18;
        vector<vector<ll>> dp(m+2,vector<ll>(n+2,NEG));
        for(int i=0;i<=n;i++){
            dp[0][i]=0;
        }
        for(int t=1;t<=m;t++){
            multiset<ll> st;
            for(int i=1;i<=n;i++){
                dp[t][i]=dp[t][i-1];
                if(i-l>=0){
                    st.insert(dp[t-1][i-l]-pref[i-l]);
                }
                if(i-r-1>=0){
                    st.erase(st.find(dp[t-1][i-r-1]-pref[i-r-1]));
                }
                if(!st.empty()){
                    dp[t][i]=max(dp[t][i],pref[i]+*st.rbegin());
                }
            }
        }
        ll ans=NEG;
        for(int i=1;i<=m;i++){
            ans=max(ans,dp[i][n]);
        }
        return ans;
    }
};
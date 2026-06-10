class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n=nums.size();
        const long long NEG=-(long long)4e18;
        vector<long long>dp(2,NEG);
        dp[s[0]=='1']=0;
        for(int i=0;i<n;i++){
            vector<long long> ndp(2,NEG);
            int b=(i+1<n && s[i+1]=='1');
            for(int j=0;j<=1;j++){
                if(dp[j]==NEG) continue;
                ndp[b]=max(ndp[b],dp[j]);
                if(j){
                    ndp[b]=max(ndp[b],dp[j]+nums[i]);
                }
                if(b){
                    ndp[0]=max(ndp[0],dp[j]+nums[i]);
                }
            }
            dp.swap(ndp);
        }
        return max(dp[0],dp[1]);
    }
};
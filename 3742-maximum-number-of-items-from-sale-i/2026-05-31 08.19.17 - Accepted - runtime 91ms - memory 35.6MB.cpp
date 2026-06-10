class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> free(n+5,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0] % items[i][0]==0){
                    free[i]++;
                }
            }
        }
        int mini=INT_MAX;
        for(auto& item:items){
            mini=min(mini,item[1]);
        }
        //we would now apply dp  here as to make it optimal jaise next ques also has worse constraints so we need an optimal approach
        vector<int> dp(budget+5,-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int pp=items[i][1];
            int prof=1+free[i];
            for(int j=budget;j>=pp;j--){
                if(dp[j-pp]>=0){
                    dp[j]=max(dp[j],dp[j-pp]+prof);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=budget;i++){
            if(dp[i]<0){
                continue;
            }
            int left=budget-i;
            int ext=left/mini;
            ans=max(ans,dp[i]+ext);
        }
        return ans;
    }
};
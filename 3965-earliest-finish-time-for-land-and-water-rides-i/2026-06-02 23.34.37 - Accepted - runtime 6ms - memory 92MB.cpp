class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n=landStartTime.size();
        int m=waterStartTime.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int l=landStartTime[i]+landDuration[i];
                int lw=max(l,waterStartTime[j])+waterDuration[j];
                ans=min(ans,lw);
                int w=waterStartTime[j]+waterDuration[j];
                int wl=max(w,landStartTime[i])+landDuration[i];
                ans=min(ans,wl);
            }
        }
        return ans;
    }
};
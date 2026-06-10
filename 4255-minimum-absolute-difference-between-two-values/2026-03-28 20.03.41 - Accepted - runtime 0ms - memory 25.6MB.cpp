class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int l=-1;
        int r=-1;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                l=i;
                if(r!=-1){
                    ans=min(ans,abs(l-r));
                }
            }
            else if(nums[i]==2){
                r=i;
                if(l!=-1){
                    ans=min(ans,abs(l-r));
                }
            }
        }
        return (ans==INT_MAX) ? -1:ans;
    }
};
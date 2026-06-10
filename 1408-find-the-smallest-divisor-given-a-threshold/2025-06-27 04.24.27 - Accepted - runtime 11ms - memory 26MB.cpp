class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=INT_MIN;
        int ans=-1;
        for (int i=0;i<nums.size();i++){
            if (nums[i]>high){
                high=nums[i];
            }
        }

        while (low<=high){
            int sum=0;
            int mid=(low+high)/2;
            for (int i=0;i<nums.size();i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            
            if (sum<=threshold){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};
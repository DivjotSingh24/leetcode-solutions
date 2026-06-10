class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=INT_MIN;
        int high=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]>low){
                low=nums[i];
            }
            high+=nums[i];
        }
        int ans=-1;
       
        while(low<=high){
        int sum=0;
        int sum2=0;
        int subarrays=1;
            int mid=(low+high)/2;
            for (int i=0;i<nums.size();i++){
                 if (sum+nums[i]>mid){
                    subarrays++;
                    sum=0;
                 } 
                 sum+=nums[i];
                 

            }
                 
        
        if (subarrays<=k){
                    ans=mid;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            
        }

        return ans;





    }
};
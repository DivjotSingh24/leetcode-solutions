class Solution {
public:
    int non_empty(vector<int>& nums, int tot){
        int sub=1;
        long long tot_subarray=0;
        for(int i=0;i<nums.size();i++){
            if(tot_subarray+nums[i]<=tot){
                tot_subarray+=nums[i];
            }
            else{
                sub++;
                tot_subarray=nums[i];
            }
        }
        return sub;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(high+low)/2;
            int tot_subarrays=non_empty(nums, mid);
            if(tot_subarrays>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};
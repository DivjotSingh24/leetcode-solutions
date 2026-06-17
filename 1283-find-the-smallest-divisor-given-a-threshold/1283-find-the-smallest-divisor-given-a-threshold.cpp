class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low= 1;
        int n=nums.size();
        int high=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>high){
                high=nums[i];
            }
        }
        while(low<=high){
            int mid=(high+low)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold){
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
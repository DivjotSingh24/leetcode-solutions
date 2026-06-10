class Solution {
public:
    int minimumCost(vector<int>& nums) {
        for(int i=1;i<=2;i++){
            int m=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[m]){
                    m=j;
                }
            }
            swap(nums[i],nums[m]);
        }
        return nums[0]+nums[1]+nums[2];
    }
};
class Solution {
public:
    int countHillValley(vector<int>& nums) {
      int val=0;
        for (int i=1;i<nums.size()-1;i++){
            
            if (nums[i]==nums[i-1]){
                continue;
            }
            int left=i-1;
            while(left >0 &&nums[left]==nums[i]){
                left--;
            }
            int right=i+1;
            while(right<nums.size()-1 && nums[right]==nums[i]){
                right++;
            }
            if ((nums[i]>nums[left] && nums[i]>nums[right]) || (nums[i]<nums[left] && nums[i]<nums[right])){
                val++;
            }
        }
       return val; 
    }
};
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int>freq;
        int left=0;
        int result=0;
        int sum=0;
        
        for (int right=0;right<nums.size();right++){
            freq[nums[right]]++;
            sum+=nums[right];
            while(freq[nums[right]]>1){
                freq[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            
            result=max(sum,result);


           
        }
        
       
        return result;
    }
};
class Solution {
public:
    int func(vector<int>& nums, int k){
        if(k<0) return 0;
        int left = 0;
        int right = 0;
        int count = 0;
        int answer = 0;
        while(right<nums.size()){
            if(nums[right]%2 == 1){
                count++;
            }
            while(count>k){
                if(nums[left]%2 == 1) count--;
                left++;
            }
            answer += (right-left+1);
            right++;
        }
        return answer;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};
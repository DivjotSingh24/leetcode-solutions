class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int left = 0;
        int right = 0;
        vector<int> ans;
        // int max = INT_MIN;
        while(right<k){
            while(!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back();
            dq.push_back(right);
            right++;
        }
        ans.push_back(nums[dq.front()]); 
        // right--;
        while(right<nums.size()){
            while(!dq.empty() && dq.front() <= right-k) dq.pop_front();  
            while(!dq.empty() && nums[dq.back()] <= nums[right]) dq.pop_back();
            dq.push_back(right);
            ans.push_back(nums[dq.front()]);
            left++;
            right++;
        }
        return ans;
    }
};
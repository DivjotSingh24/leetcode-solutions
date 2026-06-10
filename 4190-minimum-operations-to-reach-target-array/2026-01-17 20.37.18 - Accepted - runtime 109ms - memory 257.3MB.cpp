class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        unordered_set<int> s;
        
        // int ans=0;
        for(int i=0;i<n;i++){
            // if(nums[i]!=target[i] && (i==0||nums[i]!=nums[i-1]))
            //         ans++;
            if(nums[i]!=target[i])
                s.insert(nums[i]);
        }
        return s.size();
    }
};
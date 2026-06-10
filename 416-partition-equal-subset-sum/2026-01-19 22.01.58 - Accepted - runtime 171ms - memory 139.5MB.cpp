class Solution {
public:
    bool halfExists(vector<int>& nums, int ind, int target, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == nums.size()) return false;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTaken = halfExists(nums, ind+1, target, dp);
        bool taken = false;
        if(target>=nums[ind]){
            taken = halfExists(nums, ind+1, target-nums[ind], dp);
        }
        return dp[ind][target] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2+1, -1));
        if(sum % 2 == 1) return false;
        return halfExists(nums, 0, sum/2, dp);
    }
};
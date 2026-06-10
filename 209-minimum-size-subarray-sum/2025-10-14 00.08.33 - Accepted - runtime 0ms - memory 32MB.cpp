class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        long long sum = 0;
        int best = INT_MAX;
        for (int right = 0; right < n; ++right) {
            sum += nums[right];
            while (sum >= target) {
                best = min(best, right - left + 1);
                sum -= nums[left];
                ++left;
            }
        }
        return (best == INT_MAX) ? 0 : best;
    }
};
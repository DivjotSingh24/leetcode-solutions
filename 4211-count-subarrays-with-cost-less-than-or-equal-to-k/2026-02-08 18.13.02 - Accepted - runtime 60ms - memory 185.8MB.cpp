class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, j = 0;
        deque<int> mx, mn;

        for (int i = 0; i < nums.size(); i++) {
            while (mx.size() && nums[mx.back()] <= nums[i]) mx.pop_back();
            while (mn.size() && nums[mn.back()] >= nums[i]) mn.pop_back();
            mx.push_back(i);
            mn.push_back(i);

            while (j <= i && (nums[mx.front()] - nums[mn.front()]) * (i - j + 1) > k) {
                if (mx.front() == j) mx.pop_front();
                if (mn.front() == j) mn.pop_front();
                j++;
            }
            ans += i - j + 1;
        }
        return ans;
    }
};
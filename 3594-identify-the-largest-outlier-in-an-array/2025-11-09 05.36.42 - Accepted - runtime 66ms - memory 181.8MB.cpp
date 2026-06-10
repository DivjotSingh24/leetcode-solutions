class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        for (auto it : nums) {
            freq[it]++;
        }

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            long long target = sum - nums[i];
            if (target % 2 != 0) continue;
            long long half = target / 2;
            if(nums[i]==half && freq[nums[i]]<2) continue;
            if (freq.count(half)) {
                maxi = max(maxi, nums[i]);
            }
        }

        return maxi;
    }
};

using ll = long long;
class Solution {
public:
    ll maximumTotalDamage(vector<int>& power) {
        unordered_map<ll, int> mpp;
        for (int x : power) {
            mpp[x]++;
        }

        vector<ll> nums; 
        for (auto& [val, freq] : mpp) {
            nums.push_back(val);
        }
        sort(nums.begin(), nums.end()); 

        int n = nums.size();
        vector<ll> dp(n + 1, 0); 

        ll damage = 0; 

        for (int i = n - 1; i >= 0; --i) {
            ll skip = 0;
            if (i + 1 < n) { 
                skip = dp[i + 1];
            }
            ll curr = nums[i] * mpp[nums[i]];

            auto it = lower_bound(nums.begin() + i + 1, nums.end(), nums[i] + 3);
            int j = it - nums.begin(); 

            ll take_from_future = 0;
            if (j < n) { 
                take_from_future = dp[j];
            }
            ll take = curr + take_from_future;
            dp[i] = max(skip, take);
            damage = max(damage, dp[i]);
        }
        return damage;
    }
};
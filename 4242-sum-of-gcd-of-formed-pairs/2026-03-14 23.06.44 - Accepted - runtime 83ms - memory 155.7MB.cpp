typedef long long ll;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        vector<int> pref(n);

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            pref[i] = gcd(maxi, nums[i]);
        }

        sort(pref.begin(), pref.end());

        int l = 0, r = n - 1;
        ll ans = 0;

        while(l < r) {
            ans += gcd(pref[l++], pref[r--]);
        }

        return ans;
    }
};
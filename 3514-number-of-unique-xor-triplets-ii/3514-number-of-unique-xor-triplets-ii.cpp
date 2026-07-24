class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<char> p(2048, 0), r(2048, 0), vis(2048, 0);
        vector<int> d;
        for (int x : nums)
            if (!vis[x]) {
                vis[x] = 1;
                d.push_back(x);
            }
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                p[nums[i] ^ nums[j]] = 1;
        for (int v = 0; v < 2048; v++)
            if (p[v])
                for (int x : d)
                    r[v ^ x] = 1;
        return count(r.begin(), r.end(), 1);
    }
};
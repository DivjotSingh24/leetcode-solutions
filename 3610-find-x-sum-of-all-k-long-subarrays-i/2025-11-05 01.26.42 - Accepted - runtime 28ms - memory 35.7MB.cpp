class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i + k <= n; ++i) {
            map<int, int> freq; 
            for (int j = i; j < i + k; ++j) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> elements;
            elements.reserve(freq.size());
            for (auto& p : freq) {
                elements.push_back({p.second, p.first});
            }
            sort(elements.begin(), elements.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            int take = min(x, (int)elements.size());
            for (int t = 0; t < take; ++t) {
                sum += elements[t].first * elements[t].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

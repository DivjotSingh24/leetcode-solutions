class Solution {
public:
    int maxOr = 0;
    int count = 0;

    void dfs(vector<int>& nums, int i, int currOr) {
        if (i == nums.size()) {
            if (currOr == maxOr) {
                count++;
            } else if (currOr > maxOr) {
                maxOr = currOr;
                count = 1;
            }
            return;
        }
        dfs(nums, i + 1, currOr | nums[i]);
        dfs(nums, i + 1, currOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        dfs(nums, 0, 0);
        return count;
    }
};

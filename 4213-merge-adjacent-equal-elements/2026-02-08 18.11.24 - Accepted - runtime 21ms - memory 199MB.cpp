class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans;
        for(int i=0;i<n;i++){
            long long curr=nums[i];
            while(ans.size() && ans.back() == curr){
                ans.pop_back();
                curr *= 2;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
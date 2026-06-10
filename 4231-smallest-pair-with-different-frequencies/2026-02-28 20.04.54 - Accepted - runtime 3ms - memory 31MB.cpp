class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){
            freq[num]++;
        }
        vector<int> ans;
        for(auto &p : freq){
            ans.push_back(p.first);
        }
        if(ans.size()<2){
            return {-1, -1};
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<ans.size();i++){
            for(int j=i+1;j<ans.size();j++){
                if(freq[ans[i]]!=freq[ans[j]]){
                    return {ans[i],ans[j]};
                }
            }
        }
        return {-1,-1};
    }
};
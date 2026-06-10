class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>targ;
        for(int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    targ.push_back(nums[i]);

                    break;
                }
            }
        }
        return targ;
    }
};
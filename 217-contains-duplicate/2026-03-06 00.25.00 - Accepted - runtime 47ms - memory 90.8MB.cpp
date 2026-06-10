class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numset;
        for(int x:nums){
            if(numset.find(x)!=numset.end()){
                return true;
            }
            numset.insert(x);
        }  
        return false;
    }
};
//Hashing --> optimal solution for just getting the indexes, but better approach for yes/no, since optimal for that would be 2  pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int moreNeeded=target-num;
            if(mpp.find(moreNeeded)!=mpp.end()){
                return{mpp[moreNeeded],i};
            }
            mpp[num]=i;
        }
        return {-1,-1};
    }
};
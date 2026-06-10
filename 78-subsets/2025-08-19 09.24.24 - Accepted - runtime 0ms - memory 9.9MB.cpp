class Solution {
public:
void backtrack(int start,vector<int>&path,vector<int> &nums,vector<vector<int>> &result){
    result.push_back(path);

    for( int i=start;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrack(i+1,path,nums,result);
        path.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector <vector<int>> result;
        vector <int> path;
        backtrack(0,path,nums,result);
        return result;
        
    }
};
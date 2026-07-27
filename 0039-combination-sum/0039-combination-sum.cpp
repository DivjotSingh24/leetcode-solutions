class Solution {
public:

    void solve(int index,int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        // combination found
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        // no elements left
        if(index == arr.size())
            return;
        // take current element
        if(arr[index] <= target){
            ds.push_back(arr[index]);
            // stay on same index
            solve(index, target-arr[index], arr, ans, ds);
            ds.pop_back();
        }
        // don't take current element
        solve(index+1, target, arr, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,target,candidates,ans,ds);
        return ans;
    }
};
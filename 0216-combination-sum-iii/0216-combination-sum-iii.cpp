class Solution {
public:
    //target is basically the remaining sum we need to achieve
    void solve(int start, int k, int target, vector<vector<int>> &ans, vector<int> &ds ){
        if(k==0){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            ds.push_back(i);
            solve(i+1,k-1,target-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ans,ds);
        return ans;
    }
};
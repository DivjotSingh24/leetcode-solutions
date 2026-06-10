class Solution {
public:
    void dfs(string curr , int &n, vector<string>&ans){
        if(curr.size()==n) {ans.push_back(curr);return;}
        for(int i=0;i<3;i++){
            char c = 'a'+i;
            if(curr.empty()||curr.back()!=c){
                curr+=c;
                dfs(curr,n,ans);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        dfs("" , n , ans);
        if(ans.size()<k) return "";
        return ans[k-1];
    }
};
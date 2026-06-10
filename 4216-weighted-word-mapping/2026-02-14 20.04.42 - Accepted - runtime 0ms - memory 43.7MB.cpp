class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string &word :words){
            int total=0;
            for(char c:word){
                total+=weights[c-'a'];
            }
            int rem=total%26;
            char mapp='z'-rem;
            ans+=mapp;
        }
        return ans;
    }
};
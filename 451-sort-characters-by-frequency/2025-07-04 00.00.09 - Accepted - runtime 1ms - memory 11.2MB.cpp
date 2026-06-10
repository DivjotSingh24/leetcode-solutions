class Solution {
public:
    string frequencySort(string s) {
        map<char,int>freq;
        for (char ch:s){
            freq[ch]++;
        }
        vector<pair<char,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](pair<char,int>&a ,pair<char,int> &b){
            return a.second>b.second;
        });
        string ans="";
        for (auto& it:vec){
            ans.append(it.second,it.first);
        }
        return ans;
    }
};
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_set<string> vis;
        unordered_set<string> group;
        for(string &word : words){
            if(word.length()<k) continue;
            string prefix=word.substr(0,k);
            if(vis.count(prefix)){
                group.insert(prefix);
            }
            else{
                vis.insert(prefix);
            }
        }
        return group.size();
    }
};
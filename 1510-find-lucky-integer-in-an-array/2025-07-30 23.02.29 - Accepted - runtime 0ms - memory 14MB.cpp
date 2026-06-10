class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mpp;
        int val=-1;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        for (auto it:mpp){
            if(it.second==it.first){
                val=max(val,it.first);
            }
        }
        
        return val;
    }
};
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>freqc;
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }
        for(auto &f : freq){
            freqc[f.second]++;
        }
        for(int num:nums){
            if(freqc[freq[num]]==1){
                return num;
            }
        }
        return -1;
    }
};
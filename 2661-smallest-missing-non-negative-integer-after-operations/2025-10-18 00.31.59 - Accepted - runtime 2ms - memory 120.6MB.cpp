class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int>count(value+1,0);
        for(int i:nums){
            if(i<0) count[((i%value)+value)%value]++;
            else count[i%value]++;
        }
        for(int i=0;i<=n;i++){
            int ind = i%value;
            if(count[ind]==0) return i;
            count[ind]--;
        }
        return n;             
    }
};
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        int rep=-1;
        int miss=-1;
        for(int i=1;i<=n;i++){
            if(hash[i]==0) miss=i;
            else if(hash[i]==2) rep=i;
            if(rep!=-1 && miss!=-1) break;
        }
        return{rep,miss};
    }
};
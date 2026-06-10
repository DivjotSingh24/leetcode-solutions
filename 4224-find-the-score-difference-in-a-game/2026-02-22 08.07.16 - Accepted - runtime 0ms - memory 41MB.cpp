class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n=nums.size();
        int firstS=0;
        int secondS=0;
        bool active=true;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                active=!active;
            }
            if(i%6==5){
                active=!active;
            }
            if(active){
                firstS+=nums[i];
            }
            else{
                secondS+=nums[i];
            }
        }
        return firstS-secondS;
    }
};
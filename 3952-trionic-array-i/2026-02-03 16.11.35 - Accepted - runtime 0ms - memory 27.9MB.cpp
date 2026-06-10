class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        bool i1=false;
        bool d=false;
        bool i2=false;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(!i1) i1=true;
                else if(i1 && !d) continue;
                else if(i1 && d && !i2) i2=true;
            }
            else if(nums[i]<nums[i-1]){
                if(i1 && !d) d=true;
                else if(i1 && d && !i2) continue;
                else if(i1 && d && i2) return false;
                else return false;
            }
            else{
                return false;
            }
        }
        return (i1 && i2 && d);
    }
};
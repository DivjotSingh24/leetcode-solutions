class Solution {
public:
    void ShiftLeft(vector<int> &nums, int idx){
        int n=nums.size();
        for(int i=idx;i<n-1;i++){
            nums[i]=nums[i+1];
        }
        nums.pop_back(); //to remove the last empty space
    }
    void mergePairs(vector<int> &nums){
        int n=nums.size();
        int minSum=INT_MAX, minIdx=-1;
        for(int i=0;i<n-1;i++){
            int sum=nums[i]+nums[i+1];
            if(sum<minSum){
                minSum=sum;
                minIdx=i;
            }
        }
        nums[minIdx]=minSum;
        ShiftLeft(nums,minIdx+1);
    }
    bool isSorted(vector<int> &nums){  //to check if elements are sorted or not
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        while(!isSorted(nums)){
            mergePairs(nums);
            ans++;
        }
        return ans;
    }
};
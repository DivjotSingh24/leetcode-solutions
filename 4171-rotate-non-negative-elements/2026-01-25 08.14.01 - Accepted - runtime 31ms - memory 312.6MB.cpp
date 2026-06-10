class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> non;
        for(int x:nums){
            if(x>=0) non.push_back(x);
        }
        int num_non=non.size();
        if(num_non<=0) return nums;
        k%=num_non;

        vector<int> rot(num_non);
        for(int i=0;i<num_non;i++){
            rot[i]=non[(i+k)%num_non];
        }
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                nums[i]=rot[idx++];
            }
            else continue;
        }
        return nums;
    }
};
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int start=0;start<n;start++) {
            for(int end=start;end<n;end++) {
                int sum=0;
                for(int i=start;i<= end;i++) {
                    sum+=nums[i];         
                }
                bool found=false;
                for(int i=start;i<=end;i++) {
                    if (nums[i]==sum) {   
                        found=true;
                        break;
                    }
                }
                if (found)
                    count++;
            }
        }
        return count;
    }
};

class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n=nums.size();
        using ll=long long;
        ll p2=nums[0];
        ll p1;
        if(n==1) return nums[0];
        if(colors[1]!= colors[0]){
            p1=nums[0]+nums[1];
        }
        else{
            p1=max(nums[0],nums[1]);
        }
        for(int i=2;i<n;i++){
            ll curr;
            if(colors[i]!=colors[i-1]){
                curr=p1+nums[i];
            }
            else{
                curr=max(p1, p2+nums[i]);
            }
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
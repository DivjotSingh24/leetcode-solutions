class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int count_even=0;
        int count_odd=0;
        for(auto x:nums1){
            if(x%2==0) count_even++;
            else
                count_odd++;
        }
        if(count_even==n || count_odd==n){
            return true;
        }
        int mini=1e9+1;
        for(auto x:nums1){
            if(x%2==1){
                mini=min(mini,x);
            }
        }
        for(auto x:nums1){
            if(x%2==0 && x-mini<1){
                return false;
            }
        }
        return true;
    }
};
//here we are using binary search in such a way where it consists of all the possible weights a ship can carry aka the capacity
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>low){
                low=weights[i];
            }
            high+=weights[i];
        }
        int ans=-1;
        while(low<=high){
            int no_of_days=1;
            int load=0;
            int mid=(low+high)/2;
            for(int i=0;i<weights.size();i++){
                if(load+weights[i]>mid){
                    no_of_days++;
                    load=0;
                }
                load+=weights[i];
            }
            if(no_of_days<=days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
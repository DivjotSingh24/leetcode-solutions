class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for (int i=0;i<weights.size();i++){
            if (weights[i]>low){
                low=weights[i];
               
            }   
             high+=weights[i];
        }
 int ans=-1;
        while (low<=high){
            int mid=(low+high)/2;
           
            int curr=0;
            int day=1;
            for (int i=0;i<weights.size();i++){
            if (curr+weights[i]>mid){
                day++;
                curr=0;

            }
            curr+=weights[i];}
            if (day<=days){
                ans=mid;
                high=mid-1;
            }
            else {
                low=mid+1;
            }

            
        }
        return ans;
    }
};
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        int ans;
        for (int i=0;i<piles.size();i++){
            if (piles[i]>high){
                high=piles[i];
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhr=0;
            for (int i=0;i<piles.size();i++){
                 totalhr+=(piles[i]+mid-1LL)/mid;

            }
           
            
            if (totalhr<=h){
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
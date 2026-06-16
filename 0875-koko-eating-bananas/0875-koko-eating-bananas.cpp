class Solution {
public:
    long long calchours(vector<int> &p, int hourly){
        long long total=0;
        for(int i=0;i<p.size();i++){
            total+=(long long)ceil((double)p[i]/(double) hourly);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        int ans;
        int p=piles.size();
        //setting the uppper limit for binary search
        for (int i=0;i<p;i++){
            if (piles[i]>high){
                high=piles[i];
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhr=0;
            totalhr=calchours(piles,mid);
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
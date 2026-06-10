class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long) m*k>bloomDay.size()) return -1;
        int ans=-1;
        int min=INT_MAX;
        int max=INT_MIN;
        for (int i=0;i<bloomDay.size();i++){
            
            if (bloomDay[i]>max){
                max=bloomDay[i];
            }
            if (bloomDay[i]<min){
                min=bloomDay[i];
            }
        }
        
    


    int low=min;
    int high=max;
    while(low<=high){
        int mid=(low+high)/2;
        int flowers=0;
        int bouquet=0;
        for (int i=0;i<bloomDay.size();i++){
            if (bloomDay[i]<=mid){
                flowers++;
                 if (flowers==k){
                bouquet++;
                flowers=0;
            }
            }
           else{
            flowers=0;
           }
        }

        if (bouquet>=m){
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
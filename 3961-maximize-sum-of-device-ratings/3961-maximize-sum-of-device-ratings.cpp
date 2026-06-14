class Solution {
public:
    using ll=long long;
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        int n=units[0].size();
        if(n==1){
            ll sum=0;
            for(int i=0;i<m;i++){
                sum+=units[i][0];
            }
            return sum;
        }
        ll minig=INT_MAX;
        ll sum1=0;
        ll mini=INT_MAX;
        for(int i=0;i<m;i++){
            ll mini1=INT_MAX;
            ll mini2=INT_MAX;
            for(int j=0;j<n;j++){
                ll x=units[i][j];
                if(x<mini1){
                    mini2=mini1;
                    mini1=x;
                }
                else if(x<mini2){
                    mini2=x;
                }
            }
            if(mini1<minig){
                minig=mini1;
            }
            sum1+=mini2;
            if(mini2<mini){
                mini=mini2;
            }
        }
        return minig+sum1-mini;
    }
};
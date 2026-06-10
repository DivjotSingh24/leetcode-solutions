//observation-: either all +ve, odd -ve, even -ve, has zeroes
//can also be done using kadane's but prefer doing it with prefix suffix
class Solution {
public:
    using ll=long long;
    int maxProduct(vector<int>& arr) {
        int n=arr.size();
        ll maxi=INT_MIN;
        ll pref=1;
        ll suff=1;
        for(ll i=0;i<n;i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref=pref*arr[i];
            suff=suff*arr[n-i-1];
            maxi=max(maxi,max(pref,suff));
        }
        return maxi;
    }
};
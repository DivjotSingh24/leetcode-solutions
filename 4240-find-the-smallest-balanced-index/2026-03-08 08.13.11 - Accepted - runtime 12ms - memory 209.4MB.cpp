class Solution {
public:
    int smallestBalancedIndex(vector<int>& arr) {
        int n=arr.size();
        using ll=long long;
        const ll lim=2e14;
        vector<ll> rp(n+1);
        rp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(rp[i+1]>lim/arr[i])
                rp[i]=lim;
            else
                rp[i]=rp[i+1]*arr[i];
        }
        ll ls=0;
        for(int i=0;i<n;i++){
            if(ls==rp[i+1])
                return i;
            ls+=arr[i];
        }
        return -1;
    }
};
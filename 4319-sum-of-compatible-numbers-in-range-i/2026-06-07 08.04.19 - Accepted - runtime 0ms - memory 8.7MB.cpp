class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        // int x=max(1,n-k);
        for(int x=max(1,n-k);x<=n+k;x++){
            if((n&x)==0){
                ans+=x;
            }
        }
        return ans;
    }
};
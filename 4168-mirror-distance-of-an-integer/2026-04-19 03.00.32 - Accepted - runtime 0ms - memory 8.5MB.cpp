class Solution {
public:
    int rev(int n){
        int x=0;
        while(n>0){
            x=x*10+(n%10);
            n/=10;
        }
        return x;
    }
    int mirrorDistance(int n) {
        return abs(rev(n)-n);
    }
};
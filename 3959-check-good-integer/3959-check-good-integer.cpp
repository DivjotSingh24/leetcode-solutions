class Solution {
public:
    bool checkGoodInteger(int n) {
        int digi=0;
        int sq=0;
        while(n>0){
            int x=n%10;
            digi+=x;
            sq+=x*x;
            n/=10;
        }
        return(sq-digi)>=50;
    }
};
class Solution {
public:
    static const long long MOD=1e9+7;
long long modPow(long long base,long long exp){
  
    long long ans=1;
    if (exp==0)return 1;
    long long half=modPow(base,exp/2);;
    if (exp%2==0){
        return (half*half)%MOD;
        
    }
    else{
        return ((half*half)%MOD*base)%MOD;
    }
}
    int countGoodNumbers(long long n) {
    
        long long evenC=(n+1)/2;
        long long oddC=n/2;
        long long evens=modPow(5,evenC);
        long long odds=modPow(4,oddC);
        return (evens*odds)%MOD;
        
    }
};
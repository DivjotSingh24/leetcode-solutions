class Solution {
public:
    const int maxn=200005;
        vector<bool> prime;
        //sieve of erasthoneses use krra, IMPORTANT
        void sieve(){
            prime.assign(maxn,true);
            prime[0]=prime[1]=false;
            for(int i=2;i*i<maxn;i++){
                if(prime[i]){
                    for(int j=i*i;j<maxn;j+=i){
                        prime[j]=false;
                    }
                }
            }
        }
    int minOperations(vector<int>& nums) {
        sieve();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(i%2==0){
                while(!prime[x]){
                    x++;
                    ans++;
                }
            }
            else{
                while(prime[x]){
                    x++;
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int countMonobit(int n) {
        int ans=0;
        for(int i=0;i<=n;i++){
            if(i==0){
                ans++;
                continue;
            }
            int x=i;
            int cnt0=0, cnt1=0;
            while(x>0){
                if(x & 1) cnt1++;
                else cnt0++;
                x>>=1;
            }
            if(cnt0==0 || cnt1==0) ans++;
        }
        return ans;
    }
};
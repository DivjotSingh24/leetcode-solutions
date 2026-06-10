class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        long long time=0;
        long long t=inter.size();
        long long linter=inter[0][0];
        long long rinter=inter[0][1];
        for(int i=1;i<t;i++){
            if(inter[i][0]<=rinter+1){
                rinter=max(rinter, (long long)inter[i][1]);
            }
            else{
                time+=(rinter-linter+1);
                linter=inter[i][0];
                rinter=inter[i][1];
            }
        }
        time+=(rinter-linter+1);
        long long b=0;
        while(brightness>0){
            b++;
            brightness-=3;
        }
        return b*time;
    }
};
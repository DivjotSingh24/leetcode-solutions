class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]==0){
                continue;
            }
            int l=max(0,i-lights[i]);
            int r=min(n-1,i+lights[i]);
            diff[l]++;
            if(r+1<n){
                diff[r+1]--;
            }
        }
        int curr=0;
        int ans=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(curr==0){
                ans++;
                int pre=min(i+1,n-1);
                int l=max(0,pre-1);
                int r=min(n-1,pre+1);
                diff[l]++;
                if(r+1<n){
                    diff[r+1]--;
                }
                if(l<=i){
                    curr++;
                }
            }
        }
        return ans;
    }
};
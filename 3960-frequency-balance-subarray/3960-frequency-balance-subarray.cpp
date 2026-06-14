class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int l=0;l<n;l++){
            unordered_map<int,int> freq;
            unordered_map<int,int> cnt;
            for(int r=l;r<n;r++){
                int x=nums[r];
                // bool ok=false;
                if(freq[x]>0){
                    cnt[freq[x]]--;
                    if(cnt[freq[x]]==0){
                        cnt.erase(freq[x]);
                    }
                }
                freq[x]++;
                cnt[freq[x]]++;
                bool ok=false;
                if(freq.size()==1){
                    ok=true;
                }
                else if(cnt.size()==2){
                    auto it=cnt.begin();
                    int fi=it->first;
                    ++it;
                    int fii=it->first;
                    int mini=min(fi,fii);
                    int maxi=max(fi,fii);
                    if(maxi==2*mini){
                        ok=true;
                    }
                }
                if(ok){
                    ans=max(ans,r-l+1);
                }
            }
        }
        return ans;
    }
};
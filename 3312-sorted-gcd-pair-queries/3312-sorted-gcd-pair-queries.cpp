class Solution {
public:
    using ll = long long;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<ll>freq(mx+1,0) , total(mx+1,0);
        for(int i:nums) freq[i]++;
        for(int i=1;i<=mx;i++){
            for(int j=i*2;j<=mx;j+=i){
                freq[i]+=freq[j];
            }
        }

        for(int i=1;i<=mx;i++){
            if(freq[i]>1)
            total[i] = 1LL*freq[i]*(freq[i]-1)/2;
        }
        for(int i=mx;i>=1;i--){
            for(int j=i*2;j<=mx;j+=i){
                total[i]-=total[j];
            }
        }
        for(int i=1;i<=mx;i++) total[i]+=total[i-1];
        vector<int> ans;
        ans.reserve(queries.size());
        for(ll q:queries){
            ans.push_back(upper_bound(total.begin()+1,total.end(),q)-total.begin());
        }
        return ans;
    }
};
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();

        vector<vector<int>>vp;
        for(int i=0; i<n; i++) {
            int c = costs[i], cap = capacity[i];
            vp.push_back({c,cap});
        }

        sort(vp.begin(),vp.end());

        map<int,int>maxCap;

        int x = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(vp[i][0] < budget) {
                auto it = maxCap.lower_bound(budget-vp[i][0]-1);
                if(it == maxCap.end()) ans = max(ans, vp[i][1] + x);
                else if(it->first < (budget-vp[i][0])) ans = max(ans, vp[i][1] + it->second);
                else if(it != maxCap.begin()) {
                    it--;
                    if(it->first < (budget-vp[i][0])) ans = max(ans, vp[i][1] + it->second);
                }
                
                ans = max(ans,vp[i][1]);
            }

            x = max(x,vp[i][1]);
            maxCap[vp[i][0]] = x;
        }

        return ans;
    }
};
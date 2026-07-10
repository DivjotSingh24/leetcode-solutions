class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        vector<int> val(n), spos(n);
        for (int i = 0; i < n; i++) {
            val[i] = arr[i].first;
            spos[arr[i].second] = i;
        }
        vector<int> R(n);
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(val.begin(), val.end(), val[i] + maxDiff);
            R[i] = int(it - val.begin()) - 1;
        }
        vector<int> comp(n, -1);
        {
            int c = 0, i = 0;
            while (i < n) {
                comp[i] = c;
                int pos = R[i];
                comp[pos] = c;
                if (i == pos) {
                    c++;
                    i++;
                } else
                    i = pos;
            }
            for (int k = 1; k < n; k++)
                comp[k] = max(comp[k - 1], comp[k]);
        }
        int LOG = 1;
        while ((1 << LOG) < n)
            LOG++;
        LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = R;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;
        for (auto& q : queries) {
            int u = spos[q[0]];
            int v = spos[q[1]];
            if (u > v)
                swap(u, v);
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            if (comp[u] != comp[v]) {
                ans.push_back(-1);
                continue;
            }
            int cur = u, hops = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < v) {
                    cur = up[k][cur];
                    hops += (1 << k);
                }
            } 
            hops++;
            ans.push_back(hops);
        } 
        return ans;
    }
};
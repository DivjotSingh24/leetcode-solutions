class Solution {
public:
    int ans = 0;
    long long dfs(vector<int> adj[], vector<int> &values, int &k,vector<int> &vis, int cur)
    {
        vis[cur] = 1;
        long long sum = values[cur];
        for (int it : adj[cur])
        {
            if (!vis[it])
            {
                sum += dfs(adj, values, k, vis, it);
            }
        }
        if (sum % k == 0)
            ans++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,vector<int>& values, int k)
    {
        vector<int> adj[n];
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n, 0);
        dfs(adj, values, k, vis, 0);
        return ans;
    }
};
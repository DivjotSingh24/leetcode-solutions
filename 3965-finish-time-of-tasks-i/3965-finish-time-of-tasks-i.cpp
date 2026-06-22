class Solution {
public:
    using ll=long long;
    ll dfs(int u, vector<vector<int>> & adj, vector<int> & bt){
        if(adj[u].empty()){
            return bt[u];
        }
        ll e=LLONG_MAX;
        ll l=LLONG_MIN;
        for(int v: adj[u]){
            ll f=dfs(v,adj,bt);
            e=min(e,f);
            l=max(l,f);
        }
        return l+(l-e)+bt[u]; 
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& bt) {
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
        }
        return dfs(0,adj,bt);
    }
};
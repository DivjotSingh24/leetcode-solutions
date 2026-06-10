class Solution {
public:
    vector<int> bfs(int start, vector<vector<int>>&adj){
        int n=adj.size();
        vector<int> dist(n,-1);
        queue<int> q;
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u]){
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto& e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int cnt=0;
        vector<int> dx=bfs(x,adj);
        vector<int> dy=bfs(y,adj);
        vector<int> dz=bfs(z,adj);
        for(int u=0;u<n;u++){
            // vector<int> dx=bfs(x,adj);
            // vector<int> dy=bfs(y,adj);
            // vector<int> dz=bfs(z,adj);
            vector<int> dist={dx[u],dy[u],dz[u]};
            sort(dist.begin(),dist.end());
            long long a=dist[0],b=dist[1],c=dist[2];
            if(a*a+b*b==(c*c))
                cnt++;
        }
        return cnt;
    }
};
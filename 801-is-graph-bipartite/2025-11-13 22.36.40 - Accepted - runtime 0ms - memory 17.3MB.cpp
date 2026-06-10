class Solution {
public:
    bool dfs(int idx, int color, vector<vector<int>> &graph,vector<int> &colors,vector<int> &visited){
        if(visited[idx]) return colors[idx]==color;
        visited[idx] = 1;
        colors[idx] = color;
        for(auto node: graph[idx]){
            if(!dfs(node,1-color,graph,colors,visited)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> color(n,-1);
        vector<int> visited(n,0);
        for(int i = 0;i<n;i++){
            if(!visited[i])
            if(!dfs(i,0,graph,color,visited)) return false;
        }
        return true;
    }
};
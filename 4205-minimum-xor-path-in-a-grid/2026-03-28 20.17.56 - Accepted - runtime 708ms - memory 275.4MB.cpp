class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n,vector<bool>(1024,false)));
        queue<tuple<int,int,int>> q;
        q.push({0,0,grid[0][0]});
        vis[0][0][grid[0][0]]=true;
        int dx[2]={0,1};
        int dy[2]={1,0};
        while(!q.empty()){
            auto[i,j,x]=q.front();
            q.pop();
            for(int p=0;p<2;p++){
                int pi=i+dx[p];
                int pj=j+dy[p];

                if(pi<m && pj<n){
                    int px=x^ grid[pi][pj];
                    if(!vis[pi][pj][px]){
                        vis[pi][pj][px]=true;
                        q.push({pi,pj,px});
                    }
                }
            }
        }
        for(int x=0;x<1024;x++){
            if(vis[m-1][n-1][x]) return x;
        }
        return -1;
    }
};
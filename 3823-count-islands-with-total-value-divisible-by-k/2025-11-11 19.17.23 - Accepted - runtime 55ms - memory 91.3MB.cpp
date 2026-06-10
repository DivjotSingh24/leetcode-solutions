class Solution {
public:
    long long dfs(int row, int col, int rows, int cols,vector<vector<int>> &visited, vector<vector<int>> &grid){
        if(row<0 || col<0 || row>=rows || col>=cols || visited[row][col] || grid[row][col]==0) return 0;
        visited[row][col] = 1;
        long long sum = grid[row][col];
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        for(int i =0;i<4;i++){
            sum += dfs(row + dr[i], col + dc[i],rows,cols,visited,grid);
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,0));
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(grid[i][j]!=0 && !visited[i][j]){
                    long long sum = dfs(i,j,rows,cols,visited,grid);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};
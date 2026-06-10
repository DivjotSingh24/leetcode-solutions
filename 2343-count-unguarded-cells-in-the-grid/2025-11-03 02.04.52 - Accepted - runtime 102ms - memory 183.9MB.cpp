class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<unsigned char>> grid(m, vector<unsigned char>(n, 0));
        for (auto &w:walls)  grid[w[0]][w[1]]=1;
        for (auto &g:guards) grid[g[0]][g[1]]=2;
        vector<vector<unsigned char>> seen(m, vector<unsigned char>(n, 0));

        for (int i=0;i<m;++i) {
            bool active=false;
            for (int j=0;j<n;++j) {
                if (grid[i][j]==1) {        
                    active=false;
                } else if (grid[i][j]==2) {
                    active=true;
                } else if (active) {
                    seen[i][j]=1;
                }
            }
            active=false;
            for (int j=n-1;j>=0;--j) {
                if (grid[i][j]==1) {
                    active=false;
                } else if (grid[i][j]==2) {
                    active=true;
                } else if (active) {
                    seen[i][j]=1;
                }
            }
        }

        for (int j=0;j<n;++j) {
            bool active=false;
            for (int i=0;i<m;++i) {
                if (grid[i][j]==1) {
                    active=false;
                } else if (grid[i][j]==2) {
                    active=true;
                } else if (active) {
                    seen[i][j]=1;
                }
            }
            active=false;
            for (int i=m-1;i>=0;--i) {
                if (grid[i][j]==1) {
                    active=false;
                } else if (grid[i][j]==2) {
                    active=true;
                } else if (active) {
                    seen[i][j]=1;
                }
            }
        }

        int ans=0;
        for (int i=0;i<m;++i) {
            for (int j=0;j<n;++j) {
                if (grid[i][j]==0 && !seen[i][j]) ++ans;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> rowC(m,0);
        vector<int>colC(n,0);
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==1){
                    rowC[row]++;
                    colC[col]++;
                }
            }
        }
        int ans=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(mat[row][col]==1){
                    if(rowC[row]==1 && colC[col]==1)
                        ans++;
                }
            }
        }
        return ans;
    }
};
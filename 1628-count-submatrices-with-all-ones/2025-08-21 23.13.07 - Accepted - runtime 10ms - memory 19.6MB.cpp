class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // heights[i][j] will store the number of continuous ones in column j ending at row i
        vector<vector<int>> heights(m, vector<int>(n, 0));
        
        // Compute heights
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                if (mat[i][j] == 1) {
                    heights[i][j] = (i == 0) ? 1 : heights[i-1][j] + 1;
                } else {
                    heights[i][j] = 0;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (heights[i][j] > 0) {
                    int minHeight = heights[i][j];
                    for (int k = j; k >= 0 && heights[i][k] > 0; --k) {
                        minHeight = min(minHeight, heights[i][k]);
                        result += minHeight;
                    }
                }
            }
        }
        
        return result;
    }
};
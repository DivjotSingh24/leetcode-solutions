class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix;

        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int minal = dp[i+1][j];
                if(j > 0){
                    minal = min(dp[i+1][j-1], minal);
                }
                if(j < n-1){
                    minal = min(dp[i+1][j+1], minal);
                }
                dp[i][j] += minal;
                
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> sums;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int d=0; d<26; d++){
                    if(i-d<0 || j-d<0 || i+d>=m || j+d>=n) break;

                    int temp = 0;

                    if(d==0){
                        temp = grid[i][j];
                    }
                    else{
                        temp = grid[i-d][j] + grid[i+d][j] + grid[i][j-d] + grid[i][j+d];

                        for(int t=1;t<d;t++){
                            temp += grid[i+t][j+d-t];
                            temp += grid[i+t][j-d+t];
                            temp += grid[i-t][j+d-t];
                            temp += grid[i-t][j-d+t];
                        }
                    }

                    sums.insert(temp);
                }
            }
        }

        vector<int> ans(sums.begin(), sums.end());
        sort(ans.rbegin(), ans.rend());

        if(ans.size() > 3) ans.resize(3);
        return ans;
    }
};
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = 0;
        int col = grid[0].size()-1;
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        while(row<rows && col>=0){
            if(grid[row][col]<0){
                count+=(rows-row);
                col--;
            }
            else{
                row++;
            }
        }
        return count;
    }
};
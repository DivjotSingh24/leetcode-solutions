//brute force would be by creating an ans array of the same size and taking input as ans[j][n-1-i]
//optimal below
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //taking transpose
        for(int i=0;i<n-1;i++){
         for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
            }   
        }
        //reversing the rows
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
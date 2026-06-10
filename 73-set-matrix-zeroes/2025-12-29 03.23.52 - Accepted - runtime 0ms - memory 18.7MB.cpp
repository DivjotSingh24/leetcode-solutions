//BETTER SOLUTION USING EXTRA SPACE, SEE OPTIMAL BELOW
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int m=matrix.size(); //for rows
//         int n=matrix[0].size(); //for cols
//         int col[n]={0};
//         int row[m]={0};
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     row[i]=1;
//                     col[i]=1;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(row[i]||col[j]){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//         return matrix;
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //col[n]={0} -> matrix[0][..]
        //row[m]={0} -> matrix[..][0]
        int m=matrix.size(); //for rows
        int n=matrix[0].size(); //for cols
        int col0=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=0){
                    //check for col and row
                    if(matrix[0][j]==0 || matrix[i][0]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};


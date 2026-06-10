class NumMatrix {
public:
    vector<vector<int>> mat; 

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            mat.clear();
            return;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        mat = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                mat[i][j] = mat[i][j - 1] + matrix[i - 1][j - 1];
            }
        }

        for (int j = 1; j <= cols; ++j) {
            for (int i = 1; i <= rows; ++i) {
                mat[i][j] += mat[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (mat.empty()) return 0;
        return mat[row2 + 1][col2 + 1]
             - mat[row1    ][col2 + 1]
             - mat[row2 + 1][col1    ]
             + mat[row1    ][col1    ];
    }
};


/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
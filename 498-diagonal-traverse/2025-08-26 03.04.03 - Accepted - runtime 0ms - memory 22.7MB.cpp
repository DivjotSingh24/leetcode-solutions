class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> result;
        vector<int> diagonalElements;

        for (int diag = 0; diag < rows + columns - 1; ++diag) {
            int i = diag < columns ? 0 : diag - columns + 1;
            int j = diag < columns ? diag : columns - 1;
            while (i < rows && j >= 0) {
                diagonalElements.push_back(matrix[i++][j--]);
            }
            if (diag % 2 == 0) {
                reverse(diagonalElements.begin(), diagonalElements.end());
            }
            for (int value : diagonalElements) {
                result.push_back(value);
            }

            diagonalElements.clear();
        }

        return result;
    }
};

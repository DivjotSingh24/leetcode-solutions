class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.')); 
        backtrack(res, board, 0, n);
        return res;
    }

private:
    void backtrack(vector<vector<string>>& res, vector<string>& board, int col, int n) {
        if (col == n) {
            res.push_back(board); 
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q'; 
                backtrack(res, board, col + 1, n); 
                board[row][col] = '.'; 
            }
        }
    }

    bool isValid(vector<string>& board, int row, int col, int n) {
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};
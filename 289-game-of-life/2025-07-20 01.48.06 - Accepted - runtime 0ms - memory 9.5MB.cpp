class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();

        // Directions to all 8 neighbors
        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = 0;

                // Count live neighbors
                for (auto [dx, dy] : dirs) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                        liveNeighbors += board[ni][nj] & 1; // Get current state
                    }
                }

                // Apply the rules:
                if ((board[i][j] & 1) == 1) { // Currently alive
                    if (liveNeighbors == 2 || liveNeighbors == 3)
                        board[i][j] |= 2; // Mark as alive in next state
                } else { // Currently dead
                    if (liveNeighbors == 3)
                        board[i][j] |= 2; // Mark as alive in next state
                }
            }
        }

        // Final pass to update to next state
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1; // Update to next state
    }
};
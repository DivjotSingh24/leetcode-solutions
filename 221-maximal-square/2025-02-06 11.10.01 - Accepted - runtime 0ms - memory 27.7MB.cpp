#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        int maxSide = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
                    maxSide = max(maxSide, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;  // Move to the next row
        }

        return maxSide * maxSide;  // Return area of the largest square
    }
};

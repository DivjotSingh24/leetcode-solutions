#include <climits>

class Solution {
public:
    int getLeastFrequentDigit(int n) {
        if (n == 0) return 0;
        int count[10] = {0};
        for (int num = n; num > 0; num /= 10) {
            int d = num % 10;
            count[d] += 1;
        }

        int chosen = -1, best = INT_MAX;
        for (int d = 0; d < 10; ++d) {
            if (count[d] == 0) continue;
            if (count[d] < best) {
                best = count[d];
                chosen = d;
            }
        }
        return chosen;
    }
};

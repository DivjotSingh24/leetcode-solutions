class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) {
            return n - 1;
        }
        sort(restrictions.begin(), restrictions.end());
        int idx = 1, h = 0;
        for (int i = 0; i < restrictions.size(); i++) {
            int x = restrictions[i][0];
            int y = restrictions[i][1];
            restrictions[i][1] = min(y, x - idx + h);
            idx = x;
            h = restrictions[i][1];
        }
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]
            );
        }
        int res = n - restrictions.back()[0] + restrictions.back()[1];
        idx = 1;
        h = 0;
        for (auto& r : restrictions) {
            int x = r[0];
            int y = r[1];
            int steps = x - idx - abs(y - h);
            int higher = max(y, h);
            res = max(res, higher + steps / 2);
            idx = x;
            h = y;
        }
        return res;
    }
};
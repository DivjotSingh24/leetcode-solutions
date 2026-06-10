class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2,
                    int bx1, int by1, int bx2, int by2) {
        long long areaA = 1LL * (ax2 - ax1) * (ay2 - ay1);
        long long areaB = 1LL * (bx2 - bx1) * (by2 - by1);
        int overlapW = max(0, min(ax2, bx2) - max(ax1, bx1));
        int overlapH = max(0, min(ay2, by2) - max(ay1, by1));
        long long overlapArea = 1LL * overlapW * overlapH;
        long long total = areaA + areaB - overlapArea;
        return static_cast<int>(total);
    }
};
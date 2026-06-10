class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueNums;
        int n = digits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;

                    int a = digits[i], b = digits[j], c = digits[k];

                    if (a == 0) continue;      // skip leading zero
                    if (c % 2 != 0) continue;  // must be even

                    int num = a * 100 + b * 10 + c;
                    uniqueNums.insert(num);
                }
            }
        }

        return vector<int>(uniqueNums.begin(), uniqueNums.end());
    }
};
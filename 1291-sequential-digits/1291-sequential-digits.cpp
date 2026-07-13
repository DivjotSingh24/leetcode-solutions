class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for (int length = 2; length <= 9; length++) {
            for (int start = 1; start <= 10 - length; start++) {
                int num = 0;

                for (int digit = start; digit < start + length; digit++) {
                    num = num * 10 + digit;
                }

                if (low <= num && num <= high) {
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};
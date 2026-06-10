class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h <= 11; h++) {
            for (int m = 0; m <= 59; m++) {
                int totalBits = countBits(h) + countBits(m);

                if (totalBits == turnedOn) {
                    string time = to_string(h) + ":";

                    // minute must have 2 digits
                    if (m < 10) time += "0";
                    time += to_string(m);

                    ans.push_back(time);
                }
            }
        }
        return ans;
    }

    int countBits(int n) {
        int cnt = 0;
        while (n > 0) {
            cnt += (n & 1);   // check last bit
            n >>= 1;         // right shift
        }
        return cnt;
    }
};
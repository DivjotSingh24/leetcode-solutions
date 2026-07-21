class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int first = 0;
        int second = 0;
        int c1 = 0;
        int currfirst = 0;
        int currsecond = 0;
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                c1++;
                i++;

            } else {
                if (currfirst == 0) {
                    while (i < n && s[i] == '0') {
                        currfirst++;
                        i++;
                    }
                } else if (currsecond == 0) {
                    while (i < n && s[i] == '0') {
                        currsecond++;
                        i++;
                    }
                }
            }
            if (currfirst && currsecond &&
                currfirst + currsecond > first + second) {
                first = currfirst;
                second = currsecond;
            }
            if (currfirst && currsecond) {
                currfirst = currsecond;
                currsecond = 0;
            }
        }
        if (currfirst && currsecond &&
            currfirst + currsecond > first + second) {
            first = currfirst;
            second = currsecond;
        }
        return second != 0 ? first + c1 + second : c1;
    }
};
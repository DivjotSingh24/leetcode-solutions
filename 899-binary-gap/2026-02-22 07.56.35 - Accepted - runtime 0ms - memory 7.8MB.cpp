class Solution {
public:
    int binaryGap(int n) {
        int start = -1;
        int ans = 0;

        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                
                if (start != -1) {
                    ans = max(ans, i - start);
                }
                
                start = i; 
            }
        }
        return ans;
    }
};
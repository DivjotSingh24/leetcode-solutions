class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int prev2 = 1, prev1 = 2;  // Base cases for n=1, n=2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;  // Fibonacci relation
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;  // Answer for dp[n]
    }
};

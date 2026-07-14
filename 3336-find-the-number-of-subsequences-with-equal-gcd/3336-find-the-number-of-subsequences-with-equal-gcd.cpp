class Solution {
public:
    static const int MAXV = 200;
    const long long mod = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<long long>> dp(201, vector<long long>(201, 0));
        vector<vector<long long>> ndp(201, vector<long long>(201, 0));
        dp[0][0] = 1;
        vector<int> gtab(201);
        for (int x : nums) {
            for (auto& row : ndp) fill(row.begin(), row.end(), 0LL);
            for (int k = 0; k <= MAXV; k++) gtab[k] = __gcd(k, x);
            for (int i = 0; i <= MAXV; i++) {
                int g1 = gtab[i];
                for (int j = 0; j <= MAXV; j++) {
                    long long val = dp[i][j];
                    if (!val) continue;
                    int g2 = gtab[j];
                    ndp[i][j]  = (ndp[i][j]  + val) % mod; // skip x
                    ndp[g1][j] = (ndp[g1][j] + val) % mod; // x -> seq1
                    ndp[i][g2] = (ndp[i][g2] + val) % mod; // x -> seq2
                }
            }
            swap(dp, ndp);  // O(1): just swaps internal pointers of the outer vectors
        }
        long long ans = 0;
        for (int i = 1; i <= MAXV; i++) ans = (ans + dp[i][i]) % mod;
        return (int)ans;
    }
};
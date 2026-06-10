class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int bitPos = 0;
        int temp = n;
        while (temp > 0) {
            if (temp & 1) {
                powers.push_back(1 << bitPos);
            }
            bitPos++;
            temp >>= 1;
        }
        // Already in ascending order, no need to sort

        vector<int> exponents;
        for (int p : powers) {
            exponents.push_back(__builtin_ctz(p));
        }

        vector<int> prefix(exponents.size());
        prefix[0] = exponents[0];
        for (int i = 1; i < exponents.size(); i++)
            prefix[i] = prefix[i-1] + exponents[i];

        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            int sumExp = prefix[r] - (l > 0 ? prefix[l-1] : 0);
            ans.push_back((int)modPow(2, sumExp));
        }
        return ans;
    }
};

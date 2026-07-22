class Solution {
public:
    static constexpr int N = 100005;
    static constexpr int LOG = 20;
    int st[LOG][N];
    int lg[N];
    void build(vector<int>& a) {
        int n = a.size();
        lg[1] = 0;
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++)
            st[0][i] = a[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int j = lg[r - l + 1];
        return max(st[j][l], st[j][r - (1 << j) + 1]);
    }
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();
        int cnt1 = count(s.begin(), s.end(), '1');
        vector<int> zeros_block;
        vector<int> blockLeft;
        vector<int> blockRight;
        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i += 1;
            }
            if (s[st] == '0') {
                zeros_block.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }
        int m = zeros_block.size();
        if (m < 2) {
            return vector<int>(q, cnt1);
        }
        vector<int> consec2sum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            consec2sum[i] = zeros_block[i] + zeros_block[i + 1];
        }
        build(consec2sum);
        vector<int> ans(q);
        for (int k = 0; k < q; k++) {
            int l = queries[k][0];
            int r = queries[k][1];
            int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
                    blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
                    blockLeft.begin() - 1;

            if (i > m - 1 || j < 0 || i >= j) {
                ans[k] = cnt1;
                continue;
            }
            
            int firstLen = blockRight[i] - max(blockLeft[i], l) + 1;
            int secondLen = min(blockRight[j], r) - blockLeft[j] + 1;

            if (i + 1 == j) {
                ans[k] = cnt1 + firstLen + secondLen;
                continue;
            }

            int val1 = firstLen + zeros_block[i + 1];
            int val2 = zeros_block[j - 1] + secondLen;
            int val3 = 0;
            if (i + 1 <= j - 2)
                val3 = query(i + 1, j - 2);
    
            ans[k] = cnt1 + max({val1, val2, val3});
        }
        return ans;
    }
};
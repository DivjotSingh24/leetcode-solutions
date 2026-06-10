class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> idx;
        int cnt = 0;
        for (auto &s : original)
            if (!idx.count(s)) 
                idx[s] = cnt++;
        for (auto &s : changed)
            if (!idx.count(s)) 
                idx[s] = cnt++;

        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dist(cnt, vector<long long>(cnt, INF));

        for (int i = 0; i < cnt; i++) 
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++) {
            int u = idx[original[i]];
            int v = idx[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < cnt; k++)
            for (int i = 0; i < cnt; i++)
                if (dist[i][k] < INF)
                    for (int j = 0; j < cnt; j++)
                        if (dist[k][j] < INF)
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[n] = 0;
        unordered_set<int> lens;
        for (auto &s : original) 
            lens.insert(s.size());

        for (int i = n - 1; i >= 0; i--) {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            for (int L : lens) {
                if (i + L > n) 
                    continue;
                string s1 = source.substr(i, L);
                string s2 = target.substr(i, L);
                if (idx.count(s1) && idx.count(s2)) {
                    int u = idx[s1], v = idx[s2];
                    if (dist[u][v] < INF && dp[i + L] < INF)
                        dp[i] = min(dp[i], dist[u][v] + dp[i + L]);
                }
            }
        }
        return dp[0] == INF ? -1 : dp[0];
    }
};
class Solution {
public:
    using ll = long long;
    string s;
    pair<ll, ll> memo[20][11][11][2];
    bool vis[20][11][11][2];
    pair<ll, ll> solve(int pos, int pp, int p, bool tight, bool started) {
        int n = s.size();
        if (pos == n)
            return {1, 0};
        if (!tight && vis[pos][pp][p][started])
            return memo[pos][pp][p][started];
        int lim = tight ? s[pos] - '0' : 9;
        ll cnt = 0, sum = 0;
        for (int d = 0; d <= lim; d++) {
            bool nstarted = started || d > 0;
            int npp = 10, np = 10, add = 0;
            if (nstarted) {
                if (pp != 10 && p != 10 &&
                    ((p > pp && p > d) ||
                     (p < pp && p < d))) 
                    add = 1;
                npp = p;
                np = d; 
            } 
            bool new_tight = tight&&(d==lim);
            auto [c,sm] = solve(pos+1,npp,np,new_tight,nstarted);
            cnt+=c;
            sum += sm + (ll)add * c; 
        } 
        if (!tight) {
            vis[pos][pp][p][started] = true;
            memo[pos][pp][p][started] = {cnt, sum};
        }
        return { cnt, sum };
    } 
    ll find(ll num) {
        if (num < 0)
            return 0;
        s = to_string(num);
        memset(vis, 0, sizeof(vis));
        return solve(0, 10, 10, true, false).second;
    } 
    long long totalWaviness(long long num1, long long num2) {
        return find(num2) - find(num1 - 1);
    }
};
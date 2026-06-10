class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const noexcept {
            return (uint64_t)(uint32_t)p.first << 32 ^ (uint32_t)p.second;
        }
    };
    int longestBalanced(string s) {
        int n = (int)s.size();
        int ans = 1;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            ans = max(ans, j - i);
            i = j;
        }
        auto solve_two = [&](char x, char y, char z) -> int {
            unordered_map<pair<int,int>, int, PairHash> first;
            first.reserve(n * 2);
            first.max_load_factor(0.7f);

            int diff = 0;   
            int cntZ = 0;   
            first[{0,0}] = -1;

            int best = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == x) diff++;
                else if (s[i] == y) diff--;
                else cntZ++;

                pair<int,int> st = {diff, cntZ};
                auto it = first.find(st);
                if (it != first.end()) best = max(best, i - it->second);
                else first[st] = i;
            }
            return best;
        };
        ans = max(ans, solve_two('a','b','c'));
        ans = max(ans, solve_two('a','c','b'));
        ans = max(ans, solve_two('b','c','a'));
        unordered_map<pair<int,int>, int, PairHash> first3;
        first3.reserve(n * 2);
        first3.max_load_factor(0.7f);

        int a=0,b=0,c=0;
        first3[{0,0}] = -1; 

        for (int i = 0; i < n; i++) {
            if (s[i]=='a') a++;
            else if (s[i]=='b') b++;
            else c++;
            pair<int,int> st = {b-a, c-a};

            auto it = first3.find(st);
            if (it != first3.end()) {
                int len = i - it->second;
                ans = max(ans,len);
            } else {
                first3[st] = i;
            }
        }
        return ans;
    }
};
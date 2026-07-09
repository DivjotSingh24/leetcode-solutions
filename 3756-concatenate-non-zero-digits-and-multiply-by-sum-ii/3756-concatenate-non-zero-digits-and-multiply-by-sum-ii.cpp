class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int>ans;
        const long long MOD = 1e9 + 7;
        vector<int>prefix(s.size()+1,0);
        string s2;
        
        vector<int>notZeroCnt(s.size()+1,0);
        for(int i = 0;i<s.size();i++){
            prefix[i+1] = prefix[i] + s[i] - '0';

            notZeroCnt[i+1] = notZeroCnt[i] + (s[i] != '0');

            if(s[i] == '0') continue;
            s2.push_back(s[i]);
        }

        vector<long long> prefNum(s2.size() + 1, 0);
        vector<long long> pow10(s2.size() + 1, 1);

        for (int i = 0; i < s2.size(); i++) {
            prefNum[i + 1] = (prefNum[i] *10 + (s2[i] - '0'))% MOD;
            pow10[i + 1] = (pow10[i] *10)% MOD;
        }

        for(int i = 0;i<queries.size();i++){
            int l = queries[i][0];
            int r = queries[i][1];
            
            int L = notZeroCnt[l];
            int R = notZeroCnt[r+1]-1;

            int sum = prefix[r+1]-prefix[l];

            if (L > R) {
                ans.push_back(0);
                continue;
            }
            int len = R - L + 1;
            long long num =(prefNum[R + 1] - prefNum[L] * pow10[len] % MOD + MOD) % MOD;

            ans.push_back(num *sum % MOD);
        }
        return ans;
    }
};
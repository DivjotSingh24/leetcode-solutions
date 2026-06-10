#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prevSorted;
        bool havePrev = false;
        for (auto &w : words) {
            string s = w;
            sort(s.begin(), s.end());
            if (!havePrev || s != prevSorted) {
                res.push_back(w);
                prevSorted = s;
                havePrev = true;
            }
        }
        return res;
    }
};

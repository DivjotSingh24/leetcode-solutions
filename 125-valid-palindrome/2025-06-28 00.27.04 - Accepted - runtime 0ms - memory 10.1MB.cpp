class Solution {
public:
    bool f(string& s, int i, int n) {
        if (i >= n / 2) return true;
        if (s[i] != s[n - i - 1]) return false;
        return f(s, i + 1, n);
    }

    bool isPalindrome(string s) {
        string t;
        for (char c : s)
            if (isalnum(c)) t += tolower(c);
        return f(t, 0, t.size());
    }
};

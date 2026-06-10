class Solution {
public:
    bool isPalindromic(string& rep){
        int i = 0, j = (int)rep.size() - 1;
        while(i < j){
            if(rep[i] != rep[j]) return false;
            ++i; --j;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int b = 2; b <= n - 2; ++b){
            string rep;
            int nn = n;
            while(nn){
                int d = nn % b;
                rep.push_back(d < 10 ? char('0' + d) : char('a' + (d - 10)));
                nn /= b;
            }
            if(!isPalindromic(rep)) return false;
        }
        return true;
    }
};

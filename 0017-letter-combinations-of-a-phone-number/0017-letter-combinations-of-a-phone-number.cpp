class Solution {
public:

    void solve(int index, string &digits, vector<string>& ans, string &ds, vector<string>& mp)
    {
        if(index == digits.size())
        {
            ans.push_back(ds);
            return;
        }
        string letters = mp[digits[index]-'0'];
        for(char ch : letters)
        {
            ds.push_back(ch);
            solve(index+1, digits, ans, ds, mp);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty())
            return ans;
        vector<string> mp(10);
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string ds="";
        solve(0, digits, ans, ds, mp);
        return ans;
    }
};
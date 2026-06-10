class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> result;
        vector<string> phoneMap = {
            //assigning alphabets
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string current;
        backtrack(digits, phoneMap, 0, current, result);
        return result;
    }
private:
    void backtrack(const string& digits, const vector<string>& phoneMap, int index, string& current, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        string letters = phoneMap[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);
            backtrack(digits, phoneMap, index + 1, current, result);
            current.pop_back();
        }
    }
};
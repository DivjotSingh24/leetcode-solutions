class Solution {
public:
    static bool compare(string &a, string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        
        // Convert all numbers to strings
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Sort using the custom comparator
        sort(strNums.begin(), strNums.end(), compare);
        
        // Edge case: if the largest number is "0", the whole number is "0"
        if (strNums[0] == "0") return "0";
        
        // Build the result string
        string result;
        for (string &s : strNums) {
            result += s;
        }
        
        return result;
    }
};

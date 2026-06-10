class Solution {
public:
    bool checkString(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<s.size() && s[i]=='a') i++;
        while(j>=0 && s[j]=='b') j--;
        return i>j;
    }
};
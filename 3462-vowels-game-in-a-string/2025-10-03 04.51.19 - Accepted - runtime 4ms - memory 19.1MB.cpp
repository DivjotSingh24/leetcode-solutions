class Solution {
public:
    bool doesAliceWin(string s) {
        int num = 0;
        for(char c:s) {
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') num++;
        }
        if(num % 2 == 1) return true;
        else if(s.size() > num && num != 0) return true;
        else if(s.size() == num) return true;
        else return false;
    }
};
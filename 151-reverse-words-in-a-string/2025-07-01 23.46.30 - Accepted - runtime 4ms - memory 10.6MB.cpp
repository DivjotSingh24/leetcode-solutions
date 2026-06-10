class Solution {
public:
    string reverseWords(string s) {
        stack <string> stk;
        int i=0;
        int n=s.length();
        while (i<n){
            while(i<n && s[i]==' ')i++;
            string word="";
            while (i<n && s[i]!=' '){

                word+=s[i];
                i++;
            }
            if (!word.empty()){
                stk.push(word);
            }
        }
        string result="";
        while (!stk.empty()){
            result+=stk.top();
            stk.pop();
            if (!stk.empty()) result+=" ";
        }
        return result;
    }
};
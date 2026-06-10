class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        int breaks = 0;
        int i =0;
        while(i < (int)text.size()){
            unordered_set<char> freq1;
            for(;i<text.size();i++){
                if(text[i] == ' '){
                    breaks++;
                    break;
                }
                freq1.insert(text[i]);
            }
            bool bad = false;
            for(char c: brokenLetters){
                if(freq1.count(c)){
                    bad=true;
                    break;
                }
            }
            if(!bad){
                ans++;
            }
            if(i < (int)text.size() && text[i] == ' ') i++;
        }
        return ans;
    }
};
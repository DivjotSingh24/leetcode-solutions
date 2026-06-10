class Solution {
public:
    int maxFreqSum(string s) {
        map<int, int> freq;
        for(int i =0;i<s.size();i++){
            freq[s[i]]++;
        }
        int max_vowel = 0;
        int max_cons = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                if(freq[s[i]] > max_vowel){
                    max_vowel = freq[s[i]];
                    continue;
                }
            }else{
                if(freq[s[i]] > max_cons){
                    max_cons = freq[s[i]];
                    continue;
                }
            }
        }
        return (max_vowel + max_cons);
    }
};